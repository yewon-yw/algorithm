package boj

fun main() = with(System.`in`.bufferedReader()) {
    val (n, m) = readLine().split(' ').map { it.toInt() }
    val words = mutableMapOf<String, Int>()
    val bw = System.out.bufferedWriter()
    repeat(n) {
        val word = readLine()
        if (word.length >= m) {
            words[word] = (words[word] ?: 0) + 1
        }
    }
    val dic = words.toList().sortedWith(compareByDescending<Pair<String, Int>> { it.second }
        .thenByDescending { it.first.length }.thenBy { it.first })
    dic.forEach {
        bw.write("${it.first}\n")
    }
    bw.flush()
}