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

int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *)malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++)
    {
        ;
        res[i] = 0;
    }
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] < nums[i])
            {
                res[i] = res[i] + 1;
            }
            else if (nums[j] > nums[i])
            {
                res[j] = res[j] + 1;
            }
        }
    }
    return res;
}

int main()
{
    int nums[] = {1, 2, 3, 4};
    int returnSize;
    int numsSize = 4;
    int *result = smallerNumbersThanCurrent(nums, numsSize, &returnSize);
    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}