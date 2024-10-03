package codility


fun gcd(N: Int, M: Int): Int {
    if(M == 0) return N
    return gcd(M, N % M)
}

fun solution(N: Int, M: Int): Int {
    return N / gcd(N, M)
}
