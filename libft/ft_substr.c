/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:13:21 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/05 10:34:45 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));

	if (len > slen - start)
		len = slen - start;

	substr = malloc(len + 1);
	if (!substr)
		return (NULL);

	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

// void	run_test(const char *s, unsigned int start, size_t len,
// 		const char *expected)
// {
// 	char	*result;

// 	result = ft_substr(s, start, len);
// 	printf("Testing with s=\"%s\", start=%u, len=%zu\n", s, start, len);
// 	printf("Expected: \"%s\"\n", expected);
// 	printf("Got:      \"%s\"\n", result);
// 	if (result == NULL && expected == NULL)
// 	{
// 		printf("✅ Test Passed (both NULL)\n\n");
// 	}
// 	else if (result != NULL && expected != NULL && strcmp(result,
// 			expected) == 0)
// 	{
// 		printf("✅ Test Passed\n\n");
// 	}
// 	else
// 	{
// 		printf("❌ Test Failed\n\n");
// 	}
// 	// Free the allocated memory to prevent leaks
// 	if (result)
// 		free(result);
// }

// int	main(void)
// {
// 	// --- Test cases ---

// 	// 1. Standard case: Extract from the middle of the string
// 	run_test("Hello World", 6, 5, "World");

// 	// 2. Extract from the beginning of the string
// 	run_test("Hello World", 0, 5, "Hello");

// 	// 3. Extract to the end of the string
// 	run_test("Hello World", 6, 10, "World");

// 	// 4. `len` is greater than the remaining string length
// 	run_test("Hello World", 6, 20, "World");

// 	// 5. `start` index is at the end of the string
// 	run_test("Hello", 5, 5, "");

// 	// 6. `start` index is out of bounds
// 	run_test("Hello", 10, 5, "");

// 	// 7. `len` is 0
// 	run_test("Hello World", 6, 0, "");

// 	// 8. Empty string input
// 	run_test("", 0, 5, "");

// 	// 9. Edge case with `len` 0 and `start` out of bounds
// 	run_test("Hello", 10, 0, "");

// 	// 10. `start` index is at 0 and `len` is 0
// 	run_test("Hello", 0, 0, "");

// 	return (0);
// }