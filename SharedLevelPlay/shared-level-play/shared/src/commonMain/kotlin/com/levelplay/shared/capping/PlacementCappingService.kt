package com.levelplay.shared.capping

import com.levelplay.shared.AdFormat
import com.levelplay.shared.capping.config.CappingType
import com.levelplay.shared.capping.config.ICappingConfigProvider
import com.levelplay.shared.capping.delivery.DeliveryHandler
import com.levelplay.shared.capping.placement.PlacementIdentifierliron
import kotlin.jvm.Synchronized

class PlacementCappingService(
    private val cappingService: CappingService,
    private val deliveryHandler: DeliveryHandler = DeliveryHandler()
) : com.levelplay.shared.capping.IPlacementCappingService, com.levelplay.shared.capping.IPlacementCappingService.Editor {

  @Synchronized
  override fun cappingStatus(
      placementName: com.levelplay.shared.capping.PlacementName,
      adFormat: AdFormat
  ): CappingStatus =
      com.levelplay.shared.capping.placement.PlacementIdentifierliron(
          placementName = placementName,
          adFormat = adFormat
      ).value().let {
        val cappingStatus = deliveryHandler.cappingStatus(it)
        if (cappingStatus.isCapped) {
          return cappingStatus
        }
        return cappingService.cappingStatus(it)
      }

  @Synchronized
  override fun addConfig(
      placementName: com.levelplay.shared.capping.PlacementName,
      adFormat: AdFormat,
      cappingType: CappingType,
      cappingConfig: ICappingConfigProvider
  ): Result<Unit> =
      com.levelplay.shared.capping.placement.PlacementIdentifierliron(
          placementName = placementName,
          adFormat = adFormat
      ).value().let {
        when (cappingType) {
          CappingType.Delivery -> deliveryHandler.addConfig(it, cappingType, cappingConfig)
          CappingType.Pacing,
          CappingType.ShowCount -> cappingService.addConfig(it, cappingType, cappingConfig)
        }
      }

  @Synchronized
  override fun updateCappingOnShow(placementName: com.levelplay.shared.capping.PlacementName, adFormat: AdFormat) =
      com.levelplay.shared.capping.placement.PlacementIdentifierliron(
          placementName = placementName,
          adFormat = adFormat
      ).value().let {
        val cappingStatus = deliveryHandler.cappingStatus(it)
        if (!cappingStatus.isCapped) {
          cappingService.updateCappingOnShow(it)
        }
      }
}
