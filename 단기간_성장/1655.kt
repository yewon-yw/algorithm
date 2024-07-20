import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.PriorityQueue

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val minHeap = PriorityQueue<Int>()
    val maxHeap = PriorityQueue<Int>(reverseOrder())
    val sb = StringBuilder()

    for (i in 0..<n) {
        val k = br.readLine().toInt()
        if (maxHeap.isNotEmpty() && maxHeap.peek() < k) { // max ~ min 순
            minHeap.offer(k)
        } else {
            maxHeap.offer(k)
        }

        if (maxHeap.size - minHeap.size > 1) {
            minHeap.offer(maxHeap.poll())
        } else if (minHeap.size > maxHeap.size) {
            maxHeap.offer(minHeap.poll())
        }
        sb.append("${maxHeap.peek()}\n")
    }
    println(sb)
    br.close()
}