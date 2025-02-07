package boj

import kotlin.math.min

//data class ShortCut(
//    val start: Int,
//    val end: Int,
//    val dis: Int
//)

//fun main() = with(System.`in`.bufferedReader()) {
//    val (n, d) = readLine().split(' ').map { it.toInt() }
//    val dp = (0..d).map { it }.toIntArray()
//    val short = mutableListOf<ShortCut>()
//
//    repeat(n) {
//        val (s, e, l) = readLine().split(' ').map { it.toInt() }
//        if (e <= d && e - s > l) {
//            short.add(ShortCut(s, e, l))
//        }
//    }
//    short.sortBy { it.end }
//
//    short.forEach { (s, e, l) ->
//        if (e <= d && e - s > l) {
//            dp[e] = min(dp[s] + l, dp[e])
//            for (i in 1..d) {
//                dp[i] = min(dp[i - 1] + 1, dp[i])
//            }
//        }
//    }
//    println(dp[d])
//}

fun main() = with(System.`in`.bufferedReader()) {
    val (n, d) = readLine().split(' ').map { it.toInt() }
    val dp = IntArray(d + 1) { it }
    val short = mutableListOf<Triple<Int, Int, Int>>()

    repeat(n) {
        val (s, e, l) = readLine().split(' ').map { it.toInt() }
        if (e <= d && e - s > l) {
            short.add(Triple(s, e, l))
        }
    }

    for (i in 0..<d) {
        dp[i + 1] = min(dp[i] + 1, dp[i + 1])
        short.forEach { (s, e, l) ->
            if (i == s) {
                dp[e] = min(dp[s] + l, dp[e])
            }
        }
    }
    println(dp[d])
}