func shiftingLetters(S string, shifts []int) string {
    i:=0
    l:=len(S)
    shifts[l-1]%=26
    for i=l-2;i>=0;i--{
        shifts[i]+=shifts[i+1]
        shifts[i]%=26
    }
    bs:=make([]byte,l,l)
    for i=0;i<l;i++{
        bs[i]=byte(((int(S[i])+shifts[i]-97)%26)+97)
    }
    return string(bs)
}