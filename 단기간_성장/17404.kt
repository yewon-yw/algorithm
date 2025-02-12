package boj

import kotlin.math.min

private const val INF = 1_000_001

fun main() = with(System.`in`.bufferedReader()) {
    var minCost = INF
    val n = readLine().toInt()
    val costs = Array(n) { IntArray(3) }
    repeat(n) { idx ->
        costs[idx] = readLine().split(' ').map { it.toInt() }.toIntArray()
    }

    for (idx in 0..2) {
        val dp = Array(n) { IntArray(3) { INF } }
        dp[0][idx] = costs[0][idx]

        for (i in 1..<n) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0]
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1]
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2]
            dp[i] = dp[i].map { if (it >= INF) INF else it }.toIntArray()
        }
        for (i in 0..2) {
            if (i != idx) minCost = min(minCost, dp[n - 1][i])
        }
    }

    println(minCost)
}