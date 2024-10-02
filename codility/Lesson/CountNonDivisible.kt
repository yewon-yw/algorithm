package codility

fun solution_CountNonDivisible(A: IntArray): IntArray {
    // 빈도 확인용 map
    val map = mutableMapOf<Int, Int>()
    val answer = mutableListOf<Int>()
    A.forEach {
        map[it] = (map[it]?: 0) + 1
    }
    A.forEach {
        var i = 1
        var count = 0
        // 나눌 수 있는 요소 count
        while(i * i <= it) {
            if(it % i == 0) {
                count += (map[i]?: 0)
                if(i * i != it) {
                    count += (map[it / i]?: 0)
                }
            }
            i++
        }
        // 나눌 수 없는 요소 = 전체 - 나눌 수 있는 요소
        answer.add(A.size - count)
    }
    return answer.toIntArray()
}