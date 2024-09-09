package codesignal

fun solution24(n: Int): Boolean = n.toString().map { it.toInt() % 2 == 0 }.filter { !it }.size == 0

