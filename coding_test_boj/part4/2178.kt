package part4

import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    val (n, m) = readLine().split(' ').map { it.toInt() }
    val map = Array(n + 2) { IntArray(m + 2) }
    val dis = Array(n + 1) { IntArray(m + 1) }
    val q: Queue<Pair<Int, Int>> = LinkedList()
    val xOffset = listOf(1, 0, -1, 0)
    val yOffset = listOf(0, 1, 0, -1)
    for (i in 1..n) {
        val line = readLine().toCharArray().map { it.code - 48 }.toIntArray()
        for (j in 1..m) {
            map[i][j] = line[j - 1]
        }
    }
    fun bfs() {
        while (q.isNotEmpty()) {
            val top = q.poll()
            if (top.first == n && top.second == m) return
            for (i in 0..3) {
                val nextX = top.first + xOffset[i]
                val nextY = top.second + yOffset[i]
                if (map[nextX][nextY] == 1) {
                    map[nextX][nextY] = 0
                    q.add(nextX to nextY)
                    dis[nextX][nextY] = dis[top.first][top.second] + 1
                }
            }
        }
    }
    map[1][1] = 0
    dis[1][1] = 1
    q.add(1 to 1)
    bfs()
    println(dis[n][m])
}