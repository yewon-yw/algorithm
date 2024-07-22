fun main() {
    val str = readln().uppercase()
    val count = IntArray(26)
    for (c in str) {
        count[c.code - 65]++
    }

    val maxCount = count.max()
    val maxIndex = count.withIndex().filter { it.value == maxCount }.map { it.index }

    if (maxIndex.size > 1) println("?")
    else println((maxIndex[0] + 65).toChar())
}