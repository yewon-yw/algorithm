package basic

fun main() = with(System.`in`.bufferedReader()) {
    val arr = IntArray(1001)
    var num = 1
    var count = 0
    for (i in 1..<arr.size) {
        if (count == num) {
            num++
            count = 0
        }
        arr[i] = num
        count++
    }
    val (start, end) = readLine().split(' ').map { it.toInt() }
    println(arr.sliceArray(start..end).sum())
}

// 다른 풀이
//fun main() = with(System.`in`.bufferedReader()) {
//    val (start, end) = readLine().split(' ').map { it.toInt() }
//    var num = 1
//    var count = 0
//    var sum = 0
//    while (count<end) {
//        repeat(num) {
//            count++
//            if (count in start..end) sum += num
//        }
//        num++
//    }
//    println(sum)
//}