package codility

import kotlin.math.*
fun solution_CountFactors(N: Int): Int {
    var count = 0
    val sq = sqrt(N.toDouble()).toInt()
    for(i in 1..sq) {
        if(N % i == 0) count++
    }
    return count * 2 + if(sq * sq == N) -1 else 0
}