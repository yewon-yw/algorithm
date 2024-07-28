fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val cookie = Array(n) { BooleanArray(n) }
    var heart = Pair(0, 0)
    var lArm = 0; var rArm = 0; var waist = 0 ; var lLeg = 0 ; var rLeg = 0
    for (i in 0..<n) {
        cookie[i] = readLine().map { if (it == '*') true else false }.toBooleanArray()
    }
    // 심장 위치 구하기
    findHeartPos@ for (i in cookie.indices) {
        for (j in cookie[i].indices) {
            if (cookie[i][j]) {
                heart = Pair(i + 1, j)
                break@findHeartPos
            }
        }
    }
    for (i in 0..<heart.second) {
        if (cookie[heart.first][i]) lArm++
    }
    for (i in heart.second + 1..<n) {
        if (cookie[heart.first][i]) rArm++
    }
    for (i in heart.first + 1..<n) {
        if (cookie[i][heart.second]) waist++
    }
    for (i in heart.first + waist + 1..<n) {
        if (cookie[i][heart.second - 1]) lLeg++
        if (cookie[i][heart.second + 1]) rLeg++
    }
    println("${heart.first + 1} ${heart.second + 1}")
    println("$lArm $rArm $waist $lLeg $rLeg")
}