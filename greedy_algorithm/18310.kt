fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val homes = readLine().split(" ").map { it.toInt() }.sorted()
    println(homes[(n - 1) / 2])
}