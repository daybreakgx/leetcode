#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* ret = (int*)malloc(sizeof(int) * 2);
    if (ret == NULL) {
        return NULL;
    }
    for (int i = 0; i < numsSize; i++) {
        int tmp = nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (target - tmp == nums[j]) {
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }
    free(ret);
    return NULL;
}

void main() {
    int nums[] = {2, 8, 9, 10, 100, 7};
    int target = 9;
    int* ret = NULL;
    int retSize = 0;

    ret = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target, &retSize);
    for(int i = 0; i < retSize; i++) {
        printf("%d\n", ret[i])
    }
}