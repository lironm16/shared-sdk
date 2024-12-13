package com.levelplay.shared

class Greeting {
    fun greeting(): String {
        return "Hello, ${com.levelplay.shared.getPlatform().platform}!!!xxx"
    }
}
