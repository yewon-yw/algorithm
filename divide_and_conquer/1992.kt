package boj

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val quadTree = StringBuilder()
    val video = Array(n) { IntArray(n) }

    fun checkIsSame(n: Int, x: Int, y: Int): Boolean {
        val isSame = video[x][y]
        for (i in x..<x + n) {
            for (j in y..<y + n) {
                if (isSame != video[i][j]) return false
            }
        }
        return true
    }

    fun daq(n: Int, x: Int, y: Int) {
        if (n == 1) {
            quadTree.append(video[x][y])
            return
        }
        if (checkIsSame(n, x, y)) {
            quadTree.append(video[x][y])
            return
        }
        val nextN = n / 2
        quadTree.append('(')
        daq(nextN, x, y)
        daq(nextN, x, y + nextN)
        daq(nextN, x + nextN, y)
        daq(nextN, x + nextN, y + nextN)
        quadTree.append(')')
    }

    repeat(n) { i ->
        video[i] = readLine().chunked(1).map { it.toInt() }.toIntArray()
    }
    daq(n, 0, 0)
    println(quadTree)
}