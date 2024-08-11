package part2

fun main() = with(System.`in`.bufferedReader()) {
    val (n, k) = readLine().split(' ').map { it.toInt() }
    val usage = readLine().split(' ').map { it.toInt() }
    val multitap = mutableSetOf<Int>()
    var count = 0

    fun opt(start: Int, product: Int): Int {
        for (i in start..<k) {
            if (usage[i] == product) return i
        }
        return -1
    }

    for (i in usage.indices) {
        if (multitap.contains(usage[i])) continue
        if (multitap.size < n) {
            multitap.add(usage[i])
        } else {
            var last = 0
            var remove = 0

            for (product in multitap) {
                val index = opt(i + 1, product)
                if (index == -1) {
                    remove = product
                    break
                }
                if (index > last) {
                    last = index
                    remove = product
                }
            }
            multitap.remove(remove)
            count++
            multitap.add(usage[i])
        }
    }
    println(count)
}