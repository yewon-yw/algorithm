fun main() = with(System.`in`.bufferedReader()) {
    val (n, game) = readLine().split(' ')
    val players = mutableSetOf<String>()
    repeat(n.toInt()) {
        players.add(readLine())
    }
    println(
        players.size /
                when (game) {
                    "Y" -> 1
                    "F" -> 2
                    else -> 3
                }
    )
}