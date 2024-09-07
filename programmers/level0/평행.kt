package programmers

class Solution10 {
    fun solution(dots: Array<IntArray>): Int {
        var answer: Int = 0
        fun getGrade(dot1: IntArray, dot2: IntArray): Double {
            val dx = dot2[0] - dot1[0]
            val dy = dot2[1] - dot1[1]
            return dy/dx.toDouble()
        }
        answer = if (
            getGrade(dots[0], dots[1]) == getGrade(dots[2], dots[3]) ||
            getGrade(dots[0], dots[2]) == getGrade(dots[1], dots[3]) ||
            getGrade(dots[0], dots[3]) == getGrade(dots[1], dots[2])
        ) 1 else 0
        return answer
    }
}