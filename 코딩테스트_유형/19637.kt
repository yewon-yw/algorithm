fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    val title = mutableMapOf<Int, String>()
    val (n, m) = readLine().split(' ').map { it.toInt() }
    repeat(n) {
        val (name, power) = readLine().split(' ')
        title.putIfAbsent(power.toInt(), name)
    }
    val powers = title.keys.toList()
    repeat(m) {
        val character = readLine().toInt()
        var (s, e) = 0 to powers.size - 1
        while (s <= e) {
            val mid = (s + e) / 2
            if (powers[mid] < character) s = mid + 1
            else e = mid - 1
        }
        bw.write("${title[powers[s]]}\n")
    }
    bw.flush()
}