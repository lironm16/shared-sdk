package com.levelplay.shared.capping

import com.levelplay.shared.capping.config.CappingType
import com.levelplay.shared.capping.config.ICappingConfigProvider

typealias Identifier = String

interface ICappingService {
  /**
   * Request cappingStatus for identifier
   *
   * @param identifier the identifier to check if it is capped.
   * @return CappingStatus
   */
  fun cappingStatus(identifier: Identifier): CappingStatus

  /** Editor to update service data. */
  interface Editor {
    fun addConfig(
        identifier: Identifier,
        cappingType: CappingType,
        cappingConfig: ICappingConfigProvider
    ): Result<Unit>

    fun updateCappingOnShow(identifier: Identifier)
  }
}
