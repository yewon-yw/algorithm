package codesignal

fun solution2(inputArray: MutableList<Int>): Int {
    var max = Int.MIN_VALUE
    for(i in 0..inputArray.size-2) {
        val multi = inputArray[i] * inputArray[i+1]
        if(max<multi) max = multi
    }
    return max
}