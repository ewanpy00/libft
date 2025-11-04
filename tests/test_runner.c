/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_runner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:06:00 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../libft/libft.h"

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

static int tests_passed = 0;
static int tests_failed = 0;
static int tests_crashed = 0;

void test_assert(int condition, const char *test_name)
{
	if (condition)
	{
		printf("%s[PASS]%s %s\n", GREEN, RESET, test_name);
		tests_passed++;
	}
	else
	{
		printf("%s[FAIL]%s %s\n", RED, RESET, test_name);
		tests_failed++;
	}
}

int run_test_with_crash_check(const char *test_name, void (*test_func)(void))
{
	pid_t pid = fork();
	int status;

	if (pid == 0)
	{
		// Child process
		test_func();
		exit(0);
	}
	else if (pid > 0)
	{
		// Parent process
		waitpid(pid, &status, 0);
		if (WIFSIGNALED(status))
		{
			printf("%s[CRASH]%s %s (signal %d)\n", YELLOW, RESET, test_name, WTERMSIG(status));
			tests_crashed++;
			return (1); // Crashed
		}
		return (0); // No crash
	}
	return (-1); // Fork failed
}

void print_summary(void)
{
	printf("\n");
	printf("========================================\n");
	printf("Test Summary:\n");
	printf("%sPassed: %d%s\n", GREEN, tests_passed, RESET);
	printf("%sFailed: %d%s\n", RED, tests_failed, RESET);
	printf("%sCrashed: %d%s\n", YELLOW, tests_crashed, RESET);
	printf("Total: %d\n", tests_passed + tests_failed + tests_crashed);
	printf("========================================\n");
}

int main(void)
{
	extern void test_all(void);
	
	test_all();
	print_summary();
	
	return (tests_failed > 0 ? 1 : 0);
}

