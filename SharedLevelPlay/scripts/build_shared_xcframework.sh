#!/bin/bash

# Dynamically calculate WORKSPACE_PATH based on the script location
SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
WORKSPACE_PATH=$(cd "$SCRIPT_DIR/../../" && pwd)

# Variables
FRAMEWORK_NAME="shared.xcframework"
GRADLE_TASK=":shared:linkDebugFramework" # Task for building individual slices
GRADLE_XCFRAMEWORK_TASK=":shared:assembleSharedDebugXCFramework" # Task for building the entire XCFramework
GRADLE_PATH="$WORKSPACE_PATH/SharedLevelPlay/shared-level-play/gradlew"
GRADLE_PROJECT_PATH="$WORKSPACE_PATH/SharedLevelPlay/shared-level-play"
BUILD_FOLDER="$WORKSPACE_PATH/SharedLevelPlay/build"
XCFRAMEWORK_OUTPUT="$BUILD_FOLDER/$FRAMEWORK_NAME"
COMMON_MAIN_PATH="$GRADLE_PROJECT_PATH/shared/src/commonMain"
IOS_MAIN_PATH="$GRADLE_PROJECT_PATH/shared/src/iosMain"
GRADLE_XCFRAMEWORK_PATH="$GRADLE_PROJECT_PATH/shared/build/XCFrameworks/debug/$FRAMEWORK_NAME"

# Constants
SLICE_IOS_ARM64="ios-arm64"
SLICE_IOS_SIMULATOR_ARM64_X64="ios-arm64_x86_64-simulator"

# Ensure the build folder exists
mkdir -p "$BUILD_FOLDER"

echo "RUN_DESTINATION_DEVICE_PLATFORM_NAME: $RUN_DESTINATION_DEVICE_PLATFORM_NAME"

IOS_TARGET=""
if [[ "$RUN_DESTINATION_DEVICE_PLATFORM_NAME" == "iphoneos" ]]; then
    IOS_TARGET="iosArm64"
elif [[ "$RUN_DESTINATION_DEVICE_PLATFORM_NAME" == "iphonesimulator" ]]; then
    IOS_TARGET="iosSimulatorArm64" # Treat both architectures as one slice
fi

# Fallback: If no target detected, build the entire XCFramework
if [ -z "$IOS_TARGET" ]; then
    echo "No specific target detected. Using Gradle to rebuild the entire XCFramework..."

    # Run the Gradle task to build the XCFramework
    cd "$GRADLE_PROJECT_PATH" || exit 1
    "$GRADLE_PATH" $GRADLE_XCFRAMEWORK_TASK
    if [ $? -ne 0 ]; then
        echo "Gradle XCFramework build failed. Aborting."
        exit 1
    fi

    # Copy the XCFramework to the desired build folder
    if [ -d "$GRADLE_XCFRAMEWORK_PATH" ]; then
        echo "Copying XCFramework to build folder..."
        rm -rf "$XCFRAMEWORK_OUTPUT" # Clean up the existing XCFramework
        cp -R "$GRADLE_XCFRAMEWORK_PATH" "$XCFRAMEWORK_OUTPUT"
        echo "XCFramework successfully copied to: $XCFRAMEWORK_OUTPUT"
    else
        echo "Error: XCFramework not found at $GRADLE_XCFRAMEWORK_PATH. Aborting."
        exit 1
    fi
    exit 0
fi

# Function to rebuild the framework for a specific target
build_framework() {
    local target="$1"

    # Ensure the target is not empty
    if [ -z "$target" ]; then
        echo "Error: Target is empty. Cannot proceed with the build."
        exit 1
    fi

    echo "Building framework for target: $target..."
    cd "$GRADLE_PROJECT_PATH" || exit 1 # Navigate to the project directory
    "$GRADLE_PATH" $GRADLE_TASK"$target" # Build the framework slice
    if [ $? -ne 0 ]; then
        echo "Gradle build failed for target: $target. Aborting."
        exit 1
    fi

    # Locate the generated framework
    local build_path="$GRADLE_PROJECT_PATH/shared/build/bin/$target/debugFramework/shared.framework"
    if [ ! -d "$build_path" ]; then
        echo "Error: Framework not found at $build_path. Aborting."
        exit 1
    fi

    # Determine the target directory in the XCFramework
    local slice_path=""
    case "$target" in
        iosArm64)
            slice_path="$BUILD_FOLDER/$FRAMEWORK_NAME/$SLICE_IOS_ARM64"
            ;;
        iosSimulatorArm64|iosX64)
            slice_path="$BUILD_FOLDER/$FRAMEWORK_NAME/$SLICE_IOS_SIMULATOR_ARM64_X64"
            ;;
        *)
            echo "Error: Unknown target $target"
            exit 1
            ;;
    esac

    echo "Copying framework for target: $target to slice path: $slice_path..."
    rm -rf "$slice_path" # Clean previous slice
    mkdir -p "$slice_path" # Ensure the slice directory exists
    cp -R "$build_path" "$slice_path"

    echo "Framework for target $target successfully built and copied to: $slice_path"
}

# Function to check if the rebuild is needed for a specific target
needs_rebuild() {
    local target="$1"
    local slice_path=""
    case "$target" in
        iosArm64)
            slice_path="$BUILD_FOLDER/$FRAMEWORK_NAME/$SLICE_IOS_ARM64"
            ;;
        iosSimulatorArm64|iosX64)
            slice_path="$BUILD_FOLDER/$FRAMEWORK_NAME/$SLICE_IOS_SIMULATOR_ARM64_X64"
            ;;
        *)
            echo "Error: Unknown target $target"
            return 0
            ;;
    esac

    if [ ! -d "$slice_path" ]; then
        echo "Slice missing: $slice_path. Rebuild needed."
        return 0
    fi

    # Check if source files have been modified since the slice was built
    LATEST_SRC_MOD=$(find "$COMMON_MAIN_PATH" "$IOS_MAIN_PATH" -type f -name "*.kt" -print0 | xargs -0 stat -f "%m" 2>/dev/null | sort -n | tail -1)
    SLICE_MOD=$(stat -f "%m" "$slice_path" 2>/dev/null || echo 0)

    if [ "$LATEST_SRC_MOD" -gt "$SLICE_MOD" ]; then
        echo "Source files modified since the last build for slice: $target. Rebuild needed."
        return 0
    fi

    echo "Slice $target is up-to-date."
    return 1
}

# Main logic
if [ -z "$IOS_TARGET" ]; then
    echo "No specific target detected. Building entire XCFramework..."
    cd "$GRADLE_PROJECT_PATH" || exit 1
    "$GRADLE_PATH" $GRADLE_XCFRAMEWORK_TASK
    if [ $? -ne 0 ]; then
        echo "Gradle build for XCFramework failed. Aborting."
        exit 1
    fi

    # Copy the XCFramework to the build folder
    if [ -d "$GRADLE_XCFRAMEWORK_PATH" ]; then
        echo "Copying XCFramework to build folder..."
        rm -rf "$XCFRAMEWORK_OUTPUT"
        cp -R "$GRADLE_XCFRAMEWORK_PATH" "$XCFRAMEWORK_OUTPUT"
        echo "XCFramework successfully rebuilt and copied to: $XCFRAMEWORK_OUTPUT"
    else
        echo "Error: XCFramework not found at $GRADLE_XCFRAMEWORK_PATH. Aborting."
        exit 1
    fi
else
    # Target specified: build only the required framework
    if needs_rebuild "$IOS_TARGET"; then
        build_framework "$IOS_TARGET"
    else
        echo "No rebuild needed for target: $IOS_TARGET"
    fi
fi
