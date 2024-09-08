package codesignal

fun solution1(inputString: String): Boolean {
    for(i in 0..inputString.length / 2) {
        if(inputString[i] != inputString[inputString.length - (i+1)]) return false
    }
    return true
}
