package programmers

class Solution9 {
    fun solution(numbers: IntArray, target: Int): Int {
        var answer: Int = 0
        fun dfs(next: Int, sum: Int) {
            if(next + 1 >= numbers.size) {
                if(sum == target) answer++
                return
            }
            dfs(next + 1, sum + numbers[next + 1])
            dfs(next + 1, sum - numbers[next + 1])
        }
        dfs(-1, 0)
        return answer
    }
}