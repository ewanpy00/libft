/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:22:54 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/10/31 14:06:05 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

int is_set(const char *set, char c)
{
	while(*set)
	{
		if(*set == c)
			return 1;
		set++;
	}
	return 0;
}

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t i;
    size_t j;
    size_t len;
    char *result;
    
    if (!s1)
        return (NULL);
    i = 0;
    while (s1[i] && is_set(set, s1[i]))
        i++;
    len = 0;
    while (s1[len])
        len++;
    j = len;
    if (i == j)
	{
        result = (char *)malloc(1);
        if (result)
            *result = '\0';
        return (result);
    }
    while (j > i && is_set(set, s1[j - 1]))
        j--;

    result = (char *)malloc(j - i + 1);
    if (!result)
        return (NULL);
    len = 0;
    while (i < j)
        result[len++] = s1[i++];
    result[len] = '\0';

    return (result);
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