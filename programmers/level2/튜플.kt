package programmers

class Solution18 {
    fun solution1(s: String): IntArray {
        val result = mutableListOf<Int>()
        var str = s.substring(1, s.length - 1)
        var sb = StringBuilder(str)
        var isIn = false
        for (i in str.indices) {
            when (str[i]) {
                '{' -> isIn = true
                '}' -> isIn = false
                ',' -> {
                    if (!isIn) sb[i] = ' '
                }

                else -> {}
            }
        }
        val list = sb.split(' ')
            .map {
                it.substring(1, it.length - 1)
                    .split(',')
                    .map { it.toInt() }
                    .toSet()
            }
            .sortedBy { it.size }
        list.forEachIndexed { idx, item ->
            if (idx == 0) result.add(item.first())
            else result.add((item - list[idx - 1]).first())
        }
        return result.toIntArray()
    }

    fun solution2(s: String): IntArray {
        val answer = mutableListOf<Int>()
        val list = s.substring(2, s.length - 2)
            .split("},{")
            .sortedBy { it.length }
            .map {
                it.split(',').map { it.toInt() }.toSet()
            }
        list.forEachIndexed { idx, item ->
            if (idx == 0) answer.add(item.first())
            else answer.add((item - list[idx - 1]).first())
        }
        return answer.toIntArray()
    }
}