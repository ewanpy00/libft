/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <string.h>

// strlcpy might not be available on all systems, provide a simple implementation for testing
#ifndef __APPLE__
static size_t strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len = strlen(src);
	if (size == 0)
		return src_len;
	size_t copy_len = (src_len < size - 1) ? src_len : size - 1;
	memcpy(dst, src, copy_len);
	dst[copy_len] = '\0';
	return src_len;
}
#endif

void test_strlcpy(void)
{
	printf("\n=== Testing ft_strlcpy ===\n");

	char dest1[100], dest2[100];
	const char *src = "hello world";
	
	// Basic copy
	memset(dest1, 'X', 100);
	memset(dest2, 'X', 100);
	size_t len1 = ft_strlcpy(dest1, src, 100);
	size_t len2 = strlcpy(dest2, src, 100);
	test_assert(len1 == len2 && strcmp(dest1, dest2) == 0, "strlcpy: basic copy");
	
	// Exact fit
	memset(dest1, 'X', 100);
	memset(dest2, 'X', 100);
	len1 = ft_strlcpy(dest1, "test", 5);
	len2 = strlcpy(dest2, "test", 5);
	test_assert(len1 == len2 && strcmp(dest1, dest2) == 0, "strlcpy: exact fit");
	
	// Buffer too small
	memset(dest1, 'X', 100);
	memset(dest2, 'X', 100);
	len1 = ft_strlcpy(dest1, src, 5);
	len2 = strlcpy(dest2, src, 5);
	test_assert(len1 == len2 && strncmp(dest1, dest2, 4) == 0 && dest1[4] == '\0', "strlcpy: buffer too small");
	
	// Zero size
	memset(dest1, 'X', 100);
	memset(dest2, 'X', 100);
	len1 = ft_strlcpy(dest1, src, 0);
	len2 = strlcpy(dest2, src, 0);
	test_assert(len1 == len2, "strlcpy: zero size");
	
	// Empty source
	memset(dest1, 'X', 100);
	memset(dest2, 'X', 100);
	len1 = ft_strlcpy(dest1, "", 100);
	len2 = strlcpy(dest2, "", 100);
	test_assert(len1 == len2 && strcmp(dest1, dest2) == 0, "strlcpy: empty source");
	
	// Single character
	memset(dest1, 'X', 100);
	memset(dest2, 'X', 100);
	len1 = ft_strlcpy(dest1, "a", 100);
	len2 = strlcpy(dest2, "a", 100);
	test_assert(len1 == len2 && strcmp(dest1, dest2) == 0, "strlcpy: single char");
	
	// Size = 1 (should only store null terminator)
	memset(dest1, 'X', 100);
	memset(dest2, 'X', 100);
	len1 = ft_strlcpy(dest1, src, 1);
	len2 = strlcpy(dest2, src, 1);
	test_assert(len1 == len2 && dest1[0] == '\0' && dest2[0] == '\0', "strlcpy: size=1");
}

