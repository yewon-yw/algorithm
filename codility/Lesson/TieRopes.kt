package codility

fun solution(K: Int, A: IntArray): Int {
    var tempLength = 0
    var count = 0
    A.forEach {
        tempLength += it
        if(tempLength >= K) {
            count++
            tempLength = 0
        }
    }
    return count
}