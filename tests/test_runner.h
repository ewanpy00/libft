/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:06:00 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_RUNNER_H
# define TEST_RUNNER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void test_assert(int condition, const char *test_name);
int run_test_with_crash_check(const char *test_name, void (*test_func)(void));
void print_summary(void);

// Test functions
void test_strlen(void);
void test_atoi(void);
void test_isalpha(void);
void test_isdigit(void);
void test_isalnum(void);
void test_isascii(void);
void test_isprint(void);
void test_toupper(void);
void test_tolower(void);
void test_strchr(void);
void test_strrchr(void);
void test_strncmp(void);
void test_strdup(void);
void test_calloc(void);
void test_memcpy(void);
void test_memmove(void);
void test_memset(void);
void test_bzero(void);
void test_memchr(void);
void test_memcmp(void);
void test_strlcpy(void);
void test_strlcat(void);
void test_strnstr(void);
void test_substr(void);
void test_strjoin(void);
void test_strtrim(void);
void test_split(void);
void test_itoa(void);
void test_strmapi(void);
void test_striteri(void);
void test_putchar_fd(void);
void test_putstr_fd(void);
void test_putendl_fd(void);
void test_putnbr_fd(void);

// Helper functions for put_fd tests
char *read_file(const char *filename);
void test_lstnew(void);
void test_lstadd_front(void);
void test_lstadd_back(void);
void test_lstsize(void);
void test_lstlast(void);
void test_lstdelone(void);
void test_lstclear(void);
void test_lstiter(void);
void test_lstmap(void);

void test_all(void);

#endif

