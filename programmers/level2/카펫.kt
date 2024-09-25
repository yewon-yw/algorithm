package programmers

class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        // 노란 카펫 가로 w, 세로 h
        // 1. (w+2)*2 + 2h = 2(w+h) + 4 = brown
        // 2. w*h = yellow
        // 결과: (w+2, h+2)
        var answer = intArrayOf()
        for (w in 1..yellow) {
            if (yellow % w != 0) continue
            val h = yellow / w
            if (2 * (w + h) + 4 == brown) answer = intArrayOf(w + 2, h + 2)
        }
        return answer
    }
}