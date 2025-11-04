/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <ctype.h>

void test_toupper(void)
{
	printf("\n=== Testing ft_toupper ===\n");

	// Lowercase to uppercase
	for (int i = 'a'; i <= 'z'; i++)
		test_assert(ft_toupper(i) == toupper(i), "toupper: lowercase");
	
	// Already uppercase (should remain same)
	for (int i = 'A'; i <= 'Z'; i++)
		test_assert(ft_toupper(i) == toupper(i), "toupper: uppercase");
	
	// Non-letters (should remain same)
	test_assert(ft_toupper('0') == toupper('0'), "toupper: digit");
	test_assert(ft_toupper('9') == toupper('9'), "toupper: digit");
	test_assert(ft_toupper(' ') == toupper(' '), "toupper: space");
	test_assert(ft_toupper('!') == toupper('!'), "toupper: exclamation");
	test_assert(ft_toupper('@') == toupper('@'), "toupper: at symbol");
	
	// Edge cases
	test_assert(ft_toupper(0) == toupper(0), "toupper: null");
	test_assert(ft_toupper(127) == toupper(127), "toupper: DEL");
	test_assert(ft_toupper(-1) == toupper(-1), "toupper: -1");
	test_assert(ft_toupper(256) == toupper(256), "toupper: 256");
}

