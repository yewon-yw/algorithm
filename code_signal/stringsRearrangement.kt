package codesignal

fun solution31(inputArray: MutableList<String>): Boolean {
    val visited = BooleanArray(inputArray.size)
    var enable = false
    fun check(str1: String, str2: String): Boolean =
        str1.mapIndexed { i, s1 -> s1 == str2[i] }.filter { !it }.size == 1
    fun dfs(depth: Int, latestStr: String) {
        if(depth == inputArray.size) {
            enable = true
            return
        }
        for(i in visited.indices) {
            if(!visited[i] && check(latestStr, inputArray[i])) {
                visited[i] = true
                dfs(depth+1, inputArray[i])
                visited[i] = false
            }
        }
    }
    for(i in 0..inputArray.size - 1) {
        for(j in 0..inputArray.size - 1) {
            if(i == j) continue
            if(check(inputArray[i], inputArray[j])){
                visited[i] = true
                visited[j] = true
                dfs(2, inputArray[j])
                visited[i] = false
                visited[j] = false
            }
        }
    }
    return enable
}

