package com.levelplay.shared.capping.config

import com.levelplay.shared.capping.CappingTimeUnit
import com.levelplay.shared.capping.delivery.DeliveryCappingConfig
import com.levelplay.shared.capping.pacing.PacingCappingConfig
import com.levelplay.shared.capping.showcount.ShowCountCappingConfig

class CappingConfigProvider(
    val enabled: Boolean?,
    val limit: Int? = null,
    val unit: CappingTimeUnit? = null,
) : com.levelplay.shared.capping.config.ICappingConfigProvider {

  private fun validateConfigForType(unit: CappingTimeUnit?): Result<Boolean> {
    return com.levelplay.shared.capping.config.CappingConfigValidator(enabled, limit, unit).validateConfig()
  }

  override fun createShowCountValidatedConfig(): Result<ShowCountCappingConfig?> {
    validateConfigForType(unit).onFailure { exception ->
      return Result.failure(exception)
    }
    val showCountCappingConfig =
        if (enabled == true) {
          limit?.let { limitValue ->
            unit?.let { unitValue -> ShowCountCappingConfig(limitValue, unitValue) }
          }
        } else null
    return Result.success(showCountCappingConfig)
  }

  override fun createPacingValidatedConfig(): Result<PacingCappingConfig?> {
    validateConfigForType(CappingTimeUnit.Second).onFailure { exception ->
      return Result.failure(exception)
    }
    val pacingCappingConfig =
        if (enabled == true) {
          limit?.let { _ -> PacingCappingConfig(CappingTimeUnit.Second.inMilliseconds(limit)) }
        } else null
    return Result.success(pacingCappingConfig)
  }

  override fun createDeliveryValidatedConfig(): Result<DeliveryCappingConfig?> {
    com.levelplay.shared.capping.config.DeliveryConfigValidator(enabled)
        .validateConfig().onFailure { exception ->
      return Result.failure(exception)
    }

    return Result.success(enabled?.let { DeliveryCappingConfig(enabled) })
  }
}
