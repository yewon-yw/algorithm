package part2

fun main() = with(System.`in`.bufferedReader()) {
    val (h, w) = readLine().split(' ').map { it.toInt() }
    val block = readLine().split(' ').map { it.toInt() }
    val world = Array(h) { IntArray(w) }
    var result = 0
    for (i in block.indices) {
        for (j in 0..<block[i]) {
            world[j][i] = 1
        }
    }
    for (i in 0..<h) {
        // 한 행(h)에서 w 인덱스의 min, max 값 찾고, 그 안에 있는 world[i][j] == 0 인 값 갯수 세기
        var temp = 0
        var min = w - 1
        var max = 0
        for (j in 0..<w) {
            if (world[i][j] == 1) {
                if (j < min) min = j
                if (j > max) max = j
            }
        }
        for (j in min + 1..<max) {
            if (world[i][j] == 0) temp++
        }
        result += temp
    }
    println(result)
}