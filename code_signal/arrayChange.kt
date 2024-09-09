package codesignal

fun solution15(inputArray: MutableList<Int>): Int {
    var result = 0
    for(i in 0 until inputArray.size - 1) {
        if(inputArray[i]<inputArray[i+1]) continue
        val value = inputArray[i] + 1
        val wanted = value - inputArray[i+1]
        inputArray[i+1] = value
        result += wanted
    }
    return result
}