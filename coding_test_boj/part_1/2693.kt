package basic

fun main() = with(System.`in`.bufferedReader()) {
    val t = readLine().toInt()
    repeat(t) {
        val arr = readLine().split(' ').map { it.toInt() }.toIntArray()
        arr.sortDescending()
        println(arr[2])
    }
}