fun main() = with(System.`in`.bufferedReader()) {
    val (n, k) = readLine().split(' ').map { it.toInt() }
    val table = readLine().toCharArray()
    val state = BooleanArray(table.size)
    var count = 0
    for (i in table.indices) {
        if (table[i] == 'H') continue
        for (j in i - k..i + k) {
            if (i == j || j < 0 || j >= n) continue
            if (!state[j] && table[j] == 'H') {
                state[j] = true
                count++
                break
            }
        }
    }
    println(count)
}