/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* rv=(int*)malloc(sizeof(int)*numsSize);
    *returnSize=numsSize;
    
    int i,t;
    
    rv[0]=1;
    for(i=1;i<numsSize;++i){
        rv[i]=nums[i-1]*rv[i-1];
    }
    
    t=nums[numsSize-1];
    for(i=numsSize-2;i>=0;--i){
        rv[i]*=t;
        t*=nums[i];
    }
    
    return rv;
}