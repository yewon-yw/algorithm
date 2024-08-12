fun solution(X: Int, Y: Int, D: Int): Int {
    val jumps = (Y - X) / D
    return if ((Y - X) % D > 0) jumps + 1
    else jumps
}

fun main() = with(System.`in`.bufferedReader()) {
    val (x, y, d) = readLine().split(' ').map { it.toInt() }
    println(solution(x, y, d))
}