package com.levelplay.shared.capping.showcount

import com.levelplay.shared.CurrentTimeProvider
import com.levelplay.shared.capping.CappingStatus
import com.levelplay.shared.capping.ICappingService
import com.levelplay.shared.capping.Identifier
import com.levelplay.shared.capping.config.CappingType
import com.levelplay.shared.capping.config.ICappingConfigProvider

class ShowCountHandler(
    private val currentTimeProvider: CurrentTimeProvider,
    private val serviceDataRepository: IShowCountDataRepository
) : ICappingService, ICappingService.Editor {
  val configs = mutableMapOf<String, ShowCountCappingConfig>()

  private fun getCappingInfo(identifier: String): ShowCountCappingInfo {
    val currentTime = currentTimeProvider.nowInMilliseconds()
    val currentNumberOfShows = serviceDataRepository.getCurrentNumberOfShows(identifier)
    val currentTimeThreshold = serviceDataRepository.getTimeThreshold(identifier)
    return ShowCountCappingInfo(currentNumberOfShows, currentTime, currentTimeThreshold)
  }

  override fun cappingStatus(identifier: Identifier): CappingStatus {
    val config = configs[identifier] ?: return CappingStatus(isCapped = false)

    if (isCapped(config, identifier)) {
      return CappingStatus(isCapped = true, type = CappingType.ShowCount)
    }
    return CappingStatus(isCapped = false)
  }

  private fun isCapped(config: ShowCountCappingConfig, identifier: String): Boolean {
    val cappingInfo = getCappingInfo(identifier)
    val currentTimeThreshold = cappingInfo.currentTimeThreshold ?: return false

    return cappingInfo.currentNumberOfShows >= config.maxImpressions() &&
        currentTimeProvider.nowInMilliseconds() < currentTimeThreshold
  }

  override fun addConfig(
      identifier: Identifier,
      cappingType: CappingType,
      cappingConfig: ICappingConfigProvider
  ): Result<Unit> {
    cappingConfig
        .createShowCountValidatedConfig()
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
    val config = configs[identifier] ?: return

    val cappingInfo = getCappingInfo(identifier)

    // Check if it's the first show or if the time threshold has passed
    if (cappingInfo.currentNumberOfShows == 0 ||
        cappingInfo.currentTime >= (cappingInfo.currentTimeThreshold ?: 0)) {
      // Reset the time threshold and show counter
      val updatedTimeThreshold = cappingInfo.currentTime + config.unit().inMilliseconds()
      serviceDataRepository.setTimeThreshold(updatedTimeThreshold, identifier)
      cappingInfo.currentNumberOfShows = 0
    }

    // Increment the show counter and update the storage
    cappingInfo.currentNumberOfShows++
    serviceDataRepository.setCurrentNumberOfShows(cappingInfo.currentNumberOfShows, identifier)
  }

  internal data class ShowCountCappingInfo(
      var currentNumberOfShows: Int,
      var currentTime: Long,
      var currentTimeThreshold: Long?
  )
}
