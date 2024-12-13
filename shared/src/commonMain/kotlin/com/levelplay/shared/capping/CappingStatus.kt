package com.levelplay.shared.capping

import com.levelplay.shared.capping.config.CappingType

/** Represents the capping status */
data class CappingStatus(val isCapped: Boolean, val type: CappingType? = null) {

  /** Provides a reason for the capping status. */
  fun reason(): String? =
      when (type) {
        CappingType.Delivery -> "Placement delivery is false"
        CappingType.Pacing -> "In pacing mode"
        CappingType.ShowCount -> "Max ad cap reached"
        else -> null
      }

  /**
   * Provides a string representation of the capping status for debugging purposes.
   *
   * @return A string detailing the capping status.
   */
  override fun toString(): String = "CappingStatus(isCapped=$isCapped reason=$type)"
}
