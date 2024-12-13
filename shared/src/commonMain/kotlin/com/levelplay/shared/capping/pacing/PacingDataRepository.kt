package com.levelplay.shared.capping.pacing

import co.touchlab.stately.collections.IsoMutableMap
import com.levelplay.shared.DataStorage
import com.levelplay.shared.capping.Identifier

typealias ShowTime = Long

class PacingDataRepository(private val storage: DataStorage) : IPacingDataRepository {

  private object Keys {
    fun lastShowTimeKey(identifier: String): String {
      return "${identifier}_pacing_lastShowTime"
    }
  }

  private val lastShowTimeCache = IsoMutableMap<Identifier, ShowTime>()

  override fun getLastShowTime(identifier: String): Long? {
    val key = Keys.lastShowTimeKey(identifier)
    // Check cache first
    return lastShowTimeCache[key] ?: storage.getString(key)?.toLongOrNull()?.also {
      // Populate cache if value is found in storage
      lastShowTimeCache[key] = it
    }
  }

  override fun setLastShowTime(time: Long, identifier: String) {
    val key = Keys.lastShowTimeKey(identifier)
    // Update cache and storage
    lastShowTimeCache[key] = time
    storage.set(time.toString(), key)
  }
}
