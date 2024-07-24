fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuffer()
    val n = br.readLine().toInt()
    val s = IntArray(21)
    repeat(n) {
        val input = br.readLine()
        val (cmd, x) = if (input == "all" || input == "empty") {
            input to -1
        } else {
            input.split(" ").let { it[0] to it[1].toInt() }
        }
        when (cmd) {
            "add" -> s[x] = 1
            "remove" -> s[x] = 0
            "check" -> sb.append("${s[x]}\n")
            "toggle" -> s[x] = if (s[x] == 0) 1 else 0
            "all" -> { s.fill(1) }
            "empty" -> { s.fill(0) }
        }
    }
    println(sb)
    br.close()
}