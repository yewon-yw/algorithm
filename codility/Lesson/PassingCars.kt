package codility

fun solution_PassingCars(A: IntArray): Int {
    // (A[p], A[q]) = (0, 1) 쌍 찾기 (p < q)
    var sum = A.count { it == 1 }
    var answer = 0L
    A.forEach {
        if(it == 1) sum--
        else answer += sum
    }
    return if(answer > 1_000_000_000) -1 else answer.toInt()
}