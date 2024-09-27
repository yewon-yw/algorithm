package programmers

import kotlin.math.*

class Solution19 {
    fun solution(n: Int, a: Int, b: Int): Int {
        var answer = 0
        var (first, second) = a to b
        while (first != second) {
            first = ceil(first / 2.toDouble()).toInt()
            second = ceil(second / 2.toDouble()).toInt()
            answer++
        }
        return answer
    }
}