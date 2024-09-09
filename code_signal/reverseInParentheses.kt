package codesignal

import java.util.*

fun solution11(inputString: String): String {
    val s = Stack<StringBuilder>()
    for(c in inputString) {
        when(c) {
            '(' -> {
                s.add(StringBuilder())
            }

            ')' -> {
                val reversed = s.pop().reverse()
                if(s.isEmpty()) {
                    s.push(reversed)
                } else {
                    s[s.size-1].append(reversed)
                }
            }

            else -> {
                if(s.isEmpty()) {
                    s.add(StringBuilder("$c"))
                } else {
                    s[s.size-1].append("$c")
                }
            }
        }
    }
    return s.joinToString()
}