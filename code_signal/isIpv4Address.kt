package codesignal

fun solution19(inputString: String): Boolean {
    val numbers = inputString.split('.')
    if (numbers.size != 4) return false
    numbers.forEach { num ->
        if ((num.toIntOrNull() ?: -1) !in 0..255) return false // 숫자가 아닌경우, 범위를 벗어나는 경우
        if (num.length > 1 && num[0] == '0') return false // leadingZero 케이스 확인
    }
    return true
}