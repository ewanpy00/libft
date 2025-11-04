/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"

void test_strchr(void)
{
	printf("\n=== Testing ft_strchr ===\n");

	const char *str = "hello world";
	
	// Character found
	test_assert(ft_strchr(str, 'h') == strchr(str, 'h'), "strchr: first char");
	test_assert(ft_strchr(str, 'e') == strchr(str, 'e'), "strchr: second char");
	test_assert(ft_strchr(str, 'l') == strchr(str, 'l'), "strchr: multiple occurrence (first)");
	test_assert(ft_strchr(str, 'o') == strchr(str, 'o'), "strchr: multiple occurrence");
	test_assert(ft_strchr(str, ' ') == strchr(str, ' '), "strchr: space");
	test_assert(ft_strchr(str, 'd') == strchr(str, 'd'), "strchr: last char");
	
	// Character not found
	test_assert(ft_strchr(str, 'x') == strchr(str, 'x'), "strchr: not found");
	test_assert(ft_strchr(str, 'Z') == strchr(str, 'Z'), "strchr: uppercase not found");
	
	// Null terminator
	test_assert(ft_strchr(str, '\0') == strchr(str, '\0'), "strchr: null terminator");
	
	// Empty string
	test_assert(ft_strchr("", 'a') == strchr("", 'a'), "strchr: empty string");
	test_assert(ft_strchr("", '\0') == strchr("", '\0'), "strchr: empty string null");
	
	// Single character
	test_assert(ft_strchr("a", 'a') == strchr("a", 'a'), "strchr: single char match");
	test_assert(ft_strchr("a", 'b') == strchr("a", 'b'), "strchr: single char no match");
	
	// Special characters
	test_assert(ft_strchr("test\n", '\n') == strchr("test\n", '\n'), "strchr: newline");
	test_assert(ft_strchr("test\t", '\t') == strchr("test\t", '\t'), "strchr: tab");
	
	// Integer overflow (char is cast to int)
	test_assert(ft_strchr(str, 256 + 'h') == strchr(str, 256 + 'h'), "strchr: overflow");
	test_assert(ft_strchr(str, -1) == strchr(str, -1), "strchr: negative");
}

