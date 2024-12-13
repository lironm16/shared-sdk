package com.levelplay.shared.capping.placement

import com.levelplay.shared.AdFormat


class PlacementIdentifierliron(
    private val placementName: String,
    private val adFormat: AdFormat
) {
  fun value() = "${placementName}_${adFormat}_liron4333e7"
}
