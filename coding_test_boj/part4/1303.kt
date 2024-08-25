package part4

import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    val (n, m) = readLine().split(' ').map { it.toInt() }
    val map = Array(m) { CharArray(n) }
    val xOffset = listOf(1, -1, 0, 0)
    val yOffset = listOf(0, 0, 1, -1)
    val q: Queue<Pair<Int, Int>> = LinkedList()
    var our = 0
    var other = 0
    repeat(m) { i ->
        map[i] = readLine().toCharArray()
    }
    fun bfs(team: Char, x: Int, y: Int) {
        var count = 1
        map[x][y] = ' '
        q.add(x to y)
        while (q.isNotEmpty()) {
            val top = q.poll()
            for (i in 0..3) {
                val nextX = top.first + xOffset[i]
                val nextY = top.second + yOffset[i]
                if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue
                if (map[nextX][nextY] == team) {
                    q.add(nextX to nextY)
                    map[nextX][nextY] = ' '
                    count++
                }
            }
        }
        if (team == 'W') our += count * count
        else other += count * count
    }
    for (i in 0..<m) {
        for (j in 0..<n) {
            when (map[i][j]) {
                'W' -> bfs('W', i, j)
                'B' -> bfs('B', i, j)
                else -> continue
            }
        }
    }
    println("$our $other")
}