package codesignal

fun solution23(inputArray: MutableList<Int>, elemToReplace: Int, substitutionElem: Int): MutableList<Int> =
    inputArray.map{ if(it == elemToReplace) substitutionElem else it }.toMutableList()
