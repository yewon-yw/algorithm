package codesignal

fun solution27(cell1: String, cell2: String): Boolean {
    fun isEven(num: Int) = num % 2 == 0
    val cell1Color = isEven(cell1[0] - 'A' + 1) xor isEven(cell1[1] - '0')
    val cell2Color = isEven(cell2[0] - 'A' + 1) xor isEven(cell2[1] - '0')
    return cell1Color == cell2Color
}
