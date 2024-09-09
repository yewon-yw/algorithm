package codesignal

fun solution21(image: MutableList<MutableList<Int>>): MutableList<MutableList<Int>> {
    val (n, m) = image.size to image[0].size
    val blurred = mutableListOf<MutableList<Int>>()
    for(i in 1..n-2) {
        val list = mutableListOf<Int>()
        for(j in 1..m-2) {
            var square = 0
            for(ci in i-1..i+1) {
                for(cj in j-1..j+1) {
                    square += image[ci][cj]
                }
            }
            list.add(square/9)
        }
        blurred.add(list)
    }
    return blurred
}
