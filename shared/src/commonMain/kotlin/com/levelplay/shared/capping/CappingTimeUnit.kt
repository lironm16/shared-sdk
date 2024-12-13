package com.levelplay.shared.capping

enum class CappingTimeUnit(private val unit: String, private val millis: Long) {
  Day(unit = "d", millis = 86400000L),
  Hour(unit = "h", millis = 3600000L),
  Second(unit = "s", millis = 1000L);

  companion object {
    fun fromString(value: String?): CappingTimeUnit? {
      return CappingTimeUnit.values().firstOrNull() { it.unit == value }
    }
  }

  fun inMilliseconds(duration: Int? = 1): Long = (duration ?: 1) * this.millis
}
