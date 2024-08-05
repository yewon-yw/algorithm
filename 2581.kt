package basic

import kotlin.math.sqrt

fun main() = with(System.`in`.bufferedReader()) {
    val m = readLine().toInt()
    val n = readLine().toInt()
    val prime = mutableListOf<Int>()

    for (i in m..n) {
        var isPrime = true
        if (i == 1) continue
        for (j in 2..sqrt(i.toDouble()).toInt()) {
            if (i % j == 0) isPrime = false
        }
        if (isPrime) prime.add(i)
    }
    if (prime.isEmpty()) {
        println(-1)
    } else {
        println(prime.sum())
        println(prime.min())
    }
}