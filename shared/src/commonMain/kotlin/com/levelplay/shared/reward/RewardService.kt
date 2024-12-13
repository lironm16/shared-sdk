package com.levelplay.shared.reward

class RewardService : IRewardService, IRewardService.Editor {

    private val placementConfig: MutableMap<String, LevelPlayReward> = mutableMapOf()
    private val adUnitIdConfig: MutableMap<String, LevelPlayReward> = mutableMapOf()

    override fun addPlacementConfig(placement: String, rewardName: String, rewardAmount: Int) {
        val reward = LevelPlayReward(rewardName, rewardAmount)
        placementConfig[placement] = reward
    }

    override fun addAdUnitIdConfig(adUnitId: String, rewardName: String, rewardAmount: Int) {
        val reward = LevelPlayReward(rewardName, rewardAmount)
        adUnitIdConfig[adUnitId] = reward
    }

    override fun getReward(placement: String?, adUnitId: String): LevelPlayReward? {
        return getPlacementReward(placement) ?: getAdUnitReward(adUnitId)
    }

    private fun getPlacementReward(placement: String?): LevelPlayReward? {
        return if (!placement.isNullOrEmpty()) {
            placementConfig[placement]
        } else {
            null
        }
    }

    private fun getAdUnitReward(adUnitId: String): LevelPlayReward? {
        return adUnitIdConfig[adUnitId]
    }
}
