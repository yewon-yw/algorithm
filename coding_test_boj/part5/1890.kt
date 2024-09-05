package part5

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val game = Array(n) { IntArray(n) }
    val dp = Array(n) { LongArray(n) }
    repeat(n) { i ->
        game[i] = readLine().split(' ').map { it.toInt() }.toIntArray()
    }
    dp[0][0] = 1
    for (i in 0..<n) {
        for (j in 0..<n) {
            if (game[i][j] == 0) continue
            if (dp[i][j] == 0L) continue
            val nextI = i + game[i][j]
            val nextJ = j + game[i][j]
            if (nextI < n) dp[nextI][j] += dp[i][j]
            if (nextJ < n) dp[i][nextJ] += dp[i][j]
        }
    }
    println(dp[n - 1][n - 1])
}