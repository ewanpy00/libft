/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <string.h>

void test_memcpy(void)
{
	printf("\n=== Testing ft_memcpy ===\n");

	char dest1[100], dest2[100];
	const char *src = "hello world";
	
	// Basic copy
	memset(dest1, 0, 100);
	memset(dest2, 0, 100);
	ft_memcpy(dest1, src, strlen(src) + 1);
	memcpy(dest2, src, strlen(src) + 1);
	test_assert(memcmp(dest1, dest2, strlen(src) + 1) == 0, "memcpy: basic copy");
	
	// Partial copy
	memset(dest1, 0, 100);
	memset(dest2, 0, 100);
	ft_memcpy(dest1, src, 5);
	memcpy(dest2, src, 5);
	test_assert(memcmp(dest1, dest2, 5) == 0, "memcpy: partial copy");
	
	// Single byte
	memset(dest1, 0, 100);
	memset(dest2, 0, 100);
	ft_memcpy(dest1, "a", 1);
	memcpy(dest2, "a", 1);
	test_assert(memcmp(dest1, dest2, 1) == 0, "memcpy: single byte");
	
	// Zero length
	memset(dest1, 'X', 100);
	memset(dest2, 'X', 100);
	ft_memcpy(dest1, src, 0);
	memcpy(dest2, src, 0);
	test_assert(memcmp(dest1, dest2, 100) == 0, "memcpy: zero length");
	
	// Null in middle
	char src2[] = {'a', 'b', '\0', 'c', 'd'};
	memset(dest1, 0, 100);
	memset(dest2, 0, 100);
	ft_memcpy(dest1, src2, 5);
	memcpy(dest2, src2, 5);
	test_assert(memcmp(dest1, dest2, 5) == 0, "memcpy: null in middle");
	
	// Large copy
	char src3[1000];
	char dest3[1000], dest4[1000];
	memset(src3, 'A', 999);
	src3[999] = '\0';
	memset(dest3, 0, 1000);
	memset(dest4, 0, 1000);
	ft_memcpy(dest3, src3, 999);
	memcpy(dest4, src3, 999);
	test_assert(memcmp(dest3, dest4, 999) == 0, "memcpy: large copy");
}

