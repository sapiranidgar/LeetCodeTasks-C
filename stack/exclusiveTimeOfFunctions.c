#include <stdio.h>

#define MY_STACK_SIZE 50000
#define START_LEN 6
#define END_LEN 4
#define START_INDICATOR 's'
#define LOG_SEPARATOR ':'
#define SMALLEST_DIGIT '0'
#define LARGEST_DIGIT '9'
#define RESULT_FUNC_ID_INDEX 0
#define RESULT_IS_START_INDEX 1
#define RESULT_TIME_INDEX 2

/*
On a single-threaded CPU, we execute a program containing n functions.
Each function has a unique ID between 0 and n-1.

Function calls are stored in a call stack:
When a function call starts, its ID is pushed onto the stack, and when a function call ends, its ID is popped off the stack.
The function whose ID is at the top of the stack is the current function being executed.
Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

You are given a list logs, where logs[i] represents the i-th log message formatted as a string:
 "{function_id}:{"start" | "end"}:{timestamp}".
For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function call with function ID 1 ended at the end of timestamp 2.
Note that a function can be called multiple times, possibly recursively.

A function's exclusive time is the sum of execution times for all function calls in the program. For example, if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit, the exclusive time is 2 + 1 = 3.

Return the exclusive time of each function in an array, where the value at the i-th index represents the exclusive time for the function with ID i.
*/

int *getLogDetails(char *current_log)
{
    // ---- Fast parse function id ----
    int func_id = 0;
    int log_pointer = 0;
    while (current_log[log_pointer] != LOG_SEPARATOR)
    {
        func_id = func_id * 10 + (current_log[log_pointer] - SMALLEST_DIGIT);
        log_pointer++;
    }
    log_pointer++; // skip ':'

    // ---- Fast check start/end ----
    int isStart = (current_log[log_pointer] == START_INDICATOR);

    // skip "start:" (6 chars) or "end:" (4 chars)
    log_pointer += isStart ? START_LEN : END_LEN;

    // ---- Fast parse timestamp ----
    int time = 0;
    while (current_log[log_pointer] >= SMALLEST_DIGIT && current_log[log_pointer] <= LARGEST_DIGIT)
    {
        time = time * 10 + (current_log[log_pointer] - SMALLEST_DIGIT);
        log_pointer++;
    }
    int *result = malloc(3 * sizeof(int));
    result[RESULT_FUNC_ID_INDEX] = func_id;
    result[RESULT_IS_START_INDEX] = isStart;
    result[RESULT_TIME_INDEX] = time;
    return result;
}

int *exclusiveTime(int n, char **logs, int logsSize, int *returnSize)
{
    int my_stack[MY_STACK_SIZE];
    int stack_top = -1;
    int prevTime = 0;
    int *res = calloc(n, sizeof(int));
    for (int i = 0; i < logsSize; i++)
    {
        char *current_log = logs[i];

        int *logDetails = getLogDetails(current_log);
        int func_id = logDetails[RESULT_FUNC_ID_INDEX];
        int isStart = logDetails[RESULT_IS_START_INDEX];
        int time = logDetails[RESULT_TIME_INDEX];
        free(logDetails);

        if (isStart)
        {
            // The current function takes time until the new one starts
            if (stack_top >= 0)
            {
                res[my_stack[stack_top]] += time - prevTime;
            }
            my_stack[++stack_top] = func_id; // push
            prevTime = time;
        }
        else
        {
            // Ending function runs until end of timestamp
            res[my_stack[stack_top--]] += time - prevTime + 1;
            prevTime = time + 1; // next function starts after this tick
        }
    }

    *returnSize = n;
    return res;
}

int main()
{
    char *logs[] = {"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"};
    int returnSize;
    int n = 1;
    int logsSize = 6;
    int *result = exclusiveTime(n, logs, logsSize, &returnSize);
    printf("Result: ");
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}