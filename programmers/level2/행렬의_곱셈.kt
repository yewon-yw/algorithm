package programmers

class Solution21 {
    fun solution(arr1: Array<IntArray>, arr2: Array<IntArray>): Array<IntArray> {
        val answer = Array(arr1.size) { IntArray(arr2[0].size) { 0 } }
        for(i in arr1.indices) {
            for(j in arr2[0].indices) {
                for(k in arr2.indices) {
                    answer[i][j] += arr1[i][k] * arr2[k][j]
                }
            }
        }
        return answer
    }
}