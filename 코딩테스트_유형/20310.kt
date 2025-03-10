fun main() = with(System.`in`.bufferedReader()) {
    val s = readLine()
    var o = s.count { it == '1' }
    var (hz, ho) = s.count { it == '0' } / 2 to o / 2
    val sb = StringBuilder()
    s.forEach {
        when (it) {
            '0' -> {
                if (hz > 0) {
                    sb.append(it)
                    hz--
                }
            }

            else -> {
                if (o == ho) {
                    sb.append(it)
                    ho--
                }
                o--
            }
        }
    }
    println(sb)
}