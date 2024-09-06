package programmers

class Solution2 {
    fun solution(name: Array<String>, yearning: IntArray, photo: Array<Array<String>>): IntArray {
        var answer: IntArray = IntArray(photo.size)
        val map = mutableMapOf<String, Int>()
        name.forEachIndexed { i, n ->
            map[n] = yearning[i]
        }
        for(i in photo.indices) {
            var sum = 0
            for(n in photo[i]) {
                sum += map[n]?: 0
            }
            answer[i] = sum
        }
        return answer
    }
}