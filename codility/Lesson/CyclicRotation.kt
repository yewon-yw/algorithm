fun solution(A: IntArray, K: Int): IntArray {
    val rotated = IntArray(A.size)
    for (i in A.indices) {
        rotated[(i + K) % (A.size)] = A[i]
    }
    return rotated
}

fun main() = with(System.`in`.bufferedReader()) {
    val a = readLine().split(' ').map { it.toInt() }.toIntArray()
    val k = readLine().toInt()
    println(solution(a, k).contentToString())
}