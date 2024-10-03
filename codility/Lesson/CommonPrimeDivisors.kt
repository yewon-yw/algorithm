package codility

// 각 수가 최대공약수의 소인수로만 이루어져있는지 확인
// O(Z * log(max(A) + max(B))**2)
fun solution(A: IntArray, B: IntArray): Int {
    var count = 0
    repeat(A.size) { z ->
        val gcd = getGcd(A[z], B[z])
        if(isGcdFactor(A[z], gcd) == 1 && isGcdFactor(B[z], gcd) == 1) count++
    }
    return count
}

fun getGcd(N: Int, M: Int): Int {
    if(M == 0) return N
    return getGcd(M, N % M)
}

fun isGcdFactor(num: Int, gcdValue: Int): Int {
    // gcd의 소인수로 이루어져있으면 1
    var gcd = gcdValue
    var n = num
    while(gcd != 1) {
        n /= gcd
        if(n == 1) break
        gcd = getGcd(n, gcd)
    }
    return n
}