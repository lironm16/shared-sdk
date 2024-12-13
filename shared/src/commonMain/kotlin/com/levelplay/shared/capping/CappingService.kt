package com.levelplay.shared.capping

import com.levelplay.shared.CurrentTimeProvider
import com.levelplay.shared.DataStorage
import com.levelplay.shared.capping.config.CappingType
import com.levelplay.shared.capping.config.ICappingConfigProvider
import com.levelplay.shared.capping.pacing.PacingCappingHandler
import com.levelplay.shared.capping.pacing.PacingDataRepository
import com.levelplay.shared.capping.showcount.ShowCountDataRepository
import com.levelplay.shared.capping.showcount.ShowCountHandler
import kotlin.jvm.Synchronized

class CappingService(
    currentTimeProvider: CurrentTimeProvider,
    dataStorage: DataStorage,
) : ICappingService, ICappingService.Editor {

    private val pacingHandler: PacingCappingHandler =
        PacingCappingHandler(
            currentTimeProvider,
            PacingDataRepository(dataStorage)
        )

    private val showCountHandler: ShowCountHandler =
        ShowCountHandler(
            currentTimeProvider,
            ShowCountDataRepository(dataStorage)
        )

    @Synchronized
    override fun cappingStatus(identifier: Identifier): CappingStatus {
        val pacingStatus = pacingHandler.cappingStatus(identifier)
        if (pacingStatus.isCapped) {
            return pacingStatus
        }

        return showCountHandler.cappingStatus(identifier)
    }

    @Synchronized
    override fun addConfig(
        identifier: Identifier,
        cappingType: CappingType,
        cappingConfig: ICappingConfigProvider,
    ): Result<Unit> =
        when (cappingType) {
            CappingType.Pacing -> pacingHandler.addConfig(identifier, cappingType, cappingConfig)
            CappingType.ShowCount -> showCountHandler.addConfig(identifier, cappingType, cappingConfig)
            CappingType.Delivery -> Result.success(Unit)
        }

    @Synchronized
    override fun updateCappingOnShow(identifier: Identifier) {
        pacingHandler.updateCappingOnShow(identifier)
        showCountHandler.updateCappingOnShow(identifier)
    }
}