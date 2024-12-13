package com.levelplay.shared.capping.showcount

import co.touchlab.stately.collections.IsoMutableMap
import com.levelplay.shared.DataStorage
import com.levelplay.shared.capping.Identifier

typealias ShowCount = Int
typealias TimeThreshold = Long

internal class ShowCountDataRepository(private val storage: DataStorage) :
  IShowCountDataRepository {

  private object Keys {
    fun currentNumberOfShowsKey(identifier: String): String {
      return "${identifier}_showCount_currentNumberOfShows"
    }

    fun timeThresholdKey(identifier: String): String {
      return "${identifier}_showCount_timeThreshold"
    }
  }

  private val showCountCache = IsoMutableMap<Identifier, ShowCount>()
  private val timeThresholdCache = IsoMutableMap<Identifier, TimeThreshold>()

  override fun setCurrentNumberOfShows(count: Int, identifier: String) {
    showCountCache[identifier] = count
    storage.set(count, Keys.currentNumberOfShowsKey(identifier))
  }

  override fun getCurrentNumberOfShows(identifier: String): ShowCount {
    return showCountCache[identifier] ?: run {
      (storage.getObject(Keys.currentNumberOfShowsKey(identifier)) as? Int)?.let {
        showCountCache[identifier] = it
        return it
      }
      // Default to 0 if not found
      showCountCache[identifier] = 0
      0
    }
  }

  override fun getTimeThreshold(identifier: String): Long? {
    return timeThresholdCache[identifier] ?: run {
      (storage.getObject(Keys.timeThresholdKey(identifier)) as? Long)?.let {
        timeThresholdCache[identifier] = it
        return it
      }
      null
    }
  }

  override fun setTimeThreshold(threshold: Long, identifier: String) {
    timeThresholdCache[identifier] = threshold
    storage.set(threshold, Keys.timeThresholdKey(identifier))
  }
}
