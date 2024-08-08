import java.util.Stack

fun main() = with(System.`in`.bufferedReader()) {
    val (n, m) = readLine().split(' ').map { it.toInt() }
    val visited = BooleanArray(n + 1) { false }
    val s = Stack<Int>()

    fun dfs(count: Int) {
        if (count == m) {
            for (e in s) {
                print("$e ")
            }
            println()
            return
        }
        for (i in 1..n) {
            if (!visited[i]) {
                s.push(i)
                visited[i] = true
                dfs(count+1)
                s.pop()
                visited[i] = false
            }
        }
    }

    dfs(0)
}