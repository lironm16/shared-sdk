package com.levelplay.shared.capping.pacing

import com.levelplay.shared.CurrentTimeProvider
import com.levelplay.shared.capping.CappingStatus
import com.levelplay.shared.capping.ICappingService
import com.levelplay.shared.capping.Identifier
import com.levelplay.shared.capping.config.CappingType
import com.levelplay.shared.capping.config.ICappingConfigProvider

class PacingCappingHandler(
    private val currentTimeProvider: CurrentTimeProvider,
    private val repository: IPacingDataRepository
) : ICappingService, ICappingService.Editor {
  val configs = mutableMapOf<String, PacingCappingConfig>()

  private fun isCapped(config: PacingCappingConfig, identifier: String): Boolean {
    val lastShowTime = repository.getLastShowTime(identifier)
    lastShowTime ?: return false

    val currentTime = currentTimeProvider.nowInMilliseconds()
    // Check if the ad is within the pacing time threshold since the last show time
    return (currentTime - lastShowTime) < config.timeInterval()
  }

  override fun cappingStatus(identifier: Identifier): CappingStatus {
    val config = configs[identifier] ?: return CappingStatus(isCapped = false)
    if (isCapped(config, identifier)) {
      return CappingStatus(isCapped = true, type = CappingType.Pacing)
    }
    return CappingStatus(isCapped = false)
  }

  override fun addConfig(
      identifier: Identifier,
      cappingType: CappingType,
      cappingConfig: ICappingConfigProvider
  ): Result<Unit> {
    cappingConfig
        .createPacingValidatedConfig()
        .onSuccess { config ->
          config?.let { configs[identifier] = config }
          return Result.success(Unit)
        }
        .onFailure {
          return Result.failure(it)
        }
    return Result.success(Unit)
  }

  override fun updateCappingOnShow(identifier: Identifier) {
    configs[identifier] ?: return
    repository.setLastShowTime(currentTimeProvider.nowInMilliseconds(), identifier)
  }
}
