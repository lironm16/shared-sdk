package com.levelplay.shared.capping.showcount

interface IShowCountDataRepository {
    fun getCurrentNumberOfShows(identifier: String): Int

    fun getTimeThreshold(identifier: String): Long?

    fun setCurrentNumberOfShows(count: Int, identifier: String)

    fun setTimeThreshold(threshold: Long, identifier: String)
}