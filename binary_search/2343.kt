fun main() = with(System.`in`.bufferedReader()) {
    val (n, m) = readLine().split(' ').map { it.toInt() }
    val lesson = readLine().split(' ').map { it.toInt() }
    var start = lesson.max()
    var end = lesson.sum()
    var result = end

    while (start <= end) {
        val mid = (start + end) / 2
        var sum = 0
        var count = 1
        for (l in lesson) {
            if (sum + l > mid) {
                sum = l
                count++
            } else {
                sum += l
            }
        }

        if (count <= m) {
            result = mid
            end = mid - 1
        } else {
            start = mid + 1
        }
    }
    println(result)
}