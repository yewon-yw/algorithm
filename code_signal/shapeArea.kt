package codesignal

fun solution3(n: Int): Int {
    var answer = 1
    for(i in 2..n) {
        answer += (i-1) * 4
    }
    return answer
}
