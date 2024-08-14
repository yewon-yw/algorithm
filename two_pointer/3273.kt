fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val seq = readLine().split(' ').map { it.toInt() }.sortedDescending()
    val x = readLine().toInt()
    var first = 0
    var second = n - 1
    var count = 0
    while (first < n) {
        if (first >= second) break
        val sum = seq[first] + seq[second]
        if (sum == x) count++
        if (sum < x) second--
        else first++
    }
    println(count)
}