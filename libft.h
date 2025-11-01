#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_isalpha(int);
int		ft_isalnum(int);
int		ft_isdigit(int);
int		ft_isascii(int);
int		ft_isprint(int);
int		ft_toupper(int);
int		ft_tolower(int);
void	*ft_memset(void *, int, size_t);
void	ft_bzero(void *, size_t);
void	*ft_memcpy(void *, const void *, size_t);
void	*ft_memchr(const void *, int, size_t);
void	*ft_memmove(void *, const void *, size_t);
void	*calloc(size_t, size_t);
char	*strdup(const char *);
size_t	ft_strlcpy(char *, const char *, size_t);
size_t	ft_strlcat(char *, const char *, size_t);
char	*ft_strchr(const char *, int);
size_t	ft_strlen(char *);
char	*ft_strrchr(const char *, int);
int		ft_strncmp(const char *, const char *, size_t);
char	*ft_strnstr(const char *, const char *, size_t);
char	*strnstr(const char *, const char *, size_t);
char	*ft_substr(char const *, unsigned, size_t);
char	*ft_strjoin(char const *, char const *);
char	*ft_strtrim(char const *, char const *);
char	**ft_split(char const *, char);
char	*ft_strmapi(char const *, char (*)(unsigned int, char));
void	ft_striteri(char *, void (*)(unsigned int, char *));
void	ft_putchar_fd(char, int);
void	ft_putstr_fd(char *, int);
void	ft_putendl_fd(char *, int);
void	ft_putnbr_fd(int, int);
int		ft_atoi(const char *);
char	*ft_itoa(int);
void    ft_putchar_fd(char, int);
void    ft_putstr_fd(char *, int);
void    ft_putendl_fd(char *, int);
void    ft_putnbr_fd(int, int);

#endif