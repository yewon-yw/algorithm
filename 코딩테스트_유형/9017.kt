package boj

//fun findDisableTeam(input: List<Int>): Set<Int> {
//    val enable = mutableMapOf<Int, Int>()
//    input.forEach {
//        enable[it] = (enable[it] ?: 0) + 1
//    }
//    return enable.filter { it.value < 6 }.keys.toSet()
//}
//
//fun main() = with(System.`in`.bufferedReader()) {
//    val t = readLine().toInt()
//    val bw = System.out.bufferedWriter()
//    repeat(t) {
//        readLine()
//        val input = readLine().split(' ').map { it.toInt() }
//        val disableTeam = findDisableTeam(input)
//        val team = Array(input.max()) { 0 to Triple(0, 0, 0) } // team number / member, score, fifth
//        var rank = 0
//        for (i in input) {
//            if (disableTeam.contains(i)) continue
//            rank++
//            val member = team[i - 1].second.first + 1
//            val score = if (member <= 4) team[i - 1].second.second + rank else team[i - 1].second.second
//            val fifth = if (member == 5) rank else team[i - 1].second.third
//            team[i - 1] = i to Triple(member, score, fifth)
//        }
//        val result = team.filter { it.second.first == 6 }
//            .sortedWith(compareBy<Pair<Int, Triple<Int, Int, Int>>> { it.second.second }
//                .thenBy { it.second.third })[0].first
//        bw.write("$result\n")
//    }
//    bw.flush()
//}

fun main() = with(System.`in`.bufferedReader()) {
    val t = readLine().toInt()
    repeat(t) {
        readLine()
        val input = readLine().split(' ').map { it.toInt() }
        val teamRanks = mutableMapOf<Int, MutableList<Int>>() // team Number, ranks
        val members = mutableMapOf<Int, Int>() // team member count
        input.forEach {
            members[it] = (members[it] ?: 0) + 1
        }
        val validTeam = members.filterValues { it == 6 }.keys
        var rank = 1
        for (teamNum in input) {
            if (!validTeam.contains(teamNum)) continue
            teamRanks.getOrPut(teamNum) { mutableListOf() }.add(rank)
            rank++
        }
        val teamScore = teamRanks.mapValues { it.value.take(4).sum() }
        val minScore = teamScore.minOfOrNull { it.value }
        val candidates = teamScore.filterValues { it == minScore }.keys
        val winner = candidates.minByOrNull { teamRanks[it]!![4] }!!
        println(winner)
    }
}