fun main() {
    val br = System.`in`.bufferedReader()
    val (n, k) = br.readLine().split(" ").map { it.toInt() }
    val input = Array(1001) { IntArray(3) }
    val medal = mutableListOf<List<Int>>()
    repeat(n) {
        val l = br.readLine().split(" ").map { it.toInt() }
        input[l[0]] = l.subList(1, 4).toIntArray()
        medal.add(l.subList(1, 4))
    }
    medal.sortWith(compareByDescending<List<Int>> { it[0] }.thenByDescending { it[1] }.thenByDescending { it[2] })
    var rank = 1
    for (i in medal) {
        if (!input[k].contentEquals(i.toIntArray())) rank ++
        else break
    }
    println(rank)
}