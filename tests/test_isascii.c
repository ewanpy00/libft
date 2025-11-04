/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <ctype.h>

void test_isascii(void)
{
	printf("\n=== Testing ft_isascii ===\n");

	// Valid ASCII (0-127)
	for (int i = 0; i <= 127; i++)
		test_assert(ft_isascii(i) == 1, "isascii: valid ASCII");
	
	// Invalid ASCII (>127)
	test_assert(ft_isascii(128) == 0, "isascii: 128");
	test_assert(ft_isascii(255) == 0, "isascii: 255");
	test_assert(ft_isascii(256) == 0, "isascii: 256");
	test_assert(ft_isascii(-1) == 0, "isascii: -1");
	test_assert(ft_isascii(-128) == 0, "isascii: -128");
	
	// Common characters
	test_assert(ft_isascii('a') == 1, "isascii: lowercase letter");
	test_assert(ft_isascii('A') == 1, "isascii: uppercase letter");
	test_assert(ft_isascii('0') == 1, "isascii: digit");
	test_assert(ft_isascii(' ') == 1, "isascii: space");
	test_assert(ft_isascii('\n') == 1, "isascii: newline");
	test_assert(ft_isascii(0) == 1, "isascii: null");
	test_assert(ft_isascii(127) == 1, "isascii: DEL");
}

