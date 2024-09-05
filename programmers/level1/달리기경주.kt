class Solution {
    fun solution(players: Array<String>, callings: Array<String>): Array<String> {
        val rank = mutableMapOf<String, Int>()
        players.forEachIndexed { index, player ->
            rank[player] = index
        }
        callings.forEachIndexed { index, player ->
            val currentRank = rank[player]?: 0
            val prevRank = currentRank - 1

            val t = players[prevRank]
            players[prevRank] = players[currentRank]
            players[currentRank] = t

            rank[player] = prevRank
            rank[t] = currentRank
        }
        return players
    }
}