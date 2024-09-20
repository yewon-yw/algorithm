package programmers

class Solution15 {
    fun solution(citations: IntArray): Int {
        val sorted = citations.sortedByDescending { it }
        for(h in sorted[0] downTo 1) {
            if(h > sorted.size) continue
            if(h <= sorted[h-1]) return h
        }
        return 0
    }
}