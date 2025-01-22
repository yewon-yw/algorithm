package boj

import java.util.LinkedList
import java.util.Queue

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val q: Queue<Int> = LinkedList()
    val parent = IntArray(n + 1)
    val visited = BooleanArray(n + 1)
    val graph = Array(n + 1) { LinkedList<Int>() }

    repeat(n - 1) {
        val (first, second) = readLine().split(' ').map { it.toInt() }
        graph[first].add(second)
        graph[second].add(first)
    }
    q.add(1)
    visited[1] = true

    while (q.isNotEmpty()) {
        val node = q.poll()
        graph[node].forEach {
            if (!visited[it]) {
                q.add(it)
                visited[it] = true
                parent[it] = node
            }
        }
    }

    for (i in 2..n) {
        println(parent[i])
    }
}