#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int my_stack[50001];
int top_value_index = -1;

bool isOperation(char *token)
{
    if (strlen(token) > 1 || isdigit(token[0]))
    {
        return false;
    }
    if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
    {
        return true;
    }
    return false;
}

int calculateNewToken(int first_number, int second_number, char *operation)
{
    int result;

    if (operation[0] == '+')
    {
        result = first_number + second_number;
    }
    else if (operation[0] == '-')
    {
        result = first_number - second_number;
    }
    else if (operation[0] == '/')
    {
        result = first_number / second_number;
    }
    else if (operation[0] == '*')
    {
        result = first_number * second_number;
    }

    return result;
}

int evalRPN(char **tokens, int tokensSize)
{

    for (int i = 0; i < tokensSize; i++)
    {
        char *current_token = tokens[i];
        if (isOperation(current_token))
        {
            if (top_value_index == -1)
            {
                continue;
            }

            int second_number = my_stack[top_value_index--];

            if (top_value_index == -1)
            {
                continue;
            }
            int first_number = my_stack[top_value_index--];
            int operation_result = calculateNewToken(first_number, second_number, current_token);
            my_stack[++top_value_index] = operation_result;
        }
        else
        {
            int current_value = atoi(current_token);
            my_stack[++top_value_index] = current_value;
        }
    }

    if (top_value_index == -1)
    {
        return 0;
    }

    return my_stack[top_value_index];
}

int main()
{
    char *tokens[] = {"4", "13", "5", "*", "+"};
    int tokensSize = 5;
    int result = evalRPN(tokens, tokensSize);
    printf("Result: %d\n", result);
    return 0;
}