package part6

import kotlin.math.sqrt

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val prime = listOf(2, 3, 5, 7)
    val odd = listOf(1, 3, 7, 9)
    fun isPrime(num: Int): Boolean {
        for (i in 2..sqrt(num.toDouble()).toInt()) {
            if (num % i == 0) return false
        }
        return true
    }

    fun dfs(num: String, size: Int) {
        if (size == n) {
            println(num)
            return
        }
        odd.forEach {
            val next = "$num$it"
            if (isPrime(next.toInt())) {
                dfs(num + it, size + 1)
            }
        }
    }
    prime.forEach {
        dfs(it.toString(), 1)
    }
}