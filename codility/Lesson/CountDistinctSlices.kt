package codility

fun solution_CountDistinctSlices(M: Int, A: IntArray): Int {
    val exist = mutableMapOf<Int, Int>()
    var (start, end) = 0 to 0
    var count = 0
    val MAX = 1_000_000_000

    while(start < A.size) {
        while(end < A.size) {
            if((exist[A[end]]?: 0) == 0) {
                exist[A[end]] = 1
                end++
            } else break
        }
        count += if(start == end) 1 else end - start
        if(count > MAX) break
        exist[A[start]] = 0
        start++
    }
    return if(count > MAX) MAX else count
}