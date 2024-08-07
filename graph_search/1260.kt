import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    val (n, m, v) = readLine().split(' ').map { it.toInt() }
    val edges = Array<MutableList<Int>>(n + 1) { mutableListOf() }
    val isVisited = Array(n + 1) { false }
    val q: Queue<Int> = LinkedList()
    repeat(m) {
        val (start, end) = readLine().split(' ').map { it.toInt() }
        edges[start].add(end)
        edges[end].add(start)
    }
    for (list in edges) {
        list.sort()
    }

    fun dfs(start: Int) {
        print("$start ")
        isVisited[start] = true
        for (next in edges[start]) {
            if (!isVisited[next]) {
                dfs(next)
            }
        }
    }

    fun bfs(start: Int) {
        q.add(start)
        isVisited[start] = true
        while (q.isNotEmpty()) {
            for (next in edges[q.peek()]){
                if (!isVisited[next]) {
                    q.add(next)
                    isVisited[next] = true
                }
            }
            print("${q.poll()} ")
        }
    }

    dfs(v)
    isVisited.fill(false)
    println()
    bfs(v)
}