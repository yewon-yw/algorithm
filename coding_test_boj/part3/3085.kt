package part3

import kotlin.math.max

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val candy = Array(n) { CharArray(n) }
    var max = 1
    for (i in 0..<n) {
        candy[i] = readLine().toCharArray()
    }
    fun maxCount() {
        for (i in 0..<n) {
            var wCount = 1
            var hCount = 1
            for (j in 0..<n - 1) {
                if (candy[i][j] == candy[i][j + 1]) wCount++
                else wCount = 1
                if (candy[j][i] == candy[j + 1][i]) hCount++
                else hCount = 1
                max = max(max(max, wCount), hCount)
            }
        }
    }
    for (i in 0..<n) {
        for (j in 0..<n - 1) {
            if (candy[i][j] == candy[i][j + 1]) continue
            val temp = candy[i][j]
            candy[i][j] = candy[i][j + 1]
            candy[i][j + 1] = temp
            maxCount()
            candy[i][j + 1] = candy[i][j]
            candy[i][j] = temp
        }
    }
    for (i in 0..<n) {
        for (j in 0..<n - 1) {
            if (candy[j][i] == candy[j + 1][i]) continue
            val temp = candy[j][i]
            candy[j][i] = candy[j + 1][i]
            candy[j + 1][i] = temp
            maxCount()
            candy[j + 1][i] = candy[j][i]
            candy[j][i] = temp
        }
    }
    println(max)
}