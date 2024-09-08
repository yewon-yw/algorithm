package codesignal

fun solution5(sequence: MutableList<Int>): Boolean {
    var enable = false
    for(i in 0 until sequence.size-1) {
        if(sequence[i] >= sequence[i+1]){
            if(enable) return false
            enable = true

            if(i>0 && i+2<=sequence.size-1 && sequence[i-1]>=sequence[i+1] && sequence[i]>=sequence[i+2]) {
                return false
            }
        }
    }
    return true
}
