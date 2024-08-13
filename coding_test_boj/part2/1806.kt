package part2

import kotlin.math.min
fun main() = with(System.`in`.bufferedReader()) {
    val (n, s) = readLine().split(' ').map { it.toInt() }
    val seq = readLine().split(' ').map { it.toInt() }

    var min = Int.MAX_VALUE
    var start = 0
    var end = 0
    var sum = 0

    while (end <= n) {
        if (sum >= s) {
            min = min(min, end - start)
            sum -= seq[start]
            start++
        } else {
            if (end == n) break
            sum += seq[end]
            end++
        }
    }
    println(if (min == Int.MAX_VALUE) 0 else min)
}