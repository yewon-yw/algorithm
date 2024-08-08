package part2

const val MAX = 1_000_000_000
const val MIN = -1_000_000_000
fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val num = readLine().split(' ').map { it.toInt() }
    val op = readLine().split(' ').map { it.toInt() }.toIntArray()
    var max = MIN
    var min = MAX

    fun dfs(count: Int, temp: Int, opIndex: Int) {
        val result = when (opIndex) {
            0 -> temp + num[count]
            1 -> temp - num[count]
            2 -> temp * num[count]
            3 -> temp / num[count]
            else -> temp
        }
        if (count == n - 1) {
            if (result > max) max = result
            if (result < min) min = result
            return
        }
        for (i in op.indices) {
            if (op[i] != 0) {
                op[i]--
                dfs(count + 1, result, i)
                op[i]++
            }
        }
    }
    dfs(0, num[0], -1)
    println(max)
    println(min)
}