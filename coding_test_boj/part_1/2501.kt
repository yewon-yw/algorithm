package basic

// 약수구하기
fun main() = with(System.`in`.bufferedReader()) {
    val (n, k) = readLine().split(' ').map { it.toInt() }
    val measure = mutableListOf<Int>()
    for (i in 1..n) {
        if (n % i == 0) measure.add(i)
    }
    println(if (measure.size < k) 0 else measure[k-1])
}