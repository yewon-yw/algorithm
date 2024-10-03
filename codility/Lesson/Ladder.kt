package codility

fun solution_Ladder(A: IntArray, B: IntArray): IntArray {
    val L = A.size
    val maxA = A.maxOrNull() ?: 0
    val maxB = B.maxOrNull() ?: 0
    val ways = Array(maxA + 1) { IntArray(maxB + 1) { 1 } }
    val answer = IntArray(L)

    for (i in 2..maxA) {
        for (j in 1..maxB) {
            val mod = 1 shl j // 2^j
            ways[i][j] = (ways[i - 1][j] + ways[i - 2][j]) % mod
        }
    }

    repeat(L) { i ->
        answer[i] = ways[A[i]][B[i]]
    }
    return answer
}