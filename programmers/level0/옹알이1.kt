package programmers

class Solution6 {
    fun solution(babbling: Array<String>): Int {
        var answer: Int = 0
        val words = listOf("aya", "ye", "woo", "ma")
        babbling.forEach { word ->
            var str = ""
            for(c in word) {
                str += c
                if(words.contains(str)) {
                    str = ""
                }
            }
            if(str == "") answer++
        }
        return answer

//        var answer: Int = 0
//        val enable = listOf("aya", "ye", "woo", "ma")
//        babbling.forEach {
//            var word = it
//            for(e in enable) {
//                word = word.replace(e, " ")
//            }
//            if(word.isBlank()) answer++
//        }
//        return answer
    }
}