/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <string.h>

void test_memchr(void)
{
	printf("\n=== Testing ft_memchr ===\n");

	const char *str = "hello world";
	
	// Character found
	test_assert(ft_memchr(str, 'h', 11) == memchr(str, 'h', 11), "memchr: first char");
	test_assert(ft_memchr(str, 'e', 11) == memchr(str, 'e', 11), "memchr: second char");
	test_assert(ft_memchr(str, 'l', 11) == memchr(str, 'l', 11), "memchr: multiple occurrence");
	test_assert(ft_memchr(str, ' ', 11) == memchr(str, ' ', 11), "memchr: space");
	test_assert(ft_memchr(str, 'd', 11) == memchr(str, 'd', 11), "memchr: last char");
	
	// Character not found
	test_assert(ft_memchr(str, 'x', 11) == memchr(str, 'x', 11), "memchr: not found");
	test_assert(ft_memchr(str, 'Z', 11) == memchr(str, 'Z', 11), "memchr: uppercase not found");
	
	// Limited search length
	test_assert(ft_memchr(str, 'o', 5) == memchr(str, 'o', 5), "memchr: found in range");
	test_assert(ft_memchr(str, 'd', 5) == memchr(str, 'd', 5), "memchr: not found in range");
	
	// Zero length
	test_assert(ft_memchr(str, 'h', 0) == memchr(str, 'h', 0), "memchr: zero length");
	
	// Null in buffer
	char buffer[] = {'a', 'b', '\0', 'c', 'd'};
	test_assert(ft_memchr(buffer, '\0', 5) == memchr(buffer, '\0', 5), "memchr: null in buffer");
	test_assert(ft_memchr(buffer, 'c', 5) == memchr(buffer, 'c', 5), "memchr: after null");
	
	// Integer overflow
	test_assert(ft_memchr(str, 256 + 'h', 11) == memchr(str, 256 + 'h', 11), "memchr: overflow");
	test_assert(ft_memchr(str, -1, 11) == memchr(str, -1, 11), "memchr: negative");
}

