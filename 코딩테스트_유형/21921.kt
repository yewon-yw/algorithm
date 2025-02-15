package boj

fun main() = with(System.`in`.bufferedReader()) {
    val (n, x) = readLine().split(' ').map { it.toInt() }
    val today = readLine().split(' ').map { it.toInt() }
    val visitor = mutableListOf<Int>()
    val sum = IntArray(n + 1)

    for (i in 1..n) {
        sum[i] = sum[i - 1] + today[i - 1]
    }
    for (i in x..n) {
        visitor.add(sum[i] - sum[i - x])
    }
    val max = visitor.max()
    if (max == 0) {
        println("SAD")
    } else {
        println(max)
        println(visitor.count { it == max })
    }
}