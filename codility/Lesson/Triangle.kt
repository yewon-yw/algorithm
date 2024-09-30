package codility

fun solution_Triangle(A: IntArray): Int {
    val s = A.sorted()
    for(i in 0..s.size-3) {
        val case1: Long = s[i].toLong() + s[i+1]
        val case2: Long = s[i+1].toLong() + s[i+2]
        val case3: Long = s[i+2].toLong() + s[i]
        if(case1 > s[i+2] && case2 > s[i] && case3 > s[i+1]) return 1
    }
    return 0
}