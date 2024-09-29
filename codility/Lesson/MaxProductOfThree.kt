package codility

fun solution_MaxProductOfThree(A: IntArray): Int {
    val sorted = A.sorted()
    val n = A.size
    val case1 = sorted[n-1] * sorted[n-2] * sorted[n-3]
    val case2 = sorted[0] * sorted[1] * sorted[n-1]
    return Math.max(case1, case2)
}