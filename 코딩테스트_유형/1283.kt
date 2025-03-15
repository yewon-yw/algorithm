fun step(i: Int, j: Int, words: MutableList<String>, keys: BooleanArray): Boolean {
    val idx = words[i][j].uppercaseChar() - 'A'
    if (keys[idx]) return false
    words[i] = words[i].substring(0, j) + "[${words[i][j]}]" + words[i].substring(j + 1)
    keys[idx] = true
    return true
}

fun main() = with(System.`in`.bufferedReader()) {
    val keys = BooleanArray(26)
    repeat(readLine().toInt()) {
        val words = readLine().split(' ').toMutableList()
        var nextStep = true

        for (i in words.indices) {
            if (step(i, 0, words, keys)) {
                nextStep = false
                break
            }
        }
        if (nextStep) {
            step@ for (i in words.indices) {
                for (j in words[i].indices) {
                    if (step(i, j, words, keys)) break@step
                }
            }
        }
        println(words.joinToString(" "))
    }
}