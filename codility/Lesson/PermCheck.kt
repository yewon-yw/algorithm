package codility

fun solution(A: IntArray): Int {
    val exist = BooleanArray(A.size) { false }
    A.forEach {
        if(it > A.size) return 0
        exist[it - 1] = true
    }
    return if(exist.filter{ it }.size == A.size) 1 else 0
}