package programmers

class Solution8 {
    // 투포인터 (이미 정렬)
    // 두 포인터 사이의 원소 값을 더해서 k 보다 작으면 second 증가
    // k 보다 크면 first 증가
    // k 가 되면 가능한 수열 리스트에 추가
    // sum 을 for 문으로 구하게 되면 시간 초과
    fun solution(sequence: IntArray, k: Int): IntArray {
        val enable = mutableListOf<IntArray>()
        var first = 0
        var second = 0
        var sum = sequence[0]
        while(second < sequence.size) {
            if(sum == k) enable.add(intArrayOf(first, second))
            if(sum < k) {
                if(++second>=sequence.size) break
                sum += sequence[second]
            }
            else {
                sum -= sequence[first++]
            }
        }
        return enable.minByOrNull { it[1] - it[0] }!!
    }
}
