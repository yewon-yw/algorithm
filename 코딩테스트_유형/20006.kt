fun main() = with(System.`in`.bufferedReader()) {
    val (p, m) = readLine().split(' ').map { it.toInt() }
    val rooms = mutableListOf<MutableList<Pair<Int, String>>>()
    repeat(p) {
        val input = readLine().split(' ')
        val (level, nickname) = input[0].toInt() to input[1]
        val room = rooms.find { it.size < m && level in (it.first().first - 10..it.first().first + 10) }
        if (room == null) {
            rooms.add(mutableListOf(level to nickname))
        } else {
            room.add(level to nickname)
        }
    }
    for (room in rooms) {
        room.sortBy { it.second }
        println(if (room.size == m) "Started!" else "Waiting!")
        println(room.joinToString("\n") { "${it.first} ${it.second}" })
    }
}