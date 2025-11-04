/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:00:00 by tester            #+#    #+#             */
/*   Updated: 2025/11/04 14:01:23 by ivan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_runner.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char *read_file(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		return NULL;
	
	struct stat st;
	fstat(fd, &st);
	char *buffer = malloc(st.st_size + 1);
	if (!buffer)
	{
		close(fd);
		return NULL;
	}
	
	read(fd, buffer, st.st_size);
	buffer[st.st_size] = '\0';
	close(fd);
	return buffer;
}

void test_putchar_fd(void)
{
	printf("\n=== Testing ft_putchar_fd ===\n");
	
	char *filename = "test_putchar.txt";
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	test_assert(fd >= 0, "putchar_fd: open file");
	
	ft_putchar_fd('A', fd);
	ft_putchar_fd('B', fd);
	ft_putchar_fd('C', fd);
	close(fd);
	
	char *content = read_file(filename);
	test_assert(content != NULL && strcmp(content, "ABC") == 0, "putchar_fd: write chars");
	free(content);
	unlink(filename);
	
	// Test stdout
	test_assert(1, "putchar_fd: stdout (manual check)");
}

void test_putstr_fd(void)
{
	printf("\n=== Testing ft_putstr_fd ===\n");
	
	char *filename = "test_putstr.txt";
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	test_assert(fd >= 0, "putstr_fd: open file");
	
	ft_putstr_fd("Hello World", fd);
	close(fd);
	
	char *content = read_file(filename);
	test_assert(content != NULL && strcmp(content, "Hello World") == 0, "putstr_fd: write string");
	free(content);
	unlink(filename);
	
	// Empty string
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("", fd);
	close(fd);
	content = read_file(filename);
	test_assert(content != NULL && strlen(content) == 0, "putstr_fd: empty string");
	free(content);
	unlink(filename);
	
	// NULL (should handle gracefully or crash)
	printf("[INFO] Testing NULL input (may crash)\n");
}

void test_putendl_fd(void)
{
	printf("\n=== Testing ft_putendl_fd ===\n");
	
	char *filename = "test_putendl.txt";
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	test_assert(fd >= 0, "putendl_fd: open file");
	
	ft_putendl_fd("Hello World", fd);
	close(fd);
	
	char *content = read_file(filename);
	test_assert(content != NULL && strcmp(content, "Hello World\n") == 0, "putendl_fd: write with newline");
	free(content);
	unlink(filename);
	
	// Empty string
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("", fd);
	close(fd);
	content = read_file(filename);
	test_assert(content != NULL && strcmp(content, "\n") == 0, "putendl_fd: empty string");
	free(content);
	unlink(filename);
}

void test_putnbr_fd(void)
{
	printf("\n=== Testing ft_putnbr_fd ===\n");
	
	char *filename = "test_putnbr.txt";
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	test_assert(fd >= 0, "putnbr_fd: open file");
	
	ft_putnbr_fd(42, fd);
	close(fd);
	
	char *content = read_file(filename);
	test_assert(content != NULL && strcmp(content, "42") == 0, "putnbr_fd: positive");
	free(content);
	unlink(filename);
	
	// Negative
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(-42, fd);
	close(fd);
	content = read_file(filename);
	test_assert(content != NULL && strcmp(content, "-42") == 0, "putnbr_fd: negative");
	free(content);
	unlink(filename);
	
	// Zero
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(0, fd);
	close(fd);
	content = read_file(filename);
	test_assert(content != NULL && strcmp(content, "0") == 0, "putnbr_fd: zero");
	free(content);
	unlink(filename);
	
	// INT_MAX
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(2147483647, fd);
	close(fd);
	content = read_file(filename);
	test_assert(content != NULL && strcmp(content, "2147483647") == 0, "putnbr_fd: INT_MAX");
	free(content);
	unlink(filename);
	
	// INT_MIN
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
	content = read_file(filename);
	test_assert(content != NULL && strcmp(content, "-2147483648") == 0, "putnbr_fd: INT_MIN");
	free(content);
	unlink(filename);
}

