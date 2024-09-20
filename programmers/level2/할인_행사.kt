package programmers

class Solution16 {
    // 할인하는 상품 중에 내가 원하는 항목과 수량이 존재하는지 확인
    fun check(map: Map<String, Int>, want: Array<String>, number: IntArray): Boolean {
        want.forEachIndexed { index, p ->
            if (map[p] ?: 0 != number[index]) return false
        }
        return true
    }

    fun solution(want: Array<String>, number: IntArray, discount: Array<String>): Int {
        var answer: Int = 0
        for (start in 0..discount.size - 10) {
            val map = mutableMapOf<String, Int>()
            for (i in start..start + 9) {
                map[discount[i]] = (map[discount[i]] ?: 0) + 1
            }
            if (check(map, want, number)) answer++
        }
        return answer
    }
}