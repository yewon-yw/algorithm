package programmers

class Solution11 {
    fun solution1(lines: Array<IntArray>): Int {
        // 최소, 최대 값 구해서 선분이 하나만 있는 경우를 삭제
        var answer: Int = 0
        var (start, end) = lines[0][0] to lines[0][1]
        lines.forEach { line ->
            if (start > line[0]) start = line[0]
            if (end < line[1]) end = line[1]
        }
        for (i in start until end) {
            var count = 0
            for (j in 0..2) {
                if (i in lines[j][0] until lines[j][1]) count++
            }
            if (count > 1) answer++
        }
        return answer
    }

    fun solution2(lines: Array<IntArray>): Int {
        // 메모리 사용
        val common = IntArray(201)
        lines.forEach { line ->
            for (i in line[0] + 100 until line[1] + 100) {
                common[i]++
            }
        }
        return common.filter { it > 1 }.size
    }
}