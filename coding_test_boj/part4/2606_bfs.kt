package part4

import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val k = readLine().toInt()
    val computers = Array(n + 1) { BooleanArray(n + 1) }
    val q: Queue<Int> = LinkedList()
    val visited = BooleanArray(n + 1)
    repeat(k) {
        val (s, e) = readLine().split(' ').map { it.toInt() }
        computers[s][e] = true
        computers[e][s] = true
    }

    fun bfs() {
        q.add(1)
        visited[1] = true
        while (q.isNotEmpty()) {
            val top = q.poll()
            for (i in 1..n) {
                if (computers[top][i] && !visited[i]) {
                    visited[i] = true
                    q.add(i)
                }
            }
        }
    }
    bfs()
    val count = visited.filter { it }.size - 1
    println(count)
}