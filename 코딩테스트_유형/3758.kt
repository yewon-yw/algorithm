fun main() = with(System.`in`.bufferedReader()) {
    repeat(readLine().toInt()) {
        val (n, k, t, m) = readLine().split(' ').map { it.toInt() }
        val score = Array(n) { IntArray(k) }
        val count = IntArray(n)
        val time = IntArray(n)
        repeat(m) { idx ->
            val (i, j, s) = readLine().split(' ').map { it.toInt() }
            score[i - 1][j - 1] = maxOf(score[i - 1][j - 1], s)
            count[i - 1]++
            time[i - 1] = idx
        }
        println((0..<n).sortedWith(compareByDescending<Int> { score[it].sum() }.thenBy { count[it] }
            .thenBy { time[it] }).indexOf(t-1) + 1)
    }
}

//fun main() = with(System.`in`.bufferedReader()) {
//    repeat(readLine().toInt()) {
//        val (n, k, t, m) = readLine().split(' ').map { it.toInt() }
//        val log = mutableMapOf<Int, Triple<Int, Int, Int>>()
//        val score = Array(n) { IntArray(k) }
//        repeat(m) {
//            val (i, j, s) = readLine().split(' ').map { it.toInt() }
//            if (score[i - 1][j - 1] < s) score[i - 1][j - 1] = s
//            val l = log.getOrPut(i - 1) { Triple(0, 0, 0) }
//            log[i - 1] = Triple(l.first, l.second + 1, it)
//        }
//        repeat(n) {
//            val l = log.getOrPut(it) { Triple(0, 0, 0) }
//            log[it] = Triple(score[it].sum(), l.second, l.third)
//        }
//        val rank = log.toList().sortedWith(compareByDescending<Pair<Int, Triple<Int, Int, Int>>> { it.second.first }
//            .thenBy { it.second.second }.thenBy { it.second.third })
//        rank.forEachIndexed { idx, team ->
//            if (team.first + 1 == t) println(idx + 1)
//        }
//    }
//}