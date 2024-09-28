package programmers

import kotlin.math.*

class Solution20 {
    fun solution1(n: Int, left: Long, right: Long): IntArray {
        var answer = mutableListOf<Int>()
        // left -> (left / n, left % n)에 위치
        // right도 마찬가지
        // max(행, 열) + 1 값을 가짐
        // answer 원소들은 n과 같은 범위 -> Int
        for (i in left..right) {
            answer.add(max(i / n, i % n).toInt() + 1)
        }
        return answer.toIntArray()
    }

    // concise version
    fun solution2(n: Int, left: Long, right: Long): IntArray {
        return (left..right).map { max(it / n, it % n).toInt() + 1 }.toIntArray()
    }
}