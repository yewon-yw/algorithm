package basic

// 지능형 기차 2
fun main() = with(System.`in`.bufferedReader()) {
    val platform = IntArray(11)
    for (i in 1..10) {
        val (off, on) = readLine().split(' ').map { it.toInt() }
        platform[i] = platform[i - 1] + on - off
    }
    println(platform.max())
}