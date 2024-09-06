package programmers

import kotlin.math.max

class Solution5 {
    fun solution(sizes: Array<IntArray>): Int {
        var maxWidth = 0
        var maxHeight = 0
        sizes.forEach {
            val size = it.sorted()
            maxWidth = max(maxWidth, size[0])
            maxHeight = max(maxHeight, size[1])
        }
        return maxWidth * maxHeight
    }
}