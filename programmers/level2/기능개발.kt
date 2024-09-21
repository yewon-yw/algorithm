import java.util.*
import kotlin.math.*
class Solution17 {
    // ceil(100 - progresses[i] / speed)일간 작업
    // queue 사용
    fun solution1(progresses: IntArray, speeds: IntArray): IntArray {
        val answer = mutableListOf<Int>()
        val period: Queue<Int> = LinkedList(progresses.mapIndexed { idx, p -> ceil((100 - p) / speeds[idx].toDouble()).toInt() })
        while(period.isNotEmpty()) {
            val top = period.poll()
            var count = 1
            while(period.isNotEmpty() && top >= period.peek()) {
                period.poll()
                count++
            }
            answer.add(count)
        }
        return answer.toIntArray()
    }

    // for문 사용
    fun solution2(progresses: IntArray, speeds: IntArray): IntArray {
        val answer = mutableListOf<Int>()
        val period = progresses.mapIndexed { idx, p -> ceil((100 - p) / speeds[idx].toDouble()).toInt() }
        var (std, count) = period[0] to 0
        for(i in period.indices) {
            if(period[i] <= std) count++
            else {
                answer.add(count)
                count = 1
                std = period[i]
            }
        }
        answer.add(count)
        return answer.toIntArray()
    }
}