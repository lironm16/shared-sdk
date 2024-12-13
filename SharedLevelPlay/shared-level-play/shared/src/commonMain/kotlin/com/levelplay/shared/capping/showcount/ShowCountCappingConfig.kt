package com.levelplay.shared.capping.showcount

import com.levelplay.shared.capping.CappingTimeUnit

class ShowCountCappingConfig(private val maxImpressions: Int, private val unit: CappingTimeUnit) {
  fun maxImpressions(): Int = maxImpressions

  fun unit(): CappingTimeUnit = unit

  override fun toString(): String =
      "ShowCountCappingConfig(maxImpressions=$maxImpressions, unit=$unit)"
}
