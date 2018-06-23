func addDigits(num int) int {
    if num==0{
        return 0
    }
    num%=9
    if num==0{
        return 9
    }else{
        return num
    }
}