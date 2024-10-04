package codility

import kotlin.math.*

fun solution_AbsDistinct(A: IntArray): Int {
    val absolute = A.map { abs(it) }.distinct()
    return absolute.size
}