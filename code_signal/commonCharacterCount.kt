package codesignal

fun solution8(s1: String, s2: String): Int {
    val alphabet = Array(2) { IntArray(26) }
    for(c in s1) alphabet[0][c.code - 97]++
    for(c in s2) alphabet[1][c.code - 97]++
    var common = 0
    for(i in alphabet[0].indices) {
        common += minOf(alphabet[0][i], alphabet[1][i])
    }
    return common
}
