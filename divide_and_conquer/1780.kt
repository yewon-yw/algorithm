package boj

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val paper = Array(n) { IntArray(n) }
    val result = IntArray(3)

    repeat(n) { i ->
        paper[i] = readLine().split(' ').map { it.toInt() }.toIntArray()
    }

    fun isSame(size: Int, r: Int, c: Int): Boolean {
        val std = paper[r][c]
        for (i in r..<r + size) {
            for (j in c..<c + size) {
                if (paper[i][j] != std) return false
            }
        }
        return true
    }

    fun rec(size: Int, r: Int, c: Int) {
        if (isSame(size, r, c)) {
            result[paper[r][c] + 1]++
        } else {
            val nextSize = size / 3
            repeat(3) { i ->
                repeat(3) { j ->
                    rec(nextSize, r + i * nextSize, c + j * nextSize)
                }
            }
        }
    }

    rec(n, 0, 0)
    println(result.joinToString("\n"))
}