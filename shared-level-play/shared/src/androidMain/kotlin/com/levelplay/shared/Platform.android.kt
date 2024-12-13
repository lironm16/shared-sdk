package com.levelplay.shared

import android.os.Build

class AndroidPlatform : com.levelplay.shared.Platform {
    override val platform: String = "Android ${Build.VERSION.SDK_INT}"
}

actual fun getPlatform(): com.levelplay.shared.Platform = AndroidPlatform()