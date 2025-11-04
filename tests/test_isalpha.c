/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <ctype.h>

void test_isalpha(void)
{
	printf("\n=== Testing ft_isalpha ===\n");

	// Lowercase letters
	test_assert(ft_isalpha('a') == isalpha('a'), "isalpha: lowercase 'a'");
	test_assert(ft_isalpha('z') == isalpha('z'), "isalpha: lowercase 'z'");
	test_assert(ft_isalpha('m') == isalpha('m'), "isalpha: lowercase 'm'");
	
	// Uppercase letters
	test_assert(ft_isalpha('A') == isalpha('A'), "isalpha: uppercase 'A'");
	test_assert(ft_isalpha('Z') == isalpha('Z'), "isalpha: uppercase 'Z'");
	test_assert(ft_isalpha('M') == isalpha('M'), "isalpha: uppercase 'M'");
	
	// Non-alphabetic
	test_assert(ft_isalpha('0') == isalpha('0'), "isalpha: digit '0'");
	test_assert(ft_isalpha('9') == isalpha('9'), "isalpha: digit '9'");
	test_assert(ft_isalpha('5') == isalpha('5'), "isalpha: digit '5'");
	test_assert(ft_isalpha(' ') == isalpha(' '), "isalpha: space");
	test_assert(ft_isalpha('\t') == isalpha('\t'), "isalpha: tab");
	test_assert(ft_isalpha('\n') == isalpha('\n'), "isalpha: newline");
	test_assert(ft_isalpha('!') == isalpha('!'), "isalpha: exclamation");
	test_assert(ft_isalpha('@') == isalpha('@'), "isalpha: at symbol");
	test_assert(ft_isalpha('[') == isalpha('['), "isalpha: opening bracket");
	test_assert(ft_isalpha('{') == isalpha('{'), "isalpha: opening brace");
	
	// Edge cases
	test_assert(ft_isalpha(0) == isalpha(0), "isalpha: null terminator");
	test_assert(ft_isalpha(127) == isalpha(127), "isalpha: DEL");
	test_assert(ft_isalpha(128) == isalpha(128), "isalpha: 128");
	test_assert(ft_isalpha(-1) == isalpha(-1), "isalpha: -1");
	test_assert(ft_isalpha(256) == isalpha(256), "isalpha: 256");
}

