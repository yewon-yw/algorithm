fun main() {
    var n = readln().toInt()
    var cnt = 1
    while (n > 1) {
        n -= 6 * cnt
        cnt++
    }
    println(cnt)
}