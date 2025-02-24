package boj

import kotlin.math.max

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val m = readLine().toInt()
    val location = readLine().split(' ').map { it.toInt() }
    var (maxHalf, maxWidth) = max(location[0], n - location[m - 1]) to 0
    for (i in 0..<m - 1) {
        maxWidth = max(maxWidth, location[i + 1] - location[i])
    }
    println(max((maxWidth + 1) / 2, maxHalf))
}