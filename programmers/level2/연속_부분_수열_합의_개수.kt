package programmers

class Solution14 {
    fun solution(elements: IntArray): Int {
        val num = mutableSetOf<Int>()
        for(len in 1..elements.size) {
            for(i in elements.indices) {
                var sum = 0
                var start = i
                repeat(len) {
                    sum += elements[(start++) % elements.size]
                }
                num.add(sum)
            }
        }
        return num.size
    }
}