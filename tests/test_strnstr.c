/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"

void test_strnstr(void)
{
	printf("\n=== Testing ft_strnstr ===\n");

	const char *big = "hello world";
	
	// Substring found
	test_assert(ft_strnstr(big, "hello", 11) == strnstr(big, "hello", 11), "strnstr: found at start");
	test_assert(ft_strnstr(big, "world", 11) == strnstr(big, "world", 11), "strnstr: found in middle");
	test_assert(ft_strnstr(big, "lo", 11) == strnstr(big, "lo", 11), "strnstr: found substring");
	test_assert(ft_strnstr(big, "o", 11) == strnstr(big, "o", 11), "strnstr: single char");
	
	// Substring not found
	test_assert(ft_strnstr(big, "xyz", 11) == strnstr(big, "xyz", 11), "strnstr: not found");
	test_assert(ft_strnstr(big, "hello!", 11) == strnstr(big, "hello!", 11), "strnstr: too long");
	
	// Empty little
	test_assert(ft_strnstr(big, "", 11) == strnstr(big, "", 11), "strnstr: empty little");
	
	// Limited search length
	test_assert(ft_strnstr(big, "world", 7) == strnstr(big, "world", 7), "strnstr: not in range");
	test_assert(ft_strnstr(big, "hello", 5) == strnstr(big, "hello", 5), "strnstr: found in range");
	
	// Zero length
	test_assert(ft_strnstr(big, "hello", 0) == strnstr(big, "hello", 0), "strnstr: zero length");
	
	// Multiple occurrences (should return first)
	const char *multi = "hello hello";
	test_assert(ft_strnstr(multi, "hello", 11) == strnstr(multi, "hello", 11), "strnstr: multiple occurrences");
	
	// Partial match
	test_assert(ft_strnstr(big, "world!", 11) == strnstr(big, "world!", 11), "strnstr: partial match");
}

