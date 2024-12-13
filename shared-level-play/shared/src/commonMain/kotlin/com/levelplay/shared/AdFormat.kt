package com.levelplay.shared

enum class AdFormat(val value: String) {
    BANNER("banner"),
    INTERSTITIAL("interstitial"),
    REWARDED("rewarded"),
    NATIVE_AD("nativeAd");

    companion object {
        fun fromValue(value: String): AdFormat? {
            return values().firstOrNull { it.value == value }
        }
    }
}