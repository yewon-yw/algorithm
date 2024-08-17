package part3

fun main() = with(System.`in`.bufferedReader()) {
    val (n, k) = readLine().split(' ').map { it.toInt() }
    val dp = IntArray(k + 1)
    repeat(n) {
        val num = readLine().toInt()
        for (i in 1..k) {
            if (i == num) dp[i]++
            if (i >= num) dp[i] += dp[i - num]
        }
    }
    println(dp[k])
}