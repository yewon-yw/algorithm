package part4

fun main() = with(System.`in`.bufferedReader()) {
    val (a, b) = readLine().split(' ')
    var result: Int? = null
    fun dfs(num: String, depth: Int) {
        if (num == b) {
            result = depth
            return
        }
        if (num.toLong() > b.toLong()) return
        dfs("${num.toLong() * 2}", depth + 1)
        dfs(num + "1", depth + 1)
    }
    dfs(a, 1)
    println(result ?: -1)
}