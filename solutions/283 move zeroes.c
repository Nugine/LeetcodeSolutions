// void moveZeroes(int *nums, int numsSize) {
//     int fisrt_zero_index = -1;
//     int i, st = 0, flag = 1;
//     while (st < numsSize && flag) {
//         flag = 0;
//         for (i = st; i < numsSize; ++i) {
//             if (fisrt_zero_index == -1) {
//                 if (nums[i] == 0) {
//                     fisrt_zero_index = i;
//                 }
//             } else if (nums[i] != 0) {
//                 nums[fisrt_zero_index] = nums[i];
//                 nums[i] = 0;
//                 st = fisrt_zero_index + 1;
//                 fisrt_zero_index = -1;
//                 flag = 1;
//                 break;
//             }
//         }
//     }
// }

void moveZeroes(int nums[], int numsSize) {
    if (numsSize < 2)
        return nums;
    int i = 0, j = 0;
    for (; i < numsSize; ++i) {
        if (nums[i]) {
            nums[j] = nums[i];
            ++j;
        }
    }
    for (; j < numsSize; ++j) {
        nums[j] = 0;
    }
}