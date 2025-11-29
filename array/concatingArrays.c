#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getConcatenation(int *nums, int numsSize, int *returnSize)
{
    int *ans = (int *)malloc(numsSize * 2 * sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        ans[i] = nums[i];
        ans[i + numsSize] = nums[i];
    }
    *returnSize = numsSize * 2;
    return ans;
}

int main()
{
    int nums[] = {1, 2, 1};
    int returnSize;
    int numsSize = 3;
    int *result = getConcatenation(nums, numsSize, &returnSize);
    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}