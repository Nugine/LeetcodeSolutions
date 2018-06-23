func detectCapitalUse(word string) bool {
    bs:=[]byte(word)
    l:=len(bs)
    if l<=1{
        return true
    }
    
    if 'A'<=bs[0] && bs[0]<='Z'{
        if 'A'<=bs[1] && bs[1]<='Z'{
            for i:=2;i<l;i++{
                if bs[i]<'A' || bs[i] >'Z'{
                    return false
                }
            }
            return true
        }else{
            for i:=2;i<l;i++{
                if bs[i]<'a' || bs[i] >'z'{
                    return false
                }
            }
            return true
        }
    }else{
        for i:=1;i<l;i++{
            if bs[i]<'a' || bs[i] >'z'{
                return false
            }
        }
        return true
    }
}