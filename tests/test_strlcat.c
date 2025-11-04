/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <string.h>

// strlcat might not be available on all systems, provide a simple implementation for testing
#ifndef __APPLE__
static size_t strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len = strlen(dst);
	size_t src_len = strlen(src);
	if (size <= dst_len)
		return size + src_len;
	size_t copy_len = (src_len < size - dst_len - 1) ? src_len : size - dst_len - 1;
	memcpy(dst + dst_len, src, copy_len);
	dst[dst_len + copy_len] = '\0';
	return dst_len + src_len;
}
#endif

void test_strlcat(void)
{
	printf("\n=== Testing ft_strlcat ===\n");

	char dest1[100], dest2[100];
	const char *src = " world";
	
	// Basic concatenation
	strcpy(dest1, "hello");
	strcpy(dest2, "hello");
	size_t len1 = ft_strlcat(dest1, src, 100);
	size_t len2 = strlcat(dest2, src, 100);
	test_assert(len1 == len2 && strcmp(dest1, dest2) == 0, "strlcat: basic concat");
	
	// Exact fit
	strcpy(dest1, "test");
	strcpy(dest2, "test");
	len1 = ft_strlcat(dest1, "1234", 9);
	len2 = strlcat(dest2, "1234", 9);
	test_assert(len1 == len2 && strcmp(dest1, dest2) == 0, "strlcat: exact fit");
	
	// Buffer too small
	strcpy(dest1, "hello");
	strcpy(dest2, "hello");
	len1 = ft_strlcat(dest1, src, 8);
	len2 = strlcat(dest2, src, 8);
	test_assert(len1 == len2, "strlcat: buffer too small");
	
	// Empty destination
	strcpy(dest1, "");
	strcpy(dest2, "");
	len1 = ft_strlcat(dest1, "hello", 100);
	len2 = strlcat(dest2, "hello", 100);
	test_assert(len1 == len2 && strcmp(dest1, dest2) == 0, "strlcat: empty dest");
	
	// Empty source
	strcpy(dest1, "hello");
	strcpy(dest2, "hello");
	len1 = ft_strlcat(dest1, "", 100);
	len2 = strlcat(dest2, "", 100);
	test_assert(len1 == len2 && strcmp(dest1, dest2) == 0, "strlcat: empty source");
	
	// Zero size
	strcpy(dest1, "hello");
	strcpy(dest2, "hello");
	len1 = ft_strlcat(dest1, src, 0);
	len2 = strlcat(dest2, src, 0);
	test_assert(len1 == len2, "strlcat: zero size");
	
	// Size smaller than dest length
	strcpy(dest1, "hello");
	strcpy(dest2, "hello");
	len1 = ft_strlcat(dest1, src, 3);
	len2 = strlcat(dest2, src, 3);
	test_assert(len1 == len2, "strlcat: size < dest length");
}

