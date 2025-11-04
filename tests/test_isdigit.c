/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <ctype.h>

void test_isdigit(void)
{
	printf("\n=== Testing ft_isdigit ===\n");

	// Digits
	for (int i = '0'; i <= '9'; i++)
		test_assert(ft_isdigit(i) == isdigit(i), "isdigit: digit");
	
	// Non-digits
	test_assert(ft_isdigit('a') == isdigit('a'), "isdigit: lowercase letter");
	test_assert(ft_isdigit('A') == isdigit('A'), "isdigit: uppercase letter");
	test_assert(ft_isdigit(' ') == isdigit(' '), "isdigit: space");
	test_assert(ft_isdigit('!') == isdigit('!'), "isdigit: exclamation");
	test_assert(ft_isdigit('@') == isdigit('@'), "isdigit: at symbol");
	
	// Edge cases
	test_assert(ft_isdigit(0) == isdigit(0), "isdigit: null terminator");
	test_assert(ft_isdigit(127) == isdigit(127), "isdigit: DEL");
	test_assert(ft_isdigit(-1) == isdigit(-1), "isdigit: -1");
	test_assert(ft_isdigit(256) == isdigit(256), "isdigit: 256");
}

