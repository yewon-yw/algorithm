package codility

fun solution_MaxSliceSum(A: IntArray): Int {
    var (tempMax, max) = A[0] to A[0]
    for(i in 1 until A.size) {
        // A[i] 선택해서 slice를 늘릴지, A[i]부터 슬라이스 다시 시작
        tempMax = Math.max(tempMax + A[i], A[i])
        max = Math.max(tempMax, max)
    }
    return max
}