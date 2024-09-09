package codesignal

fun solution22(matrix: MutableList<MutableList<Boolean>>): MutableList<MutableList<Int>> {
    val (n, m) = matrix.size to matrix[0].size
    val output = Array(n) { IntArray(m) }
    for (i in matrix.indices) {
        for (j in matrix[i].indices) {
            println(matrix[i][j])
            if (matrix[i][j]) {
                for (mi in i - 1..i + 1) {
                    for (mj in j - 1..j + 1) {
                        if (mi < 0 || mi >= n || mj < 0 || mj >= m || (mi == i && mj == j)) continue
                        output[mi][mj]++
                    }
                }
            }
        }
    }
    return output.map { it.toMutableList() }.toMutableList()
}
