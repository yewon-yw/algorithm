fun main() {
    val (h, w, n, m) = readln().split(' ').map { it.toLong() }
    val height = (h + n) / (n + 1)
    val width = (w + m) / (m + 1)
    println(width * height)
}