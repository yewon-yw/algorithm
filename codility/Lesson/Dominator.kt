package codility

// O(N log N)
fun solution_Dominator_1(A: IntArray): Int {
    val s = A.sorted()
    val mid = A.size / 2
    if(A.count { it == s[mid] } <= mid) return -1
    A.forEachIndexed { idx, it ->
        if(it == s[mid]) return idx
    }
    return -1
}

// Boyer-Moore
// O(N)
fun solution_Dominator_2(A: IntArray): Int {
    var count = 0
    var candidate = 0
    var dominator = 0
    // step 1. 후보 확인
    A.forEach {
        if(count == 0) {
            candidate = it
            count++
        } else if(candidate != it) {
            count--
        }
    }

    // step 2. 실제 절반이 넘는지 확인
    count = 0
    A.forEachIndexed { idx, it ->
        if(it == candidate) {
            count++
            dominator = idx
        }
    }
    return if(count > A.size / 2) dominator else -1
}