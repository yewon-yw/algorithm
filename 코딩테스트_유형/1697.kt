import java.util.LinkedList

const val MAX = 100_000
fun main() {
    val (n, k) = readln().split(' ').map { it.toInt() }
    val q = LinkedList<Pair<Int, Int>>()
    val visited = BooleanArray(MAX + 1)

    fun visit(next: Int, depth: Int) {
        if (next in 0..MAX && !visited[next]) {
            q.add(next to depth)
            visited[next] = true
        }
    }

    fun bfs(): Int {
        visit(n, 0)
        while (q.isNotEmpty()) {
            val (top, depth) = q.poll()
            if (top == k) return depth
            visit(top * 2, depth + 1)
            visit(top + 1, depth + 1)
            visit(top - 1, depth + 1)
        }
        return k - n
    }

    when {
        n < k -> println(bfs())
        else -> println(n - k)
    }
}