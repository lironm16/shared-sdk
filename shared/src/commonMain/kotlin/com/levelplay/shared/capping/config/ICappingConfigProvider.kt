package com.levelplay.shared.capping.config

import com.levelplay.shared.capping.delivery.DeliveryCappingConfig
import com.levelplay.shared.capping.pacing.PacingCappingConfig
import com.levelplay.shared.capping.showcount.ShowCountCappingConfig

interface ICappingConfigProvider {
  fun createShowCountValidatedConfig(): Result<ShowCountCappingConfig?>

  fun createPacingValidatedConfig(): Result<PacingCappingConfig?>

  fun createDeliveryValidatedConfig(): Result<DeliveryCappingConfig?>
}
