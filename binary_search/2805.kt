package boj

import kotlin.math.max

// 1. 반복문
fun main() = with(System.`in`.bufferedReader()) {
    val (n, m) = readLine().split(' ').map { it.toInt() }
    val trees = readLine().split(' ').map { it.toInt() }.sorted()
    var (start, end) = 0 to trees[n - 1]
    var result = 0

    fun getSum(mid: Int): Long {
        var sum = 0L
        trees.forEach {
            if (it > mid) {
                sum += it - mid
            }
        }
        return sum
    }

    while (start <= end) {
        val mid = (start + end)/2
        val sum = getSum(mid)
        when {
            sum < m -> end = mid - 1
            else -> {
                start = mid + 1
                result = max(result, mid)
            }
        }
    }
    println(result)
}

// 2. 재귀
//fun main() = with(System.`in`.bufferedReader()) {
//    val (n, m) = readLine().split(' ').map { it.toInt() }
//    val trees = readLine().split(' ').map { it.toInt() }.sorted()
//    val (s, e) = 0 to trees[n - 1]
//    var result = 0
//
//    fun getSum(mid: Int): Long {
//        var sum = 0L
//        trees.forEach {
//            if (it > mid) {
//                sum += it - mid
//            }
//        }
//        return sum
//    }
//
//    fun binSearch(start: Int, end: Int) {
//        val mid = (start + end) / 2
//        if (start == mid || mid == end) return
//        val sum = getSum(mid)
//        when{
//            sum > m -> {
//                result = max(result, mid)
//                binSearch(mid, end)
//            }
//            sum < m -> {
//                binSearch(start, mid)
//            }
//            else -> {
//                result = max(result, mid)
//                return
//            }
//        }
//    }
//
//    binSearch(s, e)
//    println(result)
//}