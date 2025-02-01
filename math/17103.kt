package boj

import kotlin.math.sqrt

fun main() = with(System.`in`.bufferedReader()) {
    val t = readLine().toInt()
    val max = 1_000_000
    val isPrime = BooleanArray(max)
    isPrime[2] = true
    for (i in 3..max step 2) {
        var isDivisible = false
        for (j in 3..sqrt(i.toDouble()).toInt()) {
            if (i % j == 0) isDivisible = true
        }
        if (!isDivisible) {
            isPrime[i] = true
        }
    }

    repeat(t) {
        val n = readLine().toInt()
        var count = 0
        for (i in 2..n/2) {
            if (isPrime[i] && isPrime[n-i]) count++
        }
        println(count)
    }
}