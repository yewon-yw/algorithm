import kotlin.math.abs

private fun solution(A: IntArray): Int {
    val sum = A.sum()
    var min = Int.MAX_VALUE
    var firstSum = 0
    for (i in 0..A.size - 2) {
        firstSum += A[i]
        val secondSum = sum - firstSum
        val tempRes = abs(firstSum - secondSum)
        if (tempRes < min) min = tempRes
    }
    return min
}

fun main() = with(System.`in`.bufferedReader()) {
    val A = readLine().split(' ').map { it.toInt() }.toIntArray()
    println(solution(A))
}