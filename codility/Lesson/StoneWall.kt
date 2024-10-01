package codility

import java.util.*

// s.top 과 현재 높이 비교
// 같은 경우 -> count 증가 x
// 낮아지는 경우 -> peek가 h보다 작거나 같아질 때까지 pop, peek와 h가 다르면 push & count 증가
// 높아지는 경우 -> count 증가, push(현재 높이)

fun solution_StoneWall(H: IntArray): Int {
    val s = Stack<Int>()
    var count = 0
    s.push(0)

    for(i in H.indices) {
        val top = s.peek()
        val h = H[i]
        if(top == h) continue // 높이가 같은 경우
        if(top < h) { // 높아지는 경우
            s.push(h)
            count++
        } else { // 낮아지는 경우
            while(s.peek() > h) s.pop()
            if(s.peek() != h) {
                s.push(h)
                count++
            }
        }
    }
    return count
}
