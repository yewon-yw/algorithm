fun main() = with(System.`in`.bufferedReader()) {
    val (n, score, p) = readLine().split(' ').map { it.toInt() }
    val list = if (n > 0) readLine().split(' ').map { it.toInt() }.toMutableList() else mutableListOf<Int>()
    list.add(score)
    list.sortDescending()

    val rank = list.indexOf(score) + 1
    if (rank > p || (n == p && list.last() == score)) {
        println(-1)
    } else {
        println(rank)
    }
}