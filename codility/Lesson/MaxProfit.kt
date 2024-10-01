package codility

// i -> i-1 날까지의 min 값 저장해놓고 i 날짜에 팔때의 이득
fun solution_MaxProfit(A: IntArray): Int {
    var (minPrice, profit) = 200_000 to 0
    A.forEach {
        profit = Math.max(profit, it - minPrice) // 오늘 날짜에 팔때 최대 이득
        minPrice = Math.min(minPrice, it) // 오늘까지의 가격 포함해서 최소 가격 갱신
    }
    return profit
}