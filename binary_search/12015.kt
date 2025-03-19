fun findIndex(lis: List<Int>, target: Int): Int {
    var (s, e) = 0 to lis.size - 1
    while (s <= e) {
        val m = (s + e) / 2
        if (lis[m] < target) s = m + 1
        else e = m - 1
    }
    return s
}

fun main() = with(System.`in`.bufferedReader()) {
    readLine()
    val arr = readLine().split(' ').map { it.toInt() }
    val lis = mutableListOf(arr[0])
    for (i in 1..<arr.size) {
        if (lis.last() < arr[i]) lis.add(arr[i])
        else {
            val idx = findIndex(lis, arr[i])
            lis[idx] = arr[i]
        }
    }
    println(lis.size)
}