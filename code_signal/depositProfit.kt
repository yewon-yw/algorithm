package codesignal

fun solution29(deposit: Int, rate: Int, threshold: Int): Int {
    //deposit * (rate / 100.toDouble() + 1) 이 threshold를 넘을 때
    var current = deposit.toDouble()
    var year = 0
    while(current < threshold) {
        current *= (rate/(100.toDouble()) + 1)
        year++
    }
    return year
}
