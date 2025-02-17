package boj

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val words = mutableListOf<String>()
    var count = 0
    repeat(n) {
        words.add(readLine())
    }

    val std = IntArray(26)
    words[0].forEach {
        std[it - 'A']++
    }

    for (i in 1..<n) {
        val alphabet = IntArray(26)
        var result = true
        var (pos, neg) = 0 to 0
        words[i].forEach {
            alphabet[it - 'A']++
        }
        for (k in 0..<26) {
            when (std[k] - alphabet[k]) {
                0 -> continue
                1 -> pos++
                -1 -> neg++
                else -> result = false
            }
        }
        if (result && pos <= 1 && neg <= 1) count++
    }
    println(count)
}