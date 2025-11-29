#include <stdio.h>

/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.

Example 1:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]

Example 2:
Input: nums = [6,5,4,8]
Output: [2,1,0,3]

Example 3:
Input: nums = [7,7,7,7]
Output: [0,0,0,0]


Constraints:
    2 <= nums.length <= 500
    0 <= nums[i] <= 100

* Note: The returned array must be malloced, assume caller calls free().
*/

int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    int n = numsSize + 1;
    int *counter = (int *)calloc(n, sizeof(int));
    int *res = (int *)malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        counter[nums[i]] = 1;
    }

    int result_idx = 0;
    for (int i = 1; i < n; i++)
    {
        if (counter[i] == 0)
        {
            res[result_idx] = i;
            result_idx++;
        }
    }

    *returnSize = result_idx;
    return res;
}

int main()
{
    int nums[] = {4, 4, 4, 4};
    int returnSize;
    int numsSize = 4;
    int *result = findDisappearedNumbers(nums, numsSize, &returnSize);
    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}