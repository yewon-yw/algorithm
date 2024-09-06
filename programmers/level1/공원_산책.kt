class Solution3 {
    fun solution(park: Array<String>, routes: Array<String>): IntArray {
        var answer = IntArray(2)
        val h = park.size
        val w = park[0].length
        park.forEachIndexed{ i, p ->
            p.forEachIndexed { j, _ ->
                if(p[j] == 'S') {
                    answer[0] = i; answer[1] = j
                }
            }
        }

        val directionMap = mapOf(
            "N" to Pair(-1, 0),
            "S" to Pair(1, 0),
            "W" to Pair(0, -1),
            "E" to Pair(0, 1)
        )
        nextRoute@ for (route in routes) {
            val r = route.split(' ')
            val op = r[0]
            val n = r[1].toInt()
            val (dh, dw) = directionMap[op]?: continue@nextRoute

            for(i in 1..n) {
                val nh = answer[0] + dh * i
                val nw = answer[1] + dw * i

                if(nh < 0 || nw < 0 || nh >= h || nw >= w || park[nh][nw] == 'X') continue@nextRoute
            }

            answer[0] += dh * n
            answer[1] += dw * n
        }
        return answer
    }
}