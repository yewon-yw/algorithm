package codility

fun solution(S: String, P: IntArray, Q: IntArray): IntArray {
    // (P[i], Q[i]) = (start, end)
    val (N, M) = S.length to P.size
    val answer = IntArray(M)
    val aCount = IntArray(N + 1)
    val cCount = IntArray(N + 1)
    val gCount = IntArray(N + 1)

    for (i in 1..N) {
        aCount[i] = aCount[i - 1]
        cCount[i] = cCount[i - 1]
        gCount[i] = gCount[i - 1]
        when (S[i - 1]) {
            'A' -> aCount[i]++
            'C' -> cCount[i]++
            'G' -> gCount[i]++
            else -> {}
        }
    }

    for (i in 0 until M) {
        val (s, e) = P[i] to Q[i] + 1
        if (aCount[e] - aCount[s] > 0) answer[i] = 1
        else if (cCount[e] - cCount[s] > 0) answer[i] = 2
        else if (gCount[e] - gCount[s] > 0) answer[i] = 3
        else answer[i] = 4
    }
    return answer
}
