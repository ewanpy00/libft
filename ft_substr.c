/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipykhtin <ipykhtin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:13:21 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/10/29 15:46:23 by ipykhtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	size_t	i;
	size_t	j;
	char	*substr;

	i = 0;
	j = 0;
	while (i < start && s[i])
		i++;
	substr = malloc(ft_strlen((char *)&s[i]) + 1);
	if (!substr)
		return (NULL);
	len = len + i;
	while (s[i] && i < len)
	{
		substr[j] = s[i];
		i++;
		j++;
	}
	substr[j] = '\0';
	return (substr);
}

void	run_test(const char *s, unsigned int start, size_t len,
		const char *expected)
{
	char	*result;

	result = ft_substr(s, start, len);
	printf("Testing with s=\"%s\", start=%u, len=%zu\n", s, start, len);
	printf("Expected: \"%s\"\n", expected);
	printf("Got:      \"%s\"\n", result);
	if (result == NULL && expected == NULL)
	{
		printf("✅ Test Passed (both NULL)\n\n");
	}
	else if (result != NULL && expected != NULL && strcmp(result,
			expected) == 0)
	{
		printf("✅ Test Passed\n\n");
	}
	else
	{
		printf("❌ Test Failed\n\n");
	}
	// Free the allocated memory to prevent leaks
	if (result)
		free(result);
}

int	main(void)
{
	// --- Test cases ---

	// 1. Standard case: Extract from the middle of the string
	run_test("Hello World", 6, 5, "World");

	// 2. Extract from the beginning of the string
	run_test("Hello World", 0, 5, "Hello");

	// 3. Extract to the end of the string
	run_test("Hello World", 6, 10, "World");

	// 4. `len` is greater than the remaining string length
	run_test("Hello World", 6, 20, "World");

	// 5. `start` index is at the end of the string
	run_test("Hello", 5, 5, "");

	// 6. `start` index is out of bounds
	run_test("Hello", 10, 5, "");

	// 7. `len` is 0
	run_test("Hello World", 6, 0, "");

	// 8. Empty string input
	run_test("", 0, 5, "");

	// 9. Edge case with `len` 0 and `start` out of bounds
	run_test("Hello", 10, 0, "");

	// 10. `start` index is at 0 and `len` is 0
	run_test("Hello", 0, 0, "");

	return (0);
}