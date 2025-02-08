package boj

import java.util.*

const val INF = Int.MAX_VALUE

fun main() = with(System.`in`.bufferedReader()) {
    val (v, e) = readLine().split(' ').map { it.toInt() }
    val k = readLine().toInt()
    val edges = Array(v + 1) { mutableListOf<Pair<Int, Int>>() }
    val pq = PriorityQueue<Pair<Int, Int>>(compareBy { it.second }) // 노드, 최단거리
    val distance = IntArray(v + 1) { INF }

    repeat(e) {
        val (sv, ev, w) = readLine().split(' ').map { it.toInt() }
        edges[sv].add(ev to w)
    }

    pq.add(k to 0)
    distance[k] = 0

    while (pq.isNotEmpty()) {
        val curNode = pq.poll().first
        edges[curNode].forEach { (nextNode, w) ->
            if (distance[nextNode] > distance[curNode] + w) {
                distance[nextNode] = distance[curNode] + w
                pq.add(nextNode to distance[nextNode])
            }
        }
    }

    for (i in 1..v) {
        println(if (distance[i] == INF) "INF" else distance[i])
    }
}
