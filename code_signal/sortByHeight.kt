package codesignal

fun solution10(a: MutableList<Int>): MutableList<Int> {
    // -1 값은 새 배열에 저장해놓고, 정렬 후 순서대로 넣기
    val heights = a.filter{it != -1}.sorted()
    var result = IntArray(a.size)
    var index = 0
    a.forEachIndexed { i, h ->
        if(h == -1) result[i] = -1
    }
    for(i in result.indices) {
        if(result[i] != - 1) {
            result[i] = heights[index]
            index++
        }
    }
    return result.toMutableList()
}
