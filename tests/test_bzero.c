/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <string.h>
#include <strings.h>

void test_bzero(void)
{
	printf("\n=== Testing ft_bzero ===\n");

	char buffer1[100], buffer2[100];
	
	// Basic zero
	memset(buffer1, 'X', 100);
	memset(buffer2, 'X', 100);
	ft_bzero(buffer1, 50);
	bzero(buffer2, 50);
	test_assert(memcmp(buffer1, buffer2, 100) == 0, "bzero: basic zero");
	
	// Full buffer
	memset(buffer1, 'A', 100);
	memset(buffer2, 'A', 100);
	ft_bzero(buffer1, 100);
	bzero(buffer2, 100);
	test_assert(memcmp(buffer1, buffer2, 100) == 0, "bzero: full buffer");
	
	// Single byte
	memset(buffer1, 'B', 100);
	memset(buffer2, 'B', 100);
	ft_bzero(buffer1, 1);
	bzero(buffer2, 1);
	test_assert(memcmp(buffer1, buffer2, 100) == 0, "bzero: single byte");
	
	// Zero length
	memset(buffer1, 'C', 100);
	memset(buffer2, 'C', 100);
	ft_bzero(buffer1, 0);
	bzero(buffer2, (size_t)0);
	test_assert(memcmp(buffer1, buffer2, 100) == 0, "bzero: zero length");
	
	// Part of buffer
	memset(buffer1, 'D', 100);
	memset(buffer2, 'D', 100);
	ft_bzero(buffer1 + 10, 20);
	bzero(buffer2 + 10, 20);
	test_assert(memcmp(buffer1, buffer2, 100) == 0, "bzero: part of buffer");
}

