package basic

// 이진수
fun main() = with(System.`in`.bufferedReader()) {
    val t = readLine().toInt()
    repeat(t) {
        var n = readLine().toInt()
        var i = 0
        while (n > 0) {
            if (n % 2 == 1) print("$i ")
            i++; n /= 2
        }
    }
}