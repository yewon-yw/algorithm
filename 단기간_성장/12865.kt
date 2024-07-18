import kotlin.math.max

fun main() {
    val (n, k) = readln().split(' ').map { it.toInt() }
    val w = IntArray(n + 1)
    val v = IntArray(n + 1)
    val dp = Array(n + 1) { IntArray(k + 1) }

    for (i in 1..n) {
        val (weight, value) = readln().split(" ").map { it.toInt() }
        w[i] = weight; v[i] = value
    }
    for (i in 1..n) {
        for (j in 1..k) {
            dp[i][j] =
                if (j >= w[i]) max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i])
                else dp[i - 1][j]
        }
    }
    println(dp[n][k])
}