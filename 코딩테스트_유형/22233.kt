package boj

fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    val (n, m) = readLine().split(' ').map { it.toInt() }
    val keywords = mutableSetOf<String>()
    repeat(n) {
        keywords.add(readLine())
    }
    repeat(m) {
        val written = readLine().split(',').toSet()
        keywords.removeAll(written)
        bw.write("${keywords.size}\n")
    }
    bw.flush()
}