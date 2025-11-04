/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"

void test_all(void)
{
	// Part 1 - Character functions
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	
	// Part 1 - String functions
	test_strlen();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_strdup();
	test_strnstr();
	
	// Part 1 - Memory functions
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_calloc();
	
	// Part 1 - Additional
	test_atoi();
	test_strlcpy();
	test_strlcat();
	
	// Part 2 - String manipulation
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	
	// Part 2 - File descriptor functions
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
	
	// Bonus - Linked lists
	test_lstnew();
	test_lstadd_front();
	test_lstadd_back();
	test_lstsize();
	test_lstlast();
	test_lstdelone();
	test_lstclear();
	test_lstiter();
	test_lstmap();
}

