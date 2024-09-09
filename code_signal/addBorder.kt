package codesignal

fun solution13(picture: MutableList<String>): MutableList<String> {
    val border = "*".repeat(picture[0].length + 2)
    val body = picture.map { "*$it*" }
    val result = mutableListOf<String>().apply {
        add(border)
        addAll(body)
        add(border)
    }
    return result
}
