package codility

fun solution_MissingInteger(A: IntArray): Int {
    val setA = A.toSet().filter { it > 0 }
    val size = (setA.maxOrNull()?: 0).let { if(it < 0) 0 else it }
    val exist = BooleanArray(size + 1) { false }
    setA.forEach {
        exist[it - 1] = true
    }
    exist.forEachIndexed { idx, it ->
        if(!it) return idx + 1
    }
    return 1
}