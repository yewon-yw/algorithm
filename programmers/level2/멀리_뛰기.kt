package programmers

class Solution12 {
    fun solution(n: Int): Long {
        val mod = 1234567
        val dp = LongArray(n + 1)
        dp[1] = 1
        if (n >= 2) dp[2] = 2
        for (i in 3..n) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod
        }
        return dp[n]
    }
}