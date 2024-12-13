import org.jetbrains.kotlin.gradle.ExperimentalKotlinGradlePluginApi
import org.jetbrains.kotlin.gradle.dsl.JvmTarget
import org.jetbrains.kotlin.gradle.plugin.mpp.apple.XCFramework

plugins {
    alias(libs.plugins.kotlinMultiplatform)
    alias(libs.plugins.androidLibrary)
}

kotlin {
    androidTarget {
        @OptIn(ExperimentalKotlinGradlePluginApi::class)
        compilerOptions {
            jvmTarget.set(JvmTarget.JVM_11)
        }
    }

    val xcf = XCFramework()

    // Get the iOS target to build from the Gradle property, default to all if not specified
    val iosTargetProperty = project.findProperty("iOSTarget") as? String
    val selectedIosTargets = when (iosTargetProperty) {
        "iosX64", "iosSimulatorArm64" -> listOf(iosX64(), iosSimulatorArm64())
        "iosArm64" -> listOf(iosArm64())
        else -> listOf(iosX64(), iosArm64(), iosSimulatorArm64()) // Build all if no target specified
    }

    selectedIosTargets.forEach {
        it.binaries.framework {
            baseName = "shared"
            isStatic = true
            xcf.add(this)
        }
    }

    sourceSets {

        commonMain {
            kotlin.srcDirs("shared/commonMain/kotlin")
            dependencies {
                implementation("co.touchlab:stately-common:2.0.5")
                implementation("co.touchlab:stately-iso-collections:2.0.5")
            }
        }

        commonTest {
            dependencies {
                implementation(kotlin("test"))
            }
        }

        val androidUnitTest by getting {
            dependencies {
                implementation(libs.junit)
            }
        }
    }
}

android {
    namespace = "com.jetbrains.basicsample.shared"
    compileSdk = libs.versions.android.compileSdk.get().toInt()
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_11
        targetCompatibility = JavaVersion.VERSION_11
    }
    defaultConfig {
        minSdk = libs.versions.android.minSdk.get().toInt()
    }
}