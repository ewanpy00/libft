/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <ctype.h>

void test_isalnum(void)
{
	printf("\n=== Testing ft_isalnum ===\n");

	// Digits
	for (int i = '0'; i <= '9'; i++)
		test_assert(ft_isalnum(i) == isalnum(i), "isalnum: digit");
	
	// Lowercase letters
	for (int i = 'a'; i <= 'z'; i++)
		test_assert(ft_isalnum(i) == isalnum(i), "isalnum: lowercase");
	
	// Uppercase letters
	for (int i = 'A'; i <= 'Z'; i++)
		test_assert(ft_isalnum(i) == isalnum(i), "isalnum: uppercase");
	
	// Non-alphanumeric
	test_assert(ft_isalnum(' ') == isalnum(' '), "isalnum: space");
	test_assert(ft_isalnum('!') == isalnum('!'), "isalnum: exclamation");
	test_assert(ft_isalnum('@') == isalnum('@'), "isalnum: at symbol");
	test_assert(ft_isalnum('[') == isalnum('['), "isalnum: opening bracket");
	
	// Edge cases
	test_assert(ft_isalnum(0) == isalnum(0), "isalnum: null terminator");
	test_assert(ft_isalnum(127) == isalnum(127), "isalnum: DEL");
	test_assert(ft_isalnum(-1) == isalnum(-1), "isalnum: -1");
}

