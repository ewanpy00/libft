/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:06:00 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <string.h>

void test_memcmp(void)
{
	printf("\n=== Testing ft_memcmp ===\n");

	// Equal memory
	test_assert(ft_memcmp("hello", "hello", 5) == memcmp("hello", "hello", 5), "memcmp: equal");
	test_assert(ft_memcmp("", "", 0) == memcmp("", "", 0), "memcmp: empty");
	
	// Different memory
	test_assert((ft_memcmp("hello", "world", 5) > 0) == (memcmp("hello", "world", 5) > 0), "memcmp: first greater");
	test_assert((ft_memcmp("world", "hello", 5) < 0) == (memcmp("world", "hello", 5) < 0), "memcmp: first less");
	test_assert((ft_memcmp("abc", "abd", 3) < 0) == (memcmp("abc", "abd", 3) < 0), "memcmp: last byte diff");
	
	// Partial comparison
	test_assert(ft_memcmp("hello", "hella", 4) == memcmp("hello", "hella", 4), "memcmp: partial equal");
	test_assert(ft_memcmp("hello", "hella", 5) == memcmp("hello", "hella", 5), "memcmp: partial diff");
	
	// Zero length
	test_assert(ft_memcmp("hello", "world", 0) == memcmp("hello", "world", 0), "memcmp: zero length");
	
	// Null in memory
	char buf1[] = {'a', 'b', '\0', 'c'};
	char buf2[] = {'a', 'b', '\0', 'd'};
	test_assert(ft_memcmp(buf1, buf2, 4) == memcmp(buf1, buf2, 4), "memcmp: null in memory");
	
	// Binary data
	char bin1[] = {0, 1, 2, 3, 4};
	char bin2[] = {0, 1, 2, 3, 5};
	test_assert(ft_memcmp(bin1, bin2, 5) == memcmp(bin1, bin2, 5), "memcmp: binary data");
	
	// Negative bytes
	char neg1[] = {-1, -2, -3};
	char neg2[] = {-1, -2, -4};
	test_assert(ft_memcmp(neg1, neg2, 3) == memcmp(neg1, neg2, 3), "memcmp: negative bytes");
}

