//private fun solution(A: IntArray): Int {
//    val exist = BooleanArray(100_002) { false }
//    for(e in A){
//        exist[e] = true
//    }
//    for(i in 1 .. exist.size - 1) {
//        if(!exist[i]) {
//            return i
//        }
//    }
//    return 0
//}

private fun solution(A: IntArray): Int {
    val n = A.size + 1
    val total = (n.toLong() * (n + 1)) / 2
    val sum = A.sumOf { it.toLong() }
    return (total - sum).toInt()
}

fun main() = with(System.`in`.bufferedReader()) {
    val arr = readLine().split(' ').map { it.toInt() }.toIntArray()
    println(solution(arr))
}