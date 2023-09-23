#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

void	test_substr(void);
void	test_strjoin(void);
void	test_strtrim(void);
void	test_split(void);

int	main(void)
{
	printf("Libft Tester By JustAGreenToast\nGood Luck! :D\n\n");
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
}

void	print_separator(void)
{
	printf("---------------------------------------------------------------------\n");
}

void	show_external_functions(char const *s)
{
	printf("Funciones externas en %s:\n", s);
	system(ft_strjoin("nm -u ", ft_strjoin(s, ".o")));
	printf("\n");
}

void	test_substr(void)
{
    const char *str[] =
    {
        "abcdef",
        "abcdef",
        "abcdef",
        "abcdef",
        "abcdef",
        "abcdef",
        "abcdef",
        "abcdef",
        "",
        NULL
    };
	const size_t start[] =
    {
        0,
        0,
        0,
        2,
        7,
        0,
        0,
        9,
        0,
        0
    };
    const size_t length[] =
    {
        6,
        9,
        2,
        6,
        0,
        0,
        1,
        1,
        0,
        0
    };
	print_separator();
	printf("[FT_SUBSTR]\n\n");
	show_external_functions("ft_substr");
	for (int i = 0; i < 10; i++)
	{
		printf("ft_substr(\"%s\", %lu, %lu) -> ", str[i], start[i], length[i]);
		char *result = ft_substr(str[i], start[i], length[i]);
		if (!result)
			printf("NULL\n");
		else if (!result[0])
			printf("Nothing\n");
		else
            printf("\"%s\"\n", result);
	}
	print_separator();
}

void	test_strjoin(void)
{
	const char *s1[] =
	{
		"Part1",
		"Part1",
		"Part1",
		"",
		NULL,
		"",
		NULL
	};
    const char *s2[] =
    {
        "Part2",
        "",
        NULL,
		"Part2",
        "Part2",
        "",
        NULL
    };
	char split_char = ' ';
	print_separator();
	printf("[FT_STRJOIN]\n\n");
	show_external_functions("ft_strjoin");
	for (int i = 0; i < 7; i++)
	{
		printf("ft_strjoin(\"%s\", \"%s\") -> ", s1[i], s2[i]);
		char *result = ft_strjoin(s1[i], s2[i]);
		if (!result)
			printf("NULL\n");
		else if (!result[0])
			printf("Nothing\n");
		else
		    printf("\"%s\"\n", result);
	}
	print_separator();
}

void	test_strtrim(void)
{
	const char *str[] =
	{
        "01ABC10",
        "01ABC10",
        "01ABC10",
        "01ABC10",
		"",
		NULL,
        NULL,
        "01ABC10",
        "01ABC10"
	};
    const char *set[] =
    {
        "0",
        "1",
        "01",
		"01ABC",
        "",
        NULL,
        "01",
        "",
        NULL
    };
	char split_char = ' ';
	print_separator();
	printf("[FT_STRTRIM]\n\n");
	show_external_functions("ft_strjoin");
	for (int i = 0; i < 9; i++)
	{
		printf("ft_strtrim(\"%s\", \"%s\") -> ", str[i], set[i]);
		char *result = ft_strtrim(str[i], set[i]);
		if (!result)
			printf("NULL\n");
		else if (!result[0])
			printf("Nothing\n");
		else
			printf("\"%s\"\n", result);
	}
	print_separator();
}

void	test_split(void)
{
	const char *str[] =
    {
        "Hello World",
        "H elloWorld",
        "Hello    World",
		"Hello",
        " ",
        "",
        "      ",
        "       Hello      World       ",
        NULL
    };
	char split_char = ' ';
	print_separator();
	printf("[FT_SPLIT]\n\n");
	show_external_functions("ft_split");
	for (int i = 0; i < 9; i++)
	{
		printf("ft_split(\"%s\", '%c') -> ", str[i], split_char);
		char **result = ft_split(str[i], split_char);
		if (!result)
			printf("NULL\n");
		else if (!result[0])
			printf("Nothing\n");
		else
		{
			int word = 0;
			while (result[word])
			{
				printf("\"%s\"", result[word++]);
				printf(result[word] ? ", " : " \n");
			}
		}
	}
	print_separator();
}
