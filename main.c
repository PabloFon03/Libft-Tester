#include <stdio.h>
// #include "libft.h"

int main()
{
    printf("LibFt Tester By JustAGreenToast\nGood Luck! :D\n\n")
    test_split();
}

void print_separator()
{
    printf("----------------------------------------------------------------\n");
}

void    test_split()
{
    const char  *str[] = { "Hello World", "H elloWorld", "Hello    World", "Hello", " ", "", "      ", "       Hello      World       ", NULL };
    char split_char = ' ';
    for (int i = 0; i < ; i++)
    {
        printf("ft_split(\"%s\", '%c') -> ", str[i], split_char);
        char **result = split(str[i], split_char);
        while (result)
        {
            printf("\"%s\"", result++);
            if (result)
                printf(", ");
            else
                printf("\n");
        }
    }
}