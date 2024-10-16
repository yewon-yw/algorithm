fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val paper = Array(n) { IntArray(n) }
    var (whiteCount, blueCount) = 0 to 0
    repeat(n) {i ->
        paper[i] = readLine().split(" ").map{ it.toInt() }.toIntArray()
    }

    fun rec(x: Int, y: Int, n: Int) {
        var (isWhite, isBlue) = true to true
        for(i in x until x + n) {
            for(j in y until y + n) {
                if(paper[i][j] == 1) isWhite = false
                else isBlue = false
            }
        }

        if (isWhite) {
            whiteCount++
            return
        } else if (isBlue) {
            blueCount++
            return
        }
        if(n == 1) return

        val divN = n/2
        rec(x, y, divN)
        rec(x + divN, y, divN)
        rec(x, y + divN, divN)
        rec(x + divN, y + divN, divN)
    }

    rec(0, 0, n)
    println(whiteCount)
    println(blueCount)
}
