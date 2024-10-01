package codility

import java.util.*

fun solution_Nesting(S: String): Int {
    val stack = Stack<Char>()
    S.forEach {
        when(it) {
            '(' -> stack.push(it)
            else -> {
                if(stack.isEmpty() || stack.pop() != '(') return 0
            }
        }
    }
    return if(stack.isNotEmpty()) 0 else 1
}