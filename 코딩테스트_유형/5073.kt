fun main() {
    while (true) {
        val (a, b, c) = readln().split(' ').map { it.toInt() }.sorted()
        if (c == 0) break

        println(
            when {
                c >= a + b -> "Invalid"
                a == b && b == c -> "Equilateral"
                a == b || b == c -> "Isosceles"
                else -> "Scalene"
            }
        )
    }
}