package codesignal

fun solution14(a: MutableList<Int>, b: MutableList<Int>): Boolean {
    var count = 0
    if(a.sorted() != b.sorted()) return false
    for(i in a.indices) {
        if(a[i] != b[i]) count++
    }
    return if(count>2) false else true
}