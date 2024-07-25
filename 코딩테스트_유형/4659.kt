fun main() = with(System.`in`.bufferedReader()) {
    val regex = Regex("^(?=.*[aeiou])(?!.*[aeiou]{3})(?!.*[^aeiou]{3})(?!.*([^eo])\\1)[a-z]+\$")
    while (true) {
        val word = readLine()
        if (word == "end") break
        println(
            if (regex.matches(word)) "<$word> is acceptable."
            else "<$word> is not acceptable."
        )
    }
}

/**
 * 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
 * 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
 * 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
 */