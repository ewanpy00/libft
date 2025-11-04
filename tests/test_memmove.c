/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <string.h>

void test_memmove(void)
{
	printf("\n=== Testing ft_memmove ===\n");

	char buffer1[100], buffer2[100];
	
	// Non-overlapping copy
	strcpy(buffer1, "hello world");
	strcpy(buffer2, "hello world");
	ft_memmove(buffer1 + 5, buffer1, 5);
	memmove(buffer2 + 5, buffer2, 5);
	test_assert(memcmp(buffer1, buffer2, 20) == 0, "memmove: non-overlapping");
	
	// Overlapping - dest before src
	strcpy(buffer1, "hello world");
	strcpy(buffer2, "hello world");
	ft_memmove(buffer1, buffer1 + 6, 5);
	memmove(buffer2, buffer2 + 6, 5);
	test_assert(memcmp(buffer1, buffer2, 20) == 0, "memmove: dest before src");
	
	// Overlapping - src before dest
	strcpy(buffer1, "hello world");
	strcpy(buffer2, "hello world");
	ft_memmove(buffer1 + 6, buffer1, 5);
	memmove(buffer2 + 6, buffer2, 5);
	test_assert(memcmp(buffer1, buffer2, 20) == 0, "memmove: src before dest");
	
	// Basic copy (no overlap)
	char dest1[100], dest2[100];
	const char *src = "test string";
	memset(dest1, 0, 100);
	memset(dest2, 0, 100);
	ft_memmove(dest1, src, strlen(src) + 1);
	memmove(dest2, src, strlen(src) + 1);
	test_assert(memcmp(dest1, dest2, strlen(src) + 1) == 0, "memmove: basic copy");
	
	// Zero length
	strcpy(buffer1, "hello");
	strcpy(buffer2, "hello");
	ft_memmove(buffer1, buffer1 + 1, 0);
	memmove(buffer2, buffer2 + 1, 0);
	test_assert(strcmp(buffer1, buffer2) == 0, "memmove: zero length");
	
	// Single byte
	char single1[10], single2[10];
	memset(single1, 'a', 10);
	memset(single2, 'a', 10);
	ft_memmove(single1 + 1, single1, 1);
	memmove(single2 + 1, single2, 1);
	test_assert(memcmp(single1, single2, 10) == 0, "memmove: single byte");
}

