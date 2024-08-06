package part2

import java.util.Stack

fun main() = with(System.`in`.bufferedReader()) {
    val input = readLine()
    val s = Stack<Char>()
    var temp = 1
    var result = 0
    for (i in input.indices) {
        when (input[i]) {
            '(' -> {
                s.push('(')
                temp *= 2
            }

            '[' -> {
                s.push('[')
                temp *= 3
            }

            ')' -> {
                if (s.isNotEmpty() && s.peek() == '(') {
                    if (input[i - 1] == '(') result += temp
                    s.pop()
                    temp /= 2
                } else {
                    s.push(')')
                }
            }

            ']' -> {
                if (s.isNotEmpty() && s.peek() == '[') {
                    if (input[i - 1] == '[') result += temp
                    s.pop()
                    temp /= 3
                } else {
                    s.push(']')
                }
            }
        }
    }
    if (s.isNotEmpty()) println(0)
    else println(result)
}