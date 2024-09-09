package codesignal

fun solution20(inputArray: MutableList<Int>): Int {
    inputArray.sort()
    for(i in 2 until inputArray[inputArray.size-1]) {
        var enable = true
        inputArray.forEach {
            if(it % i == 0) enable = false
        }
        if(enable) return i
    }
    return inputArray[inputArray.size-1] + 1
}
