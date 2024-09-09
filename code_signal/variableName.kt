package codesignal

fun solution25(name: String): Boolean =
    name[0] !in '0'..'9' && name.map { it in 'a'..'z' || it in 'A'..'Z' || it in '0'..'9' || it == '_' }.filter { !it }.isEmpty()