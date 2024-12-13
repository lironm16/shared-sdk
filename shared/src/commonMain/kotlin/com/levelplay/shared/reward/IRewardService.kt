package com.levelplay.shared.reward

interface IRewardService {

    /** Editor to update service data. */
    interface Editor {
        fun addPlacementConfig(
            placement: String,
            rewardName: String,
            rewardAmount: Int,
        )

        fun addAdUnitIdConfig(
            adUnitId: String,
            rewardName: String,
            rewardAmount: Int,
        )
    }

    fun getReward(placement: String?, adUnitId: String): LevelPlayReward?
}