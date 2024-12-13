package com.levelplay.shared

/**
 * Interface for getting the current time in milliseconds. This is useful for testing time-dependent
 * code.
 */
interface CurrentTimeProvider {
    fun nowInMilliseconds(): Long
}