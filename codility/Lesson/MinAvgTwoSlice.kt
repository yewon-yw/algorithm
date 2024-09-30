package codility

fun solution_MinAvgTwoSlice_1(A: IntArray): Int {
    // check length 2 or 3 slice
    val N = A.size
    var minAvg = 10_000.0
    var minPos = 0

    // length 2
    for(i in 0..N-2) {
        val avg = (A[i] + A[i+1]) / 2.0
        if(avg < minAvg) {
            minAvg = avg
            minPos = i
        }
    }

    // length 3
    for(i in 0..N-3) {
        val avg = (A[i] + A[i+1] + A[i+2]) / 3.0
        if(avg < minAvg) {
            minAvg = avg
            minPos = i
        }
    }

    return minPos
}

// for문 줄인 버전
fun solution_MinAvgTwoSlice_2(A: IntArray): Int {
    // check length 2 or 3 slice
    val N = A.size
    var minAvg = 10_000.0
    var minPos = 0

    fun checkMin(avg: Double, pos: Int) {
        if(avg < minAvg) {
            minAvg = avg
            minPos = pos
        }
    }

    for(i in 0..N-2) {
        checkMin((A[i] + A[i+1]) / 2.0, i)
        if(i < N-2) {
            checkMin((A[i] + A[i+1] + A[i+2]) / 3.0, i)
        }
    }

    return minPos
}
