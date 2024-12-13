package com.levelplay.shared

interface DataStorage {
    // Provider methods
    fun getString(key: String): String?
    fun getBool(key: String): Boolean
    fun getObject(key: String): Any?

    // Editor methods
    fun set(value: Any?, key: String)
    fun removeObject(key: String)
}
