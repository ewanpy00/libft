/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:06:10 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/05 21:41:58 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **strs, size_t j)
{
	while (j--)
		free(strs[j]);
	free(strs);
}

static size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static char	*word_splitter(const char *str, char c)
{
	char	*res;
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	add_word(char **res, const char *s, char c, size_t *i)
{
	res[*i] = word_splitter(s, c);
	if (!res[*i])
	{
		free_split(res, *i);
		return (0);
	}
	while (*s && *s != c)
		s++;
	(*i)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	res = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!add_word(res, &s[i], c, &j))
				return (NULL);
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}

// int main(){
//     char *str = "   Hello  welcome to 42 ";
//     char c = ' ';

//     ft_split(str, c);
// }

// void print_split_result(char **result)
// {
//     int i = 0;
//     if (!result)
//     {
//         printf("Result is NULL\n");
//         return ;
//     }
//     while (result[i])
//     {
//         printf("result[%d] = \"%s\"\n", i, result[i]);
//         i++;
//     }
//     printf("result[%d] = NULL\n", i);
// }

// void free_split(char **result)
// {
//     int i = 0;
//     if (!result)
//         return ;
//     while (result[i])
//     {
//         free(result[i]);
//         i++;
//     }
//     free(result);
// }

// int main(void)
// {
//     char *tests[] = {
//         "Hello world this is a test",
//         "   Leading spaces",
//         "Trailing spaces   ",
//         "  Multiple   spaces  between words  ",
//         "",
//         "NoDelimiterHere",
//         "/////", // if delimiter is '/'
//         "/split/this/string/",
//         NULL
//     };

//     char delimiters[] = {' ', ' ', ' ', ' ', ' ', ' ', '/', '/'};

//     printf("=== Testing ft_split ===\n\n");

//     for (int i = 0; tests[i] != NULL; i++)
//     {
//         printf("Test %d: \"%s\" (delimiter = '%c')\n", i + 1, tests[i],
// delimiters[i]);
//         char **result = ft_split(tests[i], delimiters[i]);
//         print_split_result(result);
//         free_split(result);
//         printf("--------------------------------\n");
//     }
//     return (0);x
// }