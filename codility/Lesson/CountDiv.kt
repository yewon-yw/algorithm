package codility

fun solution_CountDiv(A: Int, B: Int, K: Int): Int = B/K - A/K + if(A % K == 0) 1 else 0
