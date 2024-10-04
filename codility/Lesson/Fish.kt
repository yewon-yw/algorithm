package codility

import java.util.*

// O(N)
fun solution_Fish(A: IntArray, B: IntArray): Int {
    val N = A.size
    val s = Stack<Pair<Int, Int>>()

    for(i in 0 until N) {
        var flag = true
        while(s.isNotEmpty() && s.peek().second == 1 && B[i] == 0) { // 만나는 경우
            if(s.peek().first < A[i]) { // 뒤의 물고기가 더 큰 경우
                s.pop()
            } else {
                flag = false // 앞의 물고기가 더 크면 아예 넣지 않음
                break
            }
        }
        if(flag) s.push(A[i] to B[i])
    }

    return s.size
}