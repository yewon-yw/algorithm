package codility

fun solution_FrogRiverOne(X: Int, A: IntArray): Int {
    val s = mutableSetOf<Int>()
    for(i in A.indices) {
        s.add(A[i])
        if(s.size == X) return i
    }
    return -1
}