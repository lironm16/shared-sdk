package com.levelplay.shared.capping.pacing

interface IPacingDataRepository {
    fun getLastShowTime(identifier: String): Long?

    fun setLastShowTime(time: Long, identifier: String)
}
