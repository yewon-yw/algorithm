package codesignal

fun solution6(matrix: MutableList<MutableList<Int>>): Int {
    val canVisit = Array(matrix.size){BooleanArray(matrix[0].size){true}}
    var sum = 0
    for(i in matrix.indices) {
        for(j in matrix[i].indices) {
            if(matrix[i][j] == 0) {
                for(k in i..matrix.size-1) canVisit[k][j] = false
            }
        }
    }
    for(i in matrix.indices) {
        for(j in matrix[i].indices) {
            if(canVisit[i][j]) sum += matrix[i][j]
        }
    }
    return sum
}
