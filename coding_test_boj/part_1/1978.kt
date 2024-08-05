package basic

import kotlin.math.sqrt

fun main() = with(System.`in`.bufferedReader()) {
    readLine()
    val num = readLine().split(' ').map { it.toInt() }
    val prime = BooleanArray(1001) {true}
    prime[0] = false; prime[1] = false
    for (i in 1..sqrt(1000f).toInt()) { // 특정 숫자의 제곱근까지만 검토하면 됨. 예를 들어 1000의 경우 제곱근은 31.62로 정수로 변환했을 땐 31. 31보다 큰 약수가 존재한다면, 이미 그보다 작은 약수와 짝을 이뤘기 때문에 확인할 필요가 없음
        if (!prime[i]) continue
        for (j in i * i .. 1000 step i) { // 만약 i가 5라면 5의 배수는 이미 2,3,4의 배수에서 제거되었기 떄문에 5의 제곱부터 시작
            prime[j] = false
        }
    }
    var count = 0
    for (e in num) {
        if (prime[e]) count++
    }
    println(count)
}
