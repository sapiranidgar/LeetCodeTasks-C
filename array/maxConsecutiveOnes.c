#include <stdio.h>

/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
Constraints:
    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.
*/
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int max_consecutives = 0;
    int current_consecutives = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            current_consecutives = current_consecutives + 1;
            if (max_consecutives < current_consecutives)
            {
                max_consecutives = current_consecutives;
            }
        }
        else
        {
            current_consecutives = 0;
        }
    }
    return max_consecutives;
}

int main()
{
    int nums[] = {1, 0, 1, 0};
    int numsSize = 4;
    int result = findMaxConsecutiveOnes(nums, numsSize);
    printf("Result: ");
    printf("%d ", result);
    return 0;
}