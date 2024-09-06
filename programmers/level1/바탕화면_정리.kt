package programmers

class Solution4 {
    fun solution(wallpaper: Array<String>): IntArray {
        var (lux, luy) = 50 to 50 // 최소 x, y 값
        var (rdx, rdy) = 0 to 0 // 최대 x, y 값
        wallpaper.forEachIndexed { x, line ->
            line.forEachIndexed { y, cell ->
                if (cell == '#') {
                    lux = if (x < lux) x else lux
                    luy = if (y < luy) y else luy
                    rdx = if (x + 1 > rdx) x + 1 else rdx
                    rdy = if (y + 1 > rdy) y + 1 else rdy
                }
            }
        }
        return intArrayOf(lux, luy, rdx, rdy)
    }
}