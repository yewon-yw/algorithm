package basic

// 최소, 최대
fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val arr = readLine().split(' ').map { it.toInt() }.toIntArray()
    println("${arr.min()} ${arr.max()}")
}