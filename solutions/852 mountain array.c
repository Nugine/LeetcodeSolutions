// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>


int peakIndexInMountainArray(int* A, int ASize) {
    int p,q,i;
    p=A[0];
    for(i=1;i<ASize;++i){
        q=A[i];
        if(p>q){
            return i-1;
        }
        else{
            p=q;
        }
    }
    return -1;
}

// int main(int argc, char const *argv[]) {
//     int x[] = {0,1,2,0};
//     printf("%d",peakIndexInMountainArray(x,4));
//     return 0;
// }