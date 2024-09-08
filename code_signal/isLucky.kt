package codesignal

fun solution9(n: Int): Boolean {
    val ticketNumber = n.toString()
    val first = ticketNumber.substring(0, ticketNumber.length/2)
    val second = ticketNumber.substring(ticketNumber.length/2, ticketNumber.length)
    return first.sumOf { it.code - 48 } == second.sumOf { it.code - 48 }
}
