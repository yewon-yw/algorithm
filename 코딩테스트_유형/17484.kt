package boj

import kotlin.math.min

private const val INF = 1000
fun main() = with(System.`in`.bufferedReader()) {
    val (n, m) = readLine().split(' ').map { it.toInt() }
    val dp = Array(n) { Array(m) { IntArray(3) { INF } } }
    val arr = Array(n) { IntArray(m) }
    val dir = arrayOf(1, 0, -1)
    repeat(n) {
        arr[it] = readLine().split(' ').map { it.toInt() }.toIntArray()
    }

    for (i in 0..<n) {
        for (j in 0..<m) {
            for (k in 0..2) {
                val prevJ = j + dir[k]
                if (prevJ < 0 || prevJ >= m) continue
                for (d in 0..2) {
                    if (d == k) continue
                    if (i-1 < 0) {
                        dp[i][j][k] = arr[i][j]
                        continue
                    }
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][prevJ][d] + arr[i][j])
                }
            }
        }
    }

    var result = INF
    for (k in 0..2) {
        for (j in 0..<m) {
            result = min(result, dp[n-1][j][k])
        }
    }
    println(result)
}