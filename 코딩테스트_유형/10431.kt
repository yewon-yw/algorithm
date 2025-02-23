private const val N = 20
fun main() = with(System.`in`.bufferedReader()) {
    val p = readLine().toInt()

    repeat(p) {
        val case = readLine().split(' ').map { it.toInt() }
        val (num, line) = case[0] to case.subList(1, N + 1).toMutableList()
        val sorted = line.sorted()
        var result = 0

        while (line != sorted) {
            for (i in 0..<N) {
                var minIdx = N
                val current = line[i]
                for (j in 0..<i) {
                    if (current < line[j]) {
                        minIdx = j
                        break
                    }
                }
                if (minIdx != N) {
                    line.removeAt(i)
                    line.add(minIdx, current)
                    result += i - minIdx
                }
            }
        }
        println("$num $result")
    }
}