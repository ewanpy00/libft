/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:46:42 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/01 22:55:28 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(strlen(s1) + strlen(s2) + 1);
	ptr = str;
	if (!str)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (ptr);
}

// char	*ft_strjoin(char const *s1, char const *s2);

// int	main(void)
// {
// 	char *result;

// 	// Test 1: Normal strings
// 	result = ft_strjoin("Hello, ", "World!");
// 	printf("Test 1: %s\n", result);
// 	free(result);

// 	// Test 2: First string empty
// 	result = ft_strjoin("", "Non-empty");
// 	printf("Test 2: %s\n", result);
// 	free(result);

// 	// Test 3: Second string empty
// 	result = ft_strjoin("Non-empty", "");
// 	printf("Test 3: %s\n", result);
// 	free(result);

// 	// Test 4: Both strings empty
// 	result = ft_strjoin("", "");
// 	printf("Test 4: '%s'\n", result); // quotes help visualize empty string
// 	free(result);

// 	// Test 5: Long strings
// 	result = ft_strjoin("This is a longer string, ",
// 			"and this is another one.");
// 	printf("Test 5: %s\n", result);
// 	free(result);

// 	// Test 6: Strings with special characters
// 	result = ft_strjoin("Line1\n", "Line2\tTabbed");
// 	printf("Test 6: %s\n", result);
// 	free(result);

// 	return (0);
// }