/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"

void test_strrchr(void)
{
	printf("\n=== Testing ft_strrchr ===\n");

	const char *str = "hello world";
	
	// Character found (should return last occurrence)
	test_assert(ft_strrchr(str, 'h') == strrchr(str, 'h'), "strrchr: first char");
	test_assert(ft_strrchr(str, 'l') == strrchr(str, 'l'), "strrchr: multiple occurrence (last)");
	test_assert(ft_strrchr(str, 'o') == strrchr(str, 'o'), "strrchr: multiple occurrence (last)");
	test_assert(ft_strrchr(str, 'd') == strrchr(str, 'd'), "strrchr: last char");
	
	// Character not found
	test_assert(ft_strrchr(str, 'x') == strrchr(str, 'x'), "strrchr: not found");
	
	// Null terminator
	test_assert(ft_strrchr(str, '\0') == strrchr(str, '\0'), "strrchr: null terminator");
	
	// Empty string
	test_assert(ft_strrchr("", 'a') == strrchr("", 'a'), "strrchr: empty string");
	test_assert(ft_strrchr("", '\0') == strrchr("", '\0'), "strrchr: empty string null");
	
	// Single character
	test_assert(ft_strrchr("a", 'a') == strrchr("a", 'a'), "strrchr: single char match");
	test_assert(ft_strrchr("a", 'b') == strrchr("a", 'b'), "strrchr: single char no match");
	
	// All same characters
	const char *same = "aaaa";
	test_assert(ft_strrchr(same, 'a') == strrchr(same, 'a'), "strrchr: all same chars");
}

