package boj

import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    val num = readLine().split(' ').map { it.toInt() }.sorted()
    val visited = Array(1001) { BooleanArray(1001) }
    val q: Queue<Triple<Int, Int, Int>> = LinkedList()
    var result = false

    q.add(Triple(num[0], num[1], num[2]))
    visited[num[0]][num[1]] = true
    while (q.isNotEmpty()) {
        val (a, b, c) = q.poll()
        if (a == b && b == c) {
            result = true
            break
        }
        listOf(Triple(a, b, c), Triple(a, c, b), Triple(b, c, a)).forEach { (a, b, c) ->
            val (na, nb, nc) = listOf(a + a, b - a, c).sorted()
            if (!visited[na][nb]) {
                q.add(Triple(na, nb, nc))
                visited[na][nb] = true
            }
        }
    }
    println(if (result) 1 else 0)
}