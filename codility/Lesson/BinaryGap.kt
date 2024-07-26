fun main() = with(System.`in`.bufferedReader()) {
    var n = readLine().toInt()
    val binary = StringBuffer()
    val sequenceList = mutableListOf<Int>()
    while (n != 0) {
        binary.append("${n % 2}")
        n /= 2
    }
    binary.reverse()
//    println(binary.reverse())
    var count = 0
    for (i in binary.indices) {
        if (binary[i] == '1') {
            if (count > 0) sequenceList.add(count)
//            println("list: $sequenceList")
            count = 0
        } else {
            count++
        }
    }
    println(sequenceList.maxOrNull() ?: 0)
}