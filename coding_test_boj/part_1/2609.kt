package basic

fun main() = with(System.`in`.bufferedReader()) {
    val (a, b) = readLine().split(' ').map { it.toInt() }
    val max = maxOf(a, b)
    val min = minOf(a, b)
    val gcd = gcd(max, min)
    val lcm = lcm(max, min, gcd)
    println(gcd)
    println(lcm)
}

fun gcd(max: Int, min: Int): Int {
    var a = max
    var b = min
    var r = 0
    do {
        r = a % b
        a = b
        b = r
    } while (r > 0)
    return a
}

fun lcm(max: Int, min: Int, gcd: Int): Int {
    return max * min / gcd
}
