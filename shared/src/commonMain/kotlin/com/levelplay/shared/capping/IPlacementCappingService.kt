package com.levelplay.shared.capping

import com.levelplay.shared.AdFormat
import com.levelplay.shared.capping.config.CappingType
import com.levelplay.shared.capping.config.ICappingConfigProvider

typealias PlacementName = String

interface IPlacementCappingService {
    /**
     * Request cappingStatus for identifier
     *
     * @param placementName the identifier to check if it is capped.
     * @return CappingStatus
     */
    fun cappingStatus(placementName: com.levelplay.shared.capping.PlacementName, adFormat: AdFormat): com.levelplay.shared.capping.CappingStatus

  /** Editor to update service data. */
  interface Editor {
    fun addConfig(
        placementName: com.levelplay.shared.capping.PlacementName,
        adFormat: AdFormat,
        cappingType: CappingType,
        cappingConfig: ICappingConfigProvider
    ): Result<Unit>

    fun updateCappingOnShow(placementName: com.levelplay.shared.capping.PlacementName, adFormat: AdFormat)
  }
}
