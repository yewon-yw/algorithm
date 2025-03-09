import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val q = PriorityQueue<Int>()
    repeat(n) {
        readLine().split(' ').map { it.toInt() }.forEach {
            if (q.size < n) q.add(it)
            else if (q.first() < it) {
                q.add(it)
                q.poll()
            }
        }
    }
    println(q.first())
}