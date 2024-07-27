fun solution(A: IntArray): Int {
    var unpaired = 0
    for(e in A) {
        unpaired = unpaired xor e
    }
    return unpaired
}

fun main() = with(System.`in`.bufferedReader()) {
    val A = readLine().split(" ").map { it.toInt() }.toIntArray()
    println(solution(A))
}