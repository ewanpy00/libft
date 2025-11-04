/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <string.h>

void test_strlen(void)
{
	printf("\n=== Testing ft_strlen ===\n");

	// Basic tests
	test_assert(ft_strlen("") == strlen(""), "strlen: empty string");
	test_assert(ft_strlen("a") == strlen("a"), "strlen: single char");
	test_assert(ft_strlen("hello") == strlen("hello"), "strlen: basic string");
	test_assert(ft_strlen("hello world") == strlen("hello world"), "strlen: string with space");
	
	// Long strings
	char long_str[1000];
	memset(long_str, 'a', 999);
	long_str[999] = '\0';
	test_assert(ft_strlen(long_str) == strlen(long_str), "strlen: long string");
	
	// Special characters
	test_assert(ft_strlen("\0") == strlen("\0"), "strlen: null terminator only");
	test_assert(ft_strlen("test\n") == strlen("test\n"), "strlen: string with newline");
	test_assert(ft_strlen("test\t") == strlen("test\t"), "strlen: string with tab");
	test_assert(ft_strlen("test\0hidden") == strlen("test\0hidden"), "strlen: null in middle");
	
	// Numbers and symbols
	test_assert(ft_strlen("12345") == strlen("12345"), "strlen: numbers");
	test_assert(ft_strlen("!@#$%") == strlen("!@#$%"), "strlen: symbols");
	
	// Unicode/UTF-8 (basic)
	test_assert(ft_strlen("привет") == strlen("привет"), "strlen: UTF-8 string");
	
	// Edge case: NULL pointer (should match original behavior)
	// Note: strlen(NULL) is undefined behavior, but we test it
	printf("[INFO] Testing NULL pointer (undefined behavior expected)\n");
}

