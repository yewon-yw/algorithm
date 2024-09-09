package codesignal

fun solution18(inputArray: MutableList<Int>): Int {
    var max = 0
    for(i in 0 until inputArray.size - 1) {
        val difference = Math.abs(inputArray[i] - inputArray[i+1])
        max = if(max < difference) difference else max
    }
    return max
}
