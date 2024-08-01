package basic

// 일곱 난쟁이
fun main() = with(System.`in`.bufferedReader()) {
    val heights = mutableListOf<Int>()
    repeat(9) {
        heights.add(readLine().toInt())
    }
    val remove = heights.sum() - 100
    find@ for (i in heights) {
        for (j in heights) {
            if (i == j) continue
            if (i + j == remove) {
                heights.remove(i); heights.remove(j)
                break@find
            }
        }
    }
    heights.sort()
    heights.forEach {
        println(it)
    }
}