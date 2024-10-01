package codility

import java.util.*

fun solution_Brackets(S: String): Int {
    val s = Stack<Char>()
    val nest = mapOf('{' to '}', '[' to ']', '(' to ')')
    S.forEach {
        when(it) {
            '(', '[', '{' -> s.push(it)
            else -> {
                if(s.isEmpty()) return 0
                if((nest[s.pop()!!] ?: ' ') != it) return 0
            }
        }
    }
    return if(s.isEmpty()) 1 else 0
}