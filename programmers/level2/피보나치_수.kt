package programmers

class Solution17 {
    // memoization
    // recursive method occurs timeout
    fun solution(n: Int): Int {
        val mod = 1234567
        val dp = IntArray(n + 1)
        dp[0] = 0
        dp[1] = 1
        for (i in 2..n) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod
        }
        return dp[n]
    }

    // less memory
    fun solution2(n: Int): Int {
        val mod = 1234567
        var first = 0
        var second = 1
        var result = 0
        for (i in 2..n) {
            result = (first + second) % mod
            first = second
            second = result
        }
        return result
    }
}