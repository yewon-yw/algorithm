import java.util.*

class Solution20 {
    fun solution(s: String): Int {
        var answer: Int = 0
        var enable = true
        val stack = Stack<Char>()
        val bracket = mutableMapOf('{' to '}', '[' to ']', '(' to ')')
        for (i in s.indices) {
            for (j in i until i + s.length) {
                val c = s[j % s.length]
                when (c) {
                    '{', '[', '(' -> stack.push(c)
                    else -> {
                        if (stack.isEmpty()) enable = false
                        else if (bracket[stack.pop()] != c) enable = false
                    }
                }
            }
            if (enable && stack.isEmpty()) answer++
            enable = true
            stack.clear()
        }
        return answer
    }
}