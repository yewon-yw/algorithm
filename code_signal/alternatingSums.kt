package codesignal

fun solution12(a: MutableList<Int>): MutableList<Int> {
    var (team1, team2) = 0 to 0
    for(i in a.indices) {
        if(i % 2 == 0) team1 += a[i]
        else team2 += a[i]
    }
    return mutableListOf(team1, team2)
}
