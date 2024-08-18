package part3

import kotlin.math.min

fun main() = with(System.`in`.bufferedReader()) {
    val (n, k) = readLine().split(' ').map { it.toInt() }
    val max = 10_001
    val dp = IntArray(k + 1) { max }
    dp[0] = 0
    repeat(n) {
        val num = readLine().toInt()
        for (i in num..k) {
            dp[i] = min(dp[i], dp[i - num] + 1)
        }
    }
    println(if (dp[k] == max) -1 else dp[k])
}