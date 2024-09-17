package programmers

class Solution13 {
    fun solution(k: Int, tangerine: IntArray): Int {
        var answer: Int = 0
        val map = mutableMapOf<Int, Int>()
        tangerine.forEach { t ->
            map[t] = (map[t] ?: 0) + 1
        }
        val sorted = map.entries.sortedByDescending { it.value }
        var count = 0
        run loop@{
            sorted.forEach {
                count += it.value
                answer++
                if (count >= k) return@loop
            }
        }
        return answer
    }
}