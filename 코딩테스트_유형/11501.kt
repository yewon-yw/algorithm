package boj

fun main() = with(System.`in`.bufferedReader()) {
    val t = readLine().toInt()
    repeat(t) {
        val n = readLine().toInt()
        val days = readLine().split(' ').map { it.toInt() }
        var (maxPrice, profit) = 0 to 0L
        for (i in n-1 downTo 0) {
            if (maxPrice < days[i]) {
                maxPrice = days[i]
            } else {
                profit += maxPrice - days[i]
            }
        }
        println(profit)
    }
}