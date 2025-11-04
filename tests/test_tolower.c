/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <ctype.h>

void test_tolower(void)
{
	printf("\n=== Testing ft_tolower ===\n");

	// Uppercase to lowercase
	for (int i = 'A'; i <= 'Z'; i++)
		test_assert(ft_tolower(i) == tolower(i), "tolower: uppercase");
	
	// Already lowercase (should remain same)
	for (int i = 'a'; i <= 'z'; i++)
		test_assert(ft_tolower(i) == tolower(i), "tolower: lowercase");
	
	// Non-letters (should remain same)
	test_assert(ft_tolower('0') == tolower('0'), "tolower: digit");
	test_assert(ft_tolower('9') == tolower('9'), "tolower: digit");
	test_assert(ft_tolower(' ') == tolower(' '), "tolower: space");
	test_assert(ft_tolower('!') == tolower('!'), "tolower: exclamation");
	test_assert(ft_tolower('@') == tolower('@'), "tolower: at symbol");
	
	// Edge cases
	test_assert(ft_tolower(0) == tolower(0), "tolower: null");
	test_assert(ft_tolower(127) == tolower(127), "tolower: DEL");
	test_assert(ft_tolower(-1) == tolower(-1), "tolower: -1");
	test_assert(ft_tolower(256) == tolower(256), "tolower: 256");
}

