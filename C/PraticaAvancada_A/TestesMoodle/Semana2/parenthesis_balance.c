#include <stdio.h>
#include <stdlib.h>

int main()
{
    char expression[1000];
    while (fgets(expression, sizeof(expression), stdin) != NULL)
    {
        int count = 0;
        int iterator = 0;
        int is_ok = 1;
        char current = expression[iterator];

        while (current != '\0')
        {
            if (current == '(') count++;
            if (current == ')') count--;
            if (count < 0) 
            {
                is_ok = 0;
                break;
            }
            iterator++;
            current = expression[iterator];
        }

        if (is_ok && (!count)) printf("correct\n");
        else printf("incorrect\n");
    }

    return 0;
}
