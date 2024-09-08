package codesignal

fun solution4(statues: MutableList<Int>): Int {
    var count = 0
    statues.sort()
    for(i in statues[0] until statues[statues.size-1]) {
        if(!statues.contains(i)) count++
    }
    return count
}
