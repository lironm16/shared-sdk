package com.levelplay.shared.capping.pacing

import com.levelplay.shared.capping.CappingTimeUnit

class PacingCappingConfig(
    private val timeInterval: Long,
    private val unit: CappingTimeUnit = CappingTimeUnit.Second
) {

  fun timeInterval(): Long = timeInterval

  fun unit(): CappingTimeUnit = unit

  override fun toString(): String = "PacingCappingConfig(timeInterval=$timeInterval unit=$unit)"
}
