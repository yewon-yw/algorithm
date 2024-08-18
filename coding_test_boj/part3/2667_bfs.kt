package part3

import java.util.LinkedList

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val map = Array(n + 2) { BooleanArray(n + 2) }
    val house = mutableListOf<Int>()
    val q = LinkedList<Pair<Int, Int>>()
    for (i in 1..n) {
        val input = readLine()
        for (j in 1..n) {
            map[i][j] = input[j - 1] != '0'
        }
    }

    fun push(i: Int, j: Int) {
        map[i][j] = false
        q.push(i to j)
    }

    fun bfs() {
        var count = 0
        while (q.isNotEmpty()) {
            count++
            val next = q.poll()
            val i = next.first
            val j = next.second
            if (map[i + 1][j]) push(i + 1, j)
            if (map[i - 1][j]) push(i - 1, j)
            if (map[i][j + 1]) push(i, j + 1)
            if (map[i][j - 1]) push(i, j - 1)
        }
        house.add(count)
    }

    for (i in 1..n) {
        for (j in 1..n) {
            if (map[i][j]) {
                push(i, j)
                bfs()
            }
        }
    }

    house.sort()
    println(house.size)
    for (h in house) {
        println(h)
    }
}