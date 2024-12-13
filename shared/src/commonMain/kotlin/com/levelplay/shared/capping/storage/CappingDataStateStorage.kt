package com.levelplay.shared.capping.storage

interface ShowCountCappingStorage {
  fun getCurrentNumberOfShows(identifier: String): Int?
  fun getTimeThreshold(identifier: String): Long?

  fun setCurrentNumberOfShows(count : Int, identifier: String)
  fun setTimeThreshold(time : Long, identifier: String)
}

interface PacingCappingStorage {
  fun getLastShowTime(identifier: String): Long?
  fun setLastShowTime(time : Long, identifier: String)
}