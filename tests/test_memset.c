/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <string.h>

void test_memset(void)
{
	printf("\n=== Testing ft_memset ===\n");

	char buffer1[100], buffer2[100];
	
	// Basic set
	memset(buffer1, 'A', 50);
	memset(buffer2, 'A', 50);
	ft_memset(buffer1, 'A', 50);
	test_assert(memcmp(buffer1, buffer2, 50) == 0, "memset: basic set");
	
	// Set to zero
	memset(buffer1, 0, 50);
	memset(buffer2, 0, 50);
	ft_memset(buffer1, 0, 50);
	test_assert(memcmp(buffer1, buffer2, 50) == 0, "memset: set to zero");
	
	// Single byte
	memset(buffer1, 'X', 1);
	memset(buffer2, 'X', 1);
	ft_memset(buffer1, 'X', 1);
	test_assert(memcmp(buffer1, buffer2, 1) == 0, "memset: single byte");
	
	// Zero length
	memset(buffer1, 'Y', 100);
	memset(buffer2, 'Y', 100);
	ft_memset(buffer1, 'Z', 0);
	memset(buffer2, 'Z', (size_t)0);
	test_assert(memcmp(buffer1, buffer2, 100) == 0, "memset: zero length");
	
	// Integer value (cast to unsigned char)
	memset(buffer1, 65, 10);
	memset(buffer2, 65, 10);
	ft_memset(buffer1, 65, 10);
	test_assert(memcmp(buffer1, buffer2, 10) == 0, "memset: integer value");
	
	// Negative value (cast to unsigned char)
	memset(buffer1, -1, 10);
	memset(buffer2, -1, 10);
	ft_memset(buffer1, -1, 10);
	test_assert(memcmp(buffer1, buffer2, 10) == 0, "memset: negative value");
	
	// Large value (cast to unsigned char)
	memset(buffer1, 300, 10);
	memset(buffer2, 300, 10);
	ft_memset(buffer1, 300, 10);
	test_assert(memcmp(buffer1, buffer2, 10) == 0, "memset: large value");
}

