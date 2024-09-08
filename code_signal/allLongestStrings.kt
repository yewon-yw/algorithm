package codesignal

fun solution7(inputArray: MutableList<String>): MutableList<String> {
    val max = inputArray.maxOf { it.length }
    return inputArray.filter { it.length == max }.toMutableList()
}