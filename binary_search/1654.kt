package boj

import kotlin.math.max

fun main() = with(System.`in`.bufferedReader()) {
    val (k, n) = readLine().split(' ').map { it.toInt() }
    val cable = mutableListOf<Int>()
    repeat(k) {
        cable.add(readLine().toInt())
    }
    cable.sort()
    var (start, end) = 1L to cable[k - 1].toLong()
    var result = 0L

    while (start <= end) {
        val mid = (start + end) / 2L
        val cableCount = cable.sumOf { it / mid }
        if (cableCount < n) {
            end = mid - 1
        } else {
            result = max(result, mid)
            start = mid + 1
        }
    }
    println(result)
}