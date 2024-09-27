package codility

fun solution_MaxCounters(N: Int, A: IntArray): IntArray {
    val counter = IntArray(N) { 0 }
    var max = 0
    var lastMax = 0
    A.forEach {
        if(it > N) lastMax = max
        else {
            if(counter[it-1] < lastMax) {
                counter[it-1] = lastMax + 1
            } else {
                counter[it-1]++
            }
            if(max < counter[it-1]) max = counter[it-1]
        }
    }
    counter.forEachIndexed { idx, it ->
        if(it < lastMax) counter[idx] = lastMax
    }
    return counter
}