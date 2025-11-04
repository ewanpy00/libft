/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"

void test_strncmp(void)
{
	printf("\n=== Testing ft_strncmp ===\n");

	// Equal strings
	test_assert(ft_strncmp("hello", "hello", 5) == strncmp("hello", "hello", 5), "strncmp: equal strings");
	test_assert(ft_strncmp("hello", "hello", 10) == strncmp("hello", "hello", 10), "strncmp: equal longer n");
	test_assert(ft_strncmp("", "", 0) == strncmp("", "", 0), "strncmp: empty strings");
	
	// Different strings
	test_assert((ft_strncmp("hello", "world", 5) > 0) == (strncmp("hello", "world", 5) > 0), "strncmp: first greater");
	test_assert((ft_strncmp("world", "hello", 5) < 0) == (strncmp("world", "hello", 5) < 0), "strncmp: first less");
	test_assert((ft_strncmp("abc", "abd", 3) < 0) == (strncmp("abc", "abd", 3) < 0), "strncmp: last char diff");
	
	// Compare less than full length
	test_assert(ft_strncmp("hello", "hella", 4) == strncmp("hello", "hella", 4), "strncmp: partial equal");
	test_assert(ft_strncmp("hello", "hella", 5) == strncmp("hello", "hella", 5), "strncmp: partial diff");
	
	// Compare more than string length
	test_assert(ft_strncmp("hi", "hello", 10) == strncmp("hi", "hello", 10), "strncmp: n longer than str1");
	test_assert(ft_strncmp("hello", "hi", 10) == strncmp("hello", "hi", 10), "strncmp: n longer than str2");
	
	// Zero length
	test_assert(ft_strncmp("hello", "world", 0) == strncmp("hello", "world", 0), "strncmp: n=0");
	
	// Case sensitivity
	test_assert((ft_strncmp("Hello", "hello", 5) < 0) == (strncmp("Hello", "hello", 5) < 0), "strncmp: case diff");
	
	// Null terminator in middle
	test_assert(ft_strncmp("test\0hidden", "test\0visible", 12) == strncmp("test\0hidden", "test\0visible", 12), "strncmp: null in middle");
}

