package codesignal

fun solution30(a: MutableList<Int>): Int {
    if(a.size < 2) return a[0]
    if(a.size % 2 == 0) return a[a.size/2 - 1]
    return a[a.size/2]
}
