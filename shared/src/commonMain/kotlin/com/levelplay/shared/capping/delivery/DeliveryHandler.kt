package com.levelplay.shared.capping.delivery

import com.levelplay.shared.capping.CappingStatus
import com.levelplay.shared.capping.ICappingService
import com.levelplay.shared.capping.Identifier
import com.levelplay.shared.capping.config.CappingType
import com.levelplay.shared.capping.config.ICappingConfigProvider
import co.touchlab.stately.collections.IsoMutableMap

class DeliveryHandler : ICappingService, ICappingService.Editor {
    private val deliveryConfigs = IsoMutableMap<String, DeliveryCappingConfig>()

  override fun cappingStatus(
      identifier: Identifier,
  ): CappingStatus {
    deliveryConfigs[identifier]?.let {
      if (!it.enabled) {
        return CappingStatus(isCapped = true, type = CappingType.Delivery)
      }
    }
    return CappingStatus(isCapped = false)
  }

  override fun addConfig(
      identifier: Identifier,
      cappingType: CappingType,
      cappingConfig: ICappingConfigProvider,
  ): Result<Unit> {
    cappingConfig
        .createDeliveryValidatedConfig()
        .onSuccess { deliveryConfig ->
          deliveryConfig?.let { deliveryConfigs[identifier] = it }
          return Result.success(Unit)
        }
        .onFailure {
          return Result.failure(it)
        }
    return Result.success(Unit)
  }

  override fun updateCappingOnShow(identifier: Identifier) = Unit
}
