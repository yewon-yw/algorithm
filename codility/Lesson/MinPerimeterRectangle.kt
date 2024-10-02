package codility

fun solution_MinPerimeterRectangle(N: Int): Int {
    val sqrt = Math.sqrt(N.toDouble()).toInt()
    var (a, b) = 0 to 0
    for(i in 1..sqrt) {
        if(N % i == 0) {
            a = i
            b = N / i
        }
    }
    return 2 * (a + b)
}