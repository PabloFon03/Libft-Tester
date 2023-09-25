#include <stdio.h>
#include "libft.h"

int		run_makefile(void);
void	test_atoi(void);
void	test_substr(void);
void	test_strjoin(void);
void	test_strtrim(void);
void	test_split(void);
void	test_itoa(void);
void	test_striteri(void);
void	test_strmapi(void);
void	test_putnbr(void);

int	main(void)
{
	printf("Libft Tester By JustAGreenToast\nGood Luck! :D\n\n");
	if (!run_makefile())
		return (1);
	test_atoi();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_striteri();
	test_strmapi();
	test_putnbr();
	return (0);
}

int	run_makefile(void)
{
	printf("Probando makefile... (make re)\n");
	if (system("make re"))
	{
		printf("ERROR: Algo ha fallado con Makefile :(\n");
		return (0);
	}
	else
	{
		printf("Makefile funciona! :D\n");
		return (1);
	}
}

void	print_separator(void)
{
	for (int i = 0; i < 69; i++)
		printf("-");
	printf("\n");
}

void	show_external_functions(char const *s)
{
	printf("Funciones externas en %s:\n", s);
	system(ft_strjoin("nm -u ", ft_strjoin(s, ".o")));
	printf("\n");
}

void	test_atoi(void)
{
	const char	*str[] =
	{
		"0",
		"1",
		"42",
		"-3",
		"  -247 a45",
		"	+35",
		"-0",
		"",
		"2147483647",
		"-2147483648"
	};
	print_separator();
	printf("[FT_ATOI]\n\n");
	show_external_functions("ft_atoi");
	for (int i = 0; i < 10; i++)
	{
		printf("ft_atoi(\"%s\") -> %d\n", str[i], ft_atoi(str[i]));
	}
	print_separator();
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
		if (result)
			free(result);
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
		if (result)
			free(result);
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
		if (result)
		{
			int word = 0;
			while (result[word])
				free(result[word++]);
			free(result);
		}
	}
	print_separator();
}

void	test_itoa(void)
{
	int	nbr[] =
	{
		0,
		3,
		42,
		-7,
		-2048,
		2147483647,
		-2147483648
	};
	print_separator();
	printf("[FT_ITOA]\n\n");
	show_external_functions("ft_itoa");
	for (int i = 0; i < 7; i++)
	{
		printf("ft_itoa(%d) -> \"%s\"\n", nbr[i], ft_itoa(nbr[i]));
	}
	print_separator();
}

void	f_iteri(unsigned int n, char *c)
{
	*c = n % 2 == 0 ? ft_toupper(*c) : ft_tolower(*c);
}

void	test_striteri(void)
{
	const char	*str[] =
	{
		"abcd",
		"ABCD",
		"aBcD",
		"AbCd",
		""
	};
	print_separator();
	printf("[FT_STRITERI]\n\n");
	show_external_functions("ft_striteri");
	for (int i = 0; i < 5; i++)
	{
		char *new_str = ft_strdup(str[i]);
		if (new_str)
		{
			ft_striteri(new_str, &f_iteri);
			printf("ft_striteri(\"%s\") -> \"%s\"\n", str[i], new_str);
			free(new_str);
		}
		else
			printf("ERROR: Failed to allocate memory :(\n");
	}
	print_separator();
}

char	f_mapi(unsigned int n, char c)
{
	return (n % 2 == 0 ? (char)ft_toupper(c) : (char)ft_tolower(c));
}

void	test_strmapi(void)
{
	const char	*str[] =
	{
		"abcd",
		"ABCD",
		"aBcD",
		"AbCd",
		""
	};
	print_separator();
	printf("[FT_STRMAPI]\n\n");
	show_external_functions("ft_strmapi");
	for (int i = 0; i < 5; i++)
	{
		char *result = ft_strmapi(str[i], &f_mapi);
		if (result)
		{
			printf("ft_strmapi(\"%s\") -> \"%s\"\n", str[i], result);
			free(result);
		}
		else
			printf("ERROR: Failed to allocate memory :(\n");
	}
	print_separator();
}

void	test_putnbr(void)
{
	int	nbr[] =
	{
		0,
		3,
		42,
		-7,
		-2048,
		2147483647,
		-2147483648
	};
	print_separator();
	printf("[FT_PUTNBR_FD]\n\n");
	show_external_functions("ft_putnbr_fd");
	for (int i = 0; i < 7; i++)
	{
		printf(" <- ft_putnbr_fd(%d, 1)", nbr[i]);
		ft_putnbr_fd(nbr[i], 1);
		printf("\n");
	}
	print_separator();
}
