package codesignal

fun solution17(yourLeft: Int, yourRight: Int, friendsLeft: Int, friendsRight: Int): Boolean =
    Math.max(yourLeft, yourRight) == Math.max(friendsLeft, friendsRight) && Math.min(yourLeft, yourRight) == Math.min(friendsLeft, friendsRight)
