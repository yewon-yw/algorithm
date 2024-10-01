package codility

// 보이어 무어 방식으로는 정확한 답이 나오지 않음
// Map 사용
fun solution_EquiLeader(A: IntArray): Int {
    var count = Int.MIN_VALUE
    var dominator = 0
    var leaders = 0
    val size = A.size
    val map = mutableMapOf<Int, Int>()

    // dominator 찾기
    A.forEach {
        map[it] = (map[it] ?: 0) + 1
    }
    map.forEach { (k, v) ->
        if (v > count) {
            count = v
            dominator = k
        }
    }

    if (count <= size / 2) return 0

    var (first, second) = 0 to count
    A.forEachIndexed { idx, it ->
        if (it == dominator) { // 두 부분으로 나눴을 때 각 부분에 candidate 개수 갱신
            first++
            second--
        }
        // 각 부분이 leader를 가지는지 확인
        val firstSize = idx + 1
        if (first > firstSize / 2 && second > (size - firstSize) / 2) {
            leaders++
        }
    }
    return leaders
}