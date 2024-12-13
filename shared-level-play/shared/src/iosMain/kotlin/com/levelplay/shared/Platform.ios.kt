package com.levelplay.shared

import platform.UIKit.UIDevice

class IOSPlatform: com.levelplay.shared.Platform {
    override val platform: String = UIDevice.currentDevice.systemName() + " " + UIDevice.currentDevice.systemVersion
}

actual fun getPlatform(): com.levelplay.shared.Platform = IOSPlatform()