package part5

import kotlin.math.max

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val dp = IntArray(n + 1)
    repeat(n) { i ->
        val (t, p) = readLine().split(' ').map { it.toInt() }
        if (i + t <= n) dp[i + t] = max(dp[i] + p, dp[i + t])
        dp[i + 1] = max(dp[i], dp[i + 1])
    }
    println(dp[n])
}