/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tester <tester@student.42.fr>              +#+  +:+       +#+        */
/*   Updated: 2025/11/01 00:00:00 by tester           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <stdlib.h>

void test_atoi(void)
{
	printf("\n=== Testing ft_atoi ===\n");

	// Basic positive numbers
	test_assert(ft_atoi("0") == atoi("0"), "atoi: zero");
	test_assert(ft_atoi("42") == atoi("42"), "atoi: positive number");
	test_assert(ft_atoi("123") == atoi("123"), "atoi: three digit number");
	test_assert(ft_atoi("999") == atoi("999"), "atoi: max three digits");
	
	// Negative numbers
	test_assert(ft_atoi("-42") == atoi("-42"), "atoi: negative number");
	test_assert(ft_atoi("-123") == atoi("-123"), "atoi: negative three digit");
	test_assert(ft_atoi("-2147483648") == atoi("-2147483648"), "atoi: INT_MIN");
	
	// Positive sign
	test_assert(ft_atoi("+42") == atoi("+42"), "atoi: positive sign");
	test_assert(ft_atoi("+123") == atoi("+123"), "atoi: positive sign three digit");
	
	// Whitespace handling
	test_assert(ft_atoi("   42") == atoi("   42"), "atoi: leading spaces");
	test_assert(ft_atoi("\t42") == atoi("\t42"), "atoi: leading tab");
	test_assert(ft_atoi("\n42") == atoi("\n42"), "atoi: leading newline");
	test_assert(ft_atoi("\v42") == atoi("\v42"), "atoi: leading vertical tab");
	test_assert(ft_atoi("\f42") == atoi("\f42"), "atoi: leading form feed");
	test_assert(ft_atoi("\r42") == atoi("\r42"), "atoi: leading carriage return");
	test_assert(ft_atoi("   -42") == atoi("   -42"), "atoi: spaces before negative");
	test_assert(ft_atoi("   +42") == atoi("   +42"), "atoi: spaces before positive");
	
	// Non-numeric strings
	test_assert(ft_atoi("abc") == atoi("abc"), "atoi: non-numeric");
	test_assert(ft_atoi("") == atoi(""), "atoi: empty string");
	test_assert(ft_atoi("   ") == atoi("   "), "atoi: only whitespace");
	test_assert(ft_atoi("abc123") == atoi("abc123"), "atoi: letters before numbers");
	test_assert(ft_atoi("123abc") == atoi("123abc"), "atoi: letters after numbers");
	
	// Edge cases
	test_assert(ft_atoi("2147483647") == atoi("2147483647"), "atoi: INT_MAX");
	test_assert(ft_atoi("-2147483649") == atoi("-2147483649"), "atoi: underflow");
	test_assert(ft_atoi("2147483648") == atoi("2147483648"), "atoi: overflow");
	test_assert(ft_atoi("99999999999999999999") == atoi("99999999999999999999"), "atoi: huge number");
	
	// Multiple signs
	test_assert(ft_atoi("++42") == atoi("++42"), "atoi: double plus");
	test_assert(ft_atoi("--42") == atoi("--42"), "atoi: double minus");
	test_assert(ft_atoi("+-42") == atoi("+-42"), "atoi: plus minus");
	test_assert(ft_atoi("-+42") == atoi("-+42"), "atoi: minus plus");
	
	// Zero variations
	test_assert(ft_atoi("0000") == atoi("0000"), "atoi: leading zeros");
	test_assert(ft_atoi("-0000") == atoi("-0000"), "atoi: negative with zeros");
	test_assert(ft_atoi("+0000") == atoi("+0000"), "atoi: positive with zeros");
	
	// Special characters
	test_assert(ft_atoi("42test") == atoi("42test"), "atoi: number followed by text");
	test_assert(ft_atoi("  42   ") == atoi("  42   "), "atoi: spaces around number");
}

