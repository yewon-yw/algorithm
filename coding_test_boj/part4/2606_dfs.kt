package part4

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val k = readLine().toInt()
    val computers = Array(n + 1) { BooleanArray(n + 1) }
    val visited = BooleanArray(n + 1)
    repeat(k) {
        val (s, e) = readLine().split(' ').map { it.toInt() }
        computers[s][e] = true
        computers[e][s] = true
    }

    fun dfs(start: Int) {
        if (visited[start]) return
        visited[start] = true
        for (i in 1..n) {
            if (computers[start][i]) {
                dfs(i)
            }
        }
    }
    dfs(1)
    val count = visited.filter { it }.size - 1
    println(count)
}