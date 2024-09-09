package codesignal

fun solution26(inputString: String): String {
    val sb = StringBuilder()
    inputString.forEachIndexed { i, c ->
        val nextAlphabet = ((c.code - 97 + 1) % 26 + 97).toChar()
        sb.append(nextAlphabet)
    }
    return sb.toString()
}
