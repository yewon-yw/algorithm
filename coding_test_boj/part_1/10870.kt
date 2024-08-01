package basic

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    println(fib(n))
}

fun fib(n: Int): Int {
    if (n < 2) return n
    return fib(n - 1) + fib(n - 2)
}