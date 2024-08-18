package part3

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val map = Array(n + 2) { BooleanArray(n + 2) }
    val house = mutableListOf<Int>()
    val xOffset = intArrayOf(-1, 1, 0, 0)
    val yOffset = intArrayOf(0, 0, -1, 1)
    var count = 0
    for (i in 1..n) {
        val input = readLine()
        for (j in 1..n) {
            map[i][j] = input[j - 1] != '0'
        }
    }

    fun dfs(i: Int, j: Int) {
        count++
        map[i][j] = false
        for (k in 0..3) {
            val x = i + xOffset[k]
            val y = j + yOffset[k]
            if (map[x][y]) {
                map[x][y] = false
                dfs(x, y)
            }
        }
    }

    for (i in 1..n) {
        for (j in 1..n) {
            if (map[i][j]) {
                dfs(i, j)
                house.add(count)
                count = 0
            }
        }
    }

    house.sort()
    println(house.size)
    for (h in house) {
        println(h)
    }
}