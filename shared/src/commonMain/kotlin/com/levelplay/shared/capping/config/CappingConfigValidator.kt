package com.levelplay.shared.capping.config

import com.levelplay.shared.capping.CappingTimeUnit

class CappingConfigValidator(
    private val enabled: Boolean?,
    private val limit: Int?,
    private val unit: CappingTimeUnit?
) : ICappingConfigValidator {

  override fun validateConfig(): Result<Boolean> {
    if (enabled == null) {
      return Result.failure(Exception("enabled flag is not provided or invalid"))
    }

    if (!enabled) {
      return Result.success(false)
    }

    if (limit == null || limit <= 0) {
      return Result.failure(Exception("limit flag is not provided or invalid"))
    }
    if (unit == null) {
      return Result.failure(Exception("unit flag is not provided or invalid"))
    }

    return Result.success(true)
  }
}
