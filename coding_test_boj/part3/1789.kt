package part3

fun main() = with(System.`in`.bufferedReader()) {
    var s = readLine().toLong()
    var n = 1
    while (s > 0) {
        s -= n
        if (s < 0) break
        n++
    }
    println(n - 1)
}
// 1~k 까지 더한 수보다 작으면 결과는 k-1
// 즉, 15~20 까지는 5 값을 가지고, 21~27는 6 이런 식
// n 값이 최대여야하기 때문에 가장 작은 수를 차례로 사용해야 함
// 16을 예로 들면 1, 2, 3, 4, 6 의 합으로 나타낼 수 있음
// 1 2 3 4 5를 선택하든, 1 2 3 4 6을 선택하든 결국 자연수 n의 개수는 5개로 동일하기 때문에
// s를 만드는 데에는 문제가 없음