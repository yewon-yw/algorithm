package codility

import kotlin.math.*

// O(N * log(log(N)) + M)
fun solution(N: Int, P: IntArray, Q: IntArray): IntArray {
    val isPrime = BooleanArray(N+1) { true }
    val prime = mutableListOf<Int>()
    val semiprime = IntArray(N+1)
    val answer = IntArray(P.size)
    isPrime[0] = false
    isPrime[1] = false

    // prime 찾기
    val sqrt = sqrt(N.toDouble()).toInt()
    for(i in 2..sqrt) {
        var p = i * 2
        while(p <= N) {
            isPrime[p] = false
            p += i
        }
    }

    // prime 원소만 추출
    isPrime.forEachIndexed { idx, isP ->
        if(isP) prime.add(idx)
    }

    // semiprime 찾기
//    prime.forEach { p1 ->
//        prime.forEach { p2 ->
//            val candidate: Long = p1 * p2.toLong()
//            if(candidate <= N) {
//                semiprime[candidate.toInt()] = 1
//            }
//        }
//    }
    // semiprime 찾기 - less 반복문
    prime.forEach { p1 ->
        for(p2 in p1..(N/p1)) {
            if(isPrime[p2]) {
                semiprime[p1 * p2] = 1
            }
        }
    }

    // i 까지의 semiprime 개수 저장
    for(i in 1..N) {
        semiprime[i] += semiprime[i-1]
    }

    // p~q 까지의 semiprime 개수
    for(i in P.indices) {
        val (p, q) = P[i] to Q[i]
        answer[i] = semiprime[q] - semiprime[p - 1]
    }

    return answer
}