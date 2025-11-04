/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:47:42 by wcorrea-          #+#    #+#             */
/*   Updated: 2025/11/02 11:10:47 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	sublen;
	char	*trimmed;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && is_set(s1[i], set))
		i++;
	j = len - 1;
	while (j > i && is_set(s1[j], set))
		j--;
	sublen = j - i;
	trimmed = (char *)malloc(sizeof(char) * (sublen + 2));
	if (!trimmed)
		return (NULL);
	ft_memcpy(trimmed, s1 + i, sublen + 1);
	trimmed[sublen + 1] = '\0';
	return (trimmed);
}

// void    test_strtrim(const char *s1, const char *set, const char *expected)
// {
//     char *result = ft_strtrim(s1, set);

//     printf("--- Test Case ---\n");
//     printf("Input String (s1): \"%s\"\n", s1);
//     printf("Trim Set (set):    \"%s\"\n", set);
//     printf("Expected Output:   \"%s\"\n", expected);
//     printf("Actual Output:     \"%s\"\n", result);

//     if (result == NULL && expected == NULL) {
//         printf("RESULT: ✅ PASS (Both NULL)\n\n");
//     } else if (result == NULL || expected == NULL) {
//         printf("RESULT: ❌ FAIL (One is NULL)\n\n");
//     } else if (strcmp(result, expected) == 0) {
//         printf("RESULT: ✅ PASS\n\n");
//     } else {
//         printf("RESULT: ❌ FAIL\n\n");
//     }

//     // Free the memory allocated by ft_strtrim
//     if (result != NULL)
//         free(result);
// }

// // --- Main Test Function ---
// int main(void)
// {
//     // 1. Basic Case (Trimming leading and trailing characters)
//     test_strtrim("  hello world  ", " ", "hello world");

//     // 2. Mixed Characters (Trimming multiple different characters)
//     test_strtrim("...---hello world---...", ".-", "hello world");

//     // 3. No Trimming Needed (Set characters are only in the middle)
//     test_strtrim("abc_def_ghi", "_", "abc_def_ghi");

//     // 4. Trims the Entire String (s1 contains only characters from set)
//     test_strtrim("xxxXxxxXxxx", "xX", "");

//     // 5. Empty Set (Should return a copy of s1)
//     test_strtrim("  hello world  ", "", "  hello world  ");

//     // 6. Empty Input String (s1 is empty)
//     test_strtrim("", "abc", "");

//     // 7. NULL/Empty Output (A single character left after trim)
//     test_strtrim("abcde", "aed", "bc");

//     // 8. Trim only leading characters
//     test_strtrim("   hello", " ", "hello");

//     // 9. Trim only trailing characters
//     test_strtrim("hello   ", " ", "hello");

//     return (0);
// }