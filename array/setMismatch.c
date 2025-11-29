#include <stdio.h>

/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Example 2:
Input: nums = [1,1]
Output: [1,2]


Constraints:
    2 <= nums.length <= 104
    1 <= nums[i] <= 104

* Note: The returned array must be malloced, assume caller calls free().
*/

int *findErrorNums(int *nums, int numsSize, int *returnSize)
{
    *returnSize = 2;
    int *res = (int *)malloc(2 * sizeof(int));
    int *freq = calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++)
    {
        freq[nums[i] - 1]++;
    }
    for (int i = 0; i < numsSize; i++)
    {
        if (freq[i] == 2)
            res[0] = i + 1;
        if (freq[i] == 0)
            res[1] = i + 1;
    }
    free(freq);
    return res;
}

int main()
{
    int nums[] = {1, 2, 2, 4};
    int returnSize;
    int numsSize = 4;
    int *result = findErrorNums(nums, numsSize, &returnSize);
    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}