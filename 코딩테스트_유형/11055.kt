fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val arr = readLine().split(' ').map { it.toInt() }
    val dp = arr.toIntArray()
    repeat(n) { i ->
        for (j in 0..<i) {
            if (arr[j] < arr[i]) {
                dp[i] = maxOf(dp[i], dp[j] + arr[i])
            }
        }
    }
    println(dp.max())
}