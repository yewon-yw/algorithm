package programmers

class Solution7 {
    fun solution(n: Int): Array<IntArray> {
        var answer = Array(n) { IntArray(n) }
        val xdir = listOf(0, 1, 0, -1)
        val ydir = listOf(1, 0, -1, 0)
        var dir = 0
        var count = 1
        var num = n-1
        var (x, y) = 0 to -1
        for(i in 0 until n) {
            x += xdir[dir]
            y += ydir[dir]
            answer[x][y] = count++
        }
        dir++
        while(num>0) {
            repeat(2) {
                for(i in 0 until num) {
                    x += xdir[dir]
                    y += ydir[dir]
                    answer[x][y] = count++
                }
                dir = (dir+1) % 4
            }
            num--
        }
        return answer
    }
}