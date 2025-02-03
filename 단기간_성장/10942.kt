package boj

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val num = readLine().split(' ').map { it.toInt() }
    val dp = Array(n) { BooleanArray(n) }

    for (step in 0..<n) {
        for (s in 0..<n - step) {
            val e = s + step
            if (s == e) {
                dp[s][e] = true
                continue
            }
            dp[s][e] = num[s] == num[e]
            if (s + 1 <= e - 1) {
                dp[s][e] = dp[s][e] && dp[s + 1][e - 1]
            }
        }
    }

    val m = readLine().toInt()
    val bw = System.out.bufferedWriter()
    repeat(m) {
        val (s, e) = readLine().split(' ').map { it.toInt() - 1 }
        bw.write("${if (dp[s][e]) 1 else 0}\n")
    }
    bw.flush()
    bw.close()
}