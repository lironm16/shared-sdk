package com.levelplay.shared

import kotlin.test.Test
import kotlin.test.assertTrue

class GreetingTest {

    @Test
    fun testExample() {
        assertTrue(com.levelplay.shared.Greeting().greeting().contains("iOS"), "Check iOS is mentioned")
    }
}