package boj

import kotlin.math.min

private const val INF = Int.MAX_VALUE

fun main() = with(System.`in`.bufferedReader()) {
    val (v, e) = readLine().split(' ').map { it.toInt() }
    val map = Array(v + 1) { IntArray(v + 1) { INF } }
    var minDist = INF

    repeat(e) {
        val (a, b, c) = readLine().split(' ').map { it.toInt() }
        map[a][b] = c
    }

    for (k in 1..v) { // 거쳐가는 노드
        for (i in 1..v) {
            for (j in 1..v) {
                if (map[i][k].toLong() + map[k][j] > INF) continue
                map[i][j] = min(map[i][j], map[i][k] + map[k][j])
            }
        }
    }

    for (i in 1..v) {
        minDist = min(minDist, map[i][i])
    }
    println(if (minDist == INF) -1 else minDist)
}