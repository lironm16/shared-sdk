package com.levelplay.shared

interface Platform {
    val platform: String
}

expect fun getPlatform(): com.levelplay.shared.Platform