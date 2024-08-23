package part3

enum class Direction {
    HORIZONTAL, VERTICAL, DIAGONAL
}

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val house = Array(n) { IntArray(n) }
    var count = 0
    repeat(n) { i ->
        house[i] = readLine().split(' ').map { it.toInt() }.toIntArray()
    }

    fun dfs(h: Int, v: Int, prevDir: Direction) {
        if (h >= n || v >= n || house[h][v] == 1) return
        // 대각선은 3칸을 차지하기 때문에 추가적으로 확인
        if (prevDir == Direction.DIAGONAL && (house[h - 1][v] == 1 || house[h][v - 1] == 1)) return
        if (h == n - 1 && v == n - 1) {
            count++
            return
        }
        when (prevDir) {
            Direction.HORIZONTAL -> {
                // 가로, 대각선
                dfs(h, v + 1, Direction.HORIZONTAL)
                dfs(h + 1, v + 1, Direction.DIAGONAL)
            }

            Direction.VERTICAL -> {
                // 세로, 대각선
                dfs(h + 1, v, Direction.VERTICAL)
                dfs(h + 1, v + 1, Direction.DIAGONAL)
            }

            Direction.DIAGONAL -> {
                // 가로, 세로, 대각선
                dfs(h, v + 1, Direction.HORIZONTAL)
                dfs(h + 1, v, Direction.VERTICAL)
                dfs(h + 1, v + 1, Direction.DIAGONAL)
            }

        }
    }
    dfs(0, 1, Direction.HORIZONTAL)
    println(count)
}