package com.levelplay.shared.capping.config

class DeliveryConfigValidator(private val enabled: Boolean?) : ICappingConfigValidator {

  override fun validateConfig(): Result<Boolean> {
    if (enabled == null) {
      return Result.failure(Exception("enabled flag is not provided or invalid"))
    }

    return Result.success(enabled)
  }
}
