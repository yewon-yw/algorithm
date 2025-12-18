import java.util.LinkedList

fun main() = with(System.`in`.bufferedReader()) {
    val (M, N, H) = readLine()!!.split(" ").map { it.toInt() }
    val box = Array(H) { Array(N) { IntArray(M) } }
    val q = LinkedList<Triple<Int, Int, Int>>() // h, n, m
    val offset = arrayOf(-1, 1, 0, 0, 0, 0)
    var days = 0

    repeat(H) { h ->
        repeat(N) { n ->
            val line = readLine().split(" ").map { it.toInt() }
            repeat(M) { m ->
                box[h][n][m] = line[m]
                if (box[h][n][m] == 1) q.add(Triple(h, n, m))
            }
        }
    }

    while (q.isNotEmpty()) {
        val (h, n, m) = q.pop()
        days = maxOf(days, box[h][n][m])

        for (i in 0..5) {
            val nh = h + offset[i]
            val nn = n + offset[(i + 4) % 6]
            val nm = m + offset[(i + 2) % 6]

            if (nh !in 0..<H || nn !in 0..<N || nm !in 0..<M) continue
            if (box[nh][nn][nm] == 0) {
                q.add(Triple(nh, nn, nm))
                box[nh][nn][nm] = box[h][n][m] + 1
            }
        }
    }

    for (h in 0..<H) {
        for (n in 0..<N) {
            if (box[h][n].any { it == 0 }) {
                println(-1)
                return
            }
        }
    }

    println(days - 1)
}