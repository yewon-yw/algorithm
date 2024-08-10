package part2

fun main() = with(System.`in`.bufferedReader()) {
    val fix = mutableSetOf('a', 'n', 't', 'i', 'c')
    val (n, k) = readLine().split(' ').map { it.toInt() }
    val words = mutableListOf<Int>() // 제공된 단어 리스트
    val alphabet = BooleanArray(26) // 필요한 알파벳 체크(visited 역할)
    var max = 0

    repeat(n) {
        val w = readLine().toCharArray().toSet().minus(fix) // 집합으로 변경 후 항상 필요한 알파벳 제외
        var bitSet = 0
        for (e in w) {
            val bitPos = e - 'a'
            bitSet = bitSet or (1 shl bitPos) // 필요한 알파벳을 비트로 저장
            alphabet[bitPos] = true
        }
        words.add(bitSet)
    }

    fun dfs(start: Int, count: Int, toLearn: Int) {
        if (count == k - 5) {
            var canLearn = 0
            for (word in words) {
                if (word and toLearn == word) canLearn++ // and 연산으로 특정 알파벳이 포함되어있는지 확인
            }
            if (canLearn > max) max = canLearn
            return
        }
        for (i in start..<alphabet.size) { // start 인덱스 이전에는 이미 확인했으니까 그 이후만 확인
            if (!alphabet[i]) continue
            alphabet[i] = false
            dfs(i, count + 1, toLearn or (1 shl i)) // or 연산으로 다른 알파벳 추가
            alphabet[i] = true
        }
    }

    if (k < 5) println(0)
    else if (alphabet.filter { it }.size <= k - 5) println(n)
    else {
        dfs(0, 0, 0)
        println(max)
    }
}