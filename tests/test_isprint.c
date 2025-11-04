/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <ctype.h>

void test_isprint(void)
{
	printf("\n=== Testing ft_isprint ===\n");

	// Printable (32-126)
	test_assert(ft_isprint(' ') == isprint(' '), "isprint: space (32)");
	test_assert(ft_isprint('!') == isprint('!'), "isprint: exclamation");
	test_assert(ft_isprint('A') == isprint('A'), "isprint: uppercase");
	test_assert(ft_isprint('z') == isprint('z'), "isprint: lowercase");
	test_assert(ft_isprint('0') == isprint('0'), "isprint: digit");
	test_assert(ft_isprint('~') == isprint('~'), "isprint: tilde (126)");
	
	// Non-printable (<32)
	test_assert(ft_isprint(0) == isprint(0), "isprint: null (0)");
	test_assert(ft_isprint('\t') == isprint('\t'), "isprint: tab (9)");
	test_assert(ft_isprint('\n') == isprint('\n'), "isprint: newline (10)");
	test_assert(ft_isprint(31) == isprint(31), "isprint: 31");
	
	// DEL and beyond (>126)
	test_assert(ft_isprint(127) == isprint(127), "isprint: DEL (127)");
	test_assert(ft_isprint(128) == isprint(128), "isprint: 128");
	test_assert(ft_isprint(255) == isprint(255), "isprint: 255");
	
	// Edge cases
	test_assert(ft_isprint(-1) == isprint(-1), "isprint: -1");
	test_assert(ft_isprint(256) == isprint(256), "isprint: 256");
}

