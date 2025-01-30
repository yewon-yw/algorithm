package boj

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val line = IntArray(n)
    readLine().split(' ').map { it.toInt() }.forEachIndexed { idx, v ->
        var count = 0
        for (i in 0..<n) {
            if (line[i] == 0) {
                if (count == v) {
                    line[i] = idx + 1
                    break
                }
                count++
            }
        }
    }
    println(line.joinToString(" "))
}