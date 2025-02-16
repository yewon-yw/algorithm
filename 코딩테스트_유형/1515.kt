package boj

import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    val q: Queue<Char> = LinkedList()
    readLine().forEach {
        q.add(it)
    }
    var num = 0
    while (q.isNotEmpty()) {
        num++
        num.toString().forEach {
            if (q.isNotEmpty() && it == q.peek()) q.poll()
        }
    }
    println(num)
}