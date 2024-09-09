package codesignal

fun solution16(inputString: String): Boolean {
    // inputString의 길이가 짝수인 경우 -> 각 숫자가 짝수개 존재
    // inputString의 길이가 홀수인 경우 -> 홀수개의 숫자는 하나만 존재
    val map = mutableMapOf<Char, Int>()
    for(c in inputString) {
        map[c] = (map[c]?: 0) + 1
    }
    val nonPair = map.filter { p -> p.value % 2 == 1 }.count()
    return if(nonPair == inputString.length % 2) true else false
}
