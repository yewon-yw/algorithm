package boj

import kotlin.math.max

fun main() = with(System.`in`.bufferedReader()) {
    val (n, k) = readLine().split(' ').map { it.toInt() }
    val num = readLine().split(' ').map { it.toInt() }
    val sum = IntArray(n + 1)
    var max = Int.MIN_VALUE

    repeat(n) { idx ->
        sum[idx+1] = sum[idx] + num[idx]
    }

    for (i in k..n) {
        max = max(sum[i] - sum[i-k], max)
    }
    println(max)
}
