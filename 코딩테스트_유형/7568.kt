fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val group: MutableList<Person> = mutableListOf()
    repeat(n) {
        val (h, w) = readLine().split(" ").map { it.toInt() }
        group.add(Person(h, w))
    }
    group.forEach {
        for (p in group) {
            if (it.height < p.height && it.weight < p.weight) it.rank++
        }
        print("${it.rank} ")
    }
}

class Person(val height: Int, val weight: Int, var rank: Int = 1)