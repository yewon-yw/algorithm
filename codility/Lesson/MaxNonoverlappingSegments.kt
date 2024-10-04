package codility

fun solution_MaxNonoverlappingSegments(A: IntArray, B: IntArray): Int {
    // 이미 종료가 빠른 순서대로 정렬되어있기 때문에 그리디로 해결해도 됨
    var count = 0
    var end = -1

    for(i in 0 until A.size) {
        if(end < A[i]) {
            count++
            end = B[i]
        }
    }

    return count
}