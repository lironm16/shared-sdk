package com.levelplay.shared.capping.config

interface ICappingConfigValidator {
  fun validateConfig(): Result<Boolean>
}
