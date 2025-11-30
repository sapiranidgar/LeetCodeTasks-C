#include <stdio.h>

/*
You are given an integer array target and an integer n.
You have an empty stack with the two following operations:

"Push": pushes an integer to the top of the stack.
"Pop": removes the integer on the top of the stack.
You also have a stream of the integers in the range [1, n].

Use the two stack operations to make the numbers in the stack (from the bottom to the top) equal to target. You should follow the following rules:

If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.
If the stack is not empty, pop the integer at the top of the stack.
If, at any moment, the elements in the stack (from the bottom to the top) are equal to target, do not read new integers from the stream and do not do more operations on the stack.
Return the stack operations needed to build target following the mentioned rules. If there are multiple valid answers, return any of them.

Example 1:
Input: target = [1,3], n = 3
Output: ["Push","Push","Pop","Push"]

Example 2:
Input: target = [1,2,3], n = 3
Output: ["Push","Push","Push"]

Example 3:
Input: target = [1,2], n = 4
Output: ["Push","Push"]

Constraints:
    1 <= target.length <= 100
    1 <= n <= 100
    1 <= target[i] <= n
    target is strictly increasing.

* Note: The returned array must be malloced, assume caller calls free().
*/

char **buildArray(int *target, int targetSize, int n, int *returnSize)
{
    char **ans = (char **)malloc(sizeof(char *) * 2 * n);
    int answer_index = 0;
    int stream_current_value = 1;

    for (int i = 0; i < targetSize; i++)
    {
        while (target[i] > stream_current_value)
        {
            ans[answer_index++] = "Push";
            ans[answer_index++] = "Pop";
            stream_current_value++;
        }
        ans[answer_index++] = "Push";
        stream_current_value++;
    }

    *returnSize = answer_index;
    return ans;
}

int main()
{
    int nums[] = {1, 3};
    int returnSize;
    int n = 3;
    int numsSize = 2;
    char **result = buildArray(nums, numsSize, n, &returnSize);
    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%s ", result[i]);
    }
    return 0;
}