#include <stdio.h>

#define MAX_NUM 101

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
    int *counter = (int *)malloc(MAX_NUM * sizeof(int));

    // Initialize counter array to 0
    for (int i = 0; i < MAX_NUM; i++)
    {
        counter[i] = 0;
    }

    // For each number in nums, increment its count in counter
    for (int i = 0; i < numsSize; i++)
    {
        counter[nums[i]] += 1;
    }

    // Modify counter to hold the count of numbers less than or equal to each index
    for (int i = 1; i < 101; ++i)
    {
        counter[i] += counter[i - 1];
    }

    // Fill the result array using the counter
    for (int i = 0; i < numsSize; ++i)
    {
        res[i] = nums[i] ? counter[nums[i] - 1] : 0;
    }
    return res;
}

int main()
{
    int nums[] = {6, 5, 4, 8};
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