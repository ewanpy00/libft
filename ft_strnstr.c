/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:43:34 by ipykhtin          #+#    #+#             */
/*   Updated: 2025/11/01 22:27:03 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hp;
	char	*np;
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		np = (char *)needle;
		hp = (char *)haystack;
		i = len;
		while (*hp == *np && i > 0 && *np != '\0')
		{
			np++;
			hp++;
			i--;
		}
		if (*np == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *haystack1 = "Hello, world!";
// 	char *needle1 = "world";
// 	char *haystack2 = "abcdefg";
// 	char *needle2 = "def";
// 	char *haystack3 = "short";
// 	char *needle3 = "longneedle";
// 	char *haystack4 = "repeatpatternpattern";
// 	char *needle4 = "pattern";
// 	char *haystack5 = "short";
// 	char *needle5 = "";

// 	// Test Case 1: Normal Case - Needle exists in the haystack
// 	printf("Test 1 - Haystack: '%s', Needle: '%s'\n", haystack1, needle1);
// 	printf("Original strnstr: '%s'\n", strnstr(haystack1, needle1, 10));
// 	printf("Custom ft_strnstr: '%s'\n", ft_strnstr(haystack1, needle1, 10));
// 	printf("--------------------------------------------------\n");

// 	// Test Case 2: Substring at the end of the haystack
// 	printf("Test 2 - Haystack: '%s', Needle: '%s'\n", haystack2, needle2);
// 	printf("Original strnstr: '%s'\n", strnstr(haystack2, needle2, 6));
// 	printf("Custom ft_strnstr: '%s'\n", ft_strnstr(haystack2, needle2, 6));
// 	printf("--------------------------------------------------\n");

// 	// Test Case 3: Needle is longer than the haystack
// 	printf("Test 3 - Haystack: '%s', Needle: '%s'\n", haystack3, needle3);
// 	printf("Original strnstr: '%s'\n", strnstr(haystack3, needle3, 5));
// 	printf("Custom ft_strnstr: '%s'\n", ft_strnstr(haystack3, needle3, 5));
// 	printf("--------------------------------------------------\n");

// 	// Test Case 4: Multiple occurrences of the needle in the haystack
// 	printf("Test 4 - Haystack: '%s', Needle: '%s'\n", haystack4, needle4);
// 	printf("Original strnstr: '%s'\n", strnstr(haystack4, needle4, 20));
// 	printf("Custom ft_strnstr: '%s'\n", ft_strnstr(haystack4, needle4, 20));
// 	printf("--------------------------------------------------\n");

// 	// Test Case 5: Empty Needle
// 	printf("Test 5 - Haystack: '%s', Needle: '%s'\n", haystack5, needle5);
// 	printf("Original strnstr: '%s'\n", strnstr(haystack5, needle5, 5));
// 	printf("Custom ft_strnstr: '%s'\n", ft_strnstr(haystack5, needle5, 5));
// 	printf("--------------------------------------------------\n");

// 	// Test Case 6: Needle not found within len characters
// 	printf("Test 6 - Haystack: '%s', Needle: '%s'\n", haystack1, needle1);
// 	printf("Original strnstr: '%s'\n", strnstr(haystack1, needle1, 5));
// 	printf("Custom ft_strnstr: '%s'\n", ft_strnstr(haystack1, needle1, 5));
// 	printf("--------------------------------------------------\n");
// }