fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val switch = readLine().split(' ').map { it == "1" }.toMutableList()

    repeat(readLine().toInt()) {
        val (gender, num) = readLine().split(' ').map { it.toInt() }
        when (gender) {
            1 -> {
                (num - 1..<n step num).forEach {
                    switch[it] = !switch[it]
                }
            }

            else -> {
                val idx = num - 1
                switch[idx] = !switch[idx]
                for (i in 1..n / 2) {
                    if (idx - i < 0 || idx + i >= n || switch[idx - i] xor switch[idx + i]) break
                    switch[idx - i] = !switch[idx - i]
                    switch[idx + i] = !switch[idx + i]
                }
            }
        }
    }

    switch.chunked(20).forEach {
        println(it.joinToString(" ") { "${if (it) 1 else 0}" })
    }
}