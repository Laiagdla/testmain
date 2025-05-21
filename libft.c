/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:35:58 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/05/21 15:19:51 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <bsd/string.h>
#include "includes/libft.h"

/* PART 1 */
int	test_isalpha(void)
{
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('2') == 0);
	return(0);
}

int	test_isdigit(void)
{
	assert(ft_isdigit('5') == 1);
	assert(ft_isdigit('a') == 0);
	return(0);
}

int	test_isalnum(void)
{
	assert(ft_isalnum('5') == 1);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('~') == 0);
	return(0);
}

int	test_isascii(void)
{
	assert(ft_isascii('5') == 1);
	assert(ft_isascii('a') == 1);
	assert(ft_isascii('~') == 1);
	assert(ft_isascii(128) == 0);
	return(0);
}

int	test_isprint(void)
{
	assert(ft_isprint('5') == 1);
	assert(ft_isprint('a') == 1);
	assert(ft_isprint('~') == 1);
	assert(ft_isprint(' ') == 1);
	assert(ft_isprint(128) == 0);
	assert(ft_isprint(17) == 0);
	return(0);}

int	test_toupper(void)
{
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('4') == '4');
	return(0);
}

int	test_tolower(void)
{
	assert(ft_tolower('A') == 'a');
	assert(ft_tolower('4') == '4');
	return(0);
}

int	test_memset(void)
{
	char	buffer[10];

	ft_memset(buffer, 'A', sizeof(buffer));
	assert(buffer[0] == 'A');
	assert(buffer[7] == 'A');
	return(0);
}

int	test_memchr(void)
{
	const char	*buffer = "hello";
	char 		*ptr;

	ptr = ft_memchr(buffer, 'o', 5);
	assert(*ptr == 'o');
	assert(*ptr == buffer[4]);
	ptr = ft_memchr(buffer, 'z', 5);
	assert(ptr == NULL);
	return(0);
}

int	test_memcmp(void)
{
	const char	*s1 = "hello";
	const char 	*s2 = "help";

	assert(ft_memcmp(s1, s2, 6) == -4);
	assert(ft_memcmp(s1, s1, 6) == 0);
	assert(ft_memcmp(s2, s1, 6) == 4);
	return(0);
}

int	test_memcpy(void)
{
	const char	*src = "hello";
	char 		*dst = malloc(10);
	char		*ptr;
	ptr = ft_memcpy(dst, src, 5);

	assert(*ptr == 'h');
	assert(*(ptr + 4) == 'o');
	assert(ft_memcpy(NULL, NULL, 3) == NULL);
	return(0);
}

int	test_memmove(void)
{
	const char	*src = "hello";
	char 		*dst = malloc(10);
	char		*ptr;
	ptr = ft_memmove(dst, src, 5);

	assert(*ptr == 'h');
	assert(*(ptr + 4) == 'o');
	return(0);
}

int	test_strlen(void)
{
	assert(ft_strlen("hello") == 5);
	assert(ft_strlen("") == 0);
	return(0);
}

int	test_strchr(void)
{
	const char	*str = "hello";

	assert(ft_strchr(str, 'o') == str + 4);
	assert(ft_strchr(str, '\0') == str + 5);
	assert(ft_strchr(str, 'A') == NULL);
	return(0);
}

int	test_strrchr(void)
{
	const char	*str = "hello";

	assert(ft_strrchr(str, 'l') == str + 3);
	assert(ft_strrchr(str, '\0') == str + 5);
	assert(ft_strrchr(str, 'A') == NULL);
	return(0);
}

int	test_strncmp(void)
{
	const char	*s1 = "hello";
	const char 	*s2 = "help";

	assert(ft_strncmp(s1, s2, 5) == -4);
	assert(ft_strncmp(s1, s1, 5) == 0);
	assert(ft_strncmp(s2, s1, 5) == 4);
	return(0);
}

int	test_strnstr(void)
{
	const char	*haystack = "one more line of code";
	const char	*needle = "lin";
	char		*ptr;

	ptr = ft_strnstr(haystack, needle, 2);
	assert(ptr == NULL);
	ptr = ft_strnstr(haystack, needle, 20);
	assert(ptr == haystack + 9);

	char *s1 = "MZIRIBMZIRIBMZE123";
	char *s2 = "MZIRIBMZE";
	size_t max = strlen(s2);
	char *i1 = strnstr(s1, s2, max);
	char *i2 = ft_strnstr(s1, s2, max);
	assert(i1 == i2);
	// ft_strnstr(((void*)0), "fake", 0);
	// printf("%s\n", i1);
	// printf("%s\n", i2);
	return (0);
}

int	test_strlcpy(void)
{
	const char	*src = "hello";
	char 		*dst = malloc(10);
	ft_strlcpy(dst, src, 6);
	// printf("%s\n", dst);
	assert(dst[0] == 'h');
	assert(dst[4] == 'o');
	// printf("%zu\n", strlcpy(dst, src, 2));
	// printf("%zu\n", ft_strlcpy(dst, src, 2));
	assert(strlcpy(dst, src, 2) == ft_strlcpy(dst, src, 2));
	// printf("%zu\n", strlcpy(dst, src, 0));
	// printf("%zu\n", ft_strlcpy(dst, src, 0));
	assert(strlcpy(dst, src, 0) == ft_strlcpy(dst, src, 0));
	free(dst);
	return(0);
}

int	test_strlcat(void)
{
	const char	*src = "hello";
	char 		*dst = malloc(10);

	// size_t src_len = ft_strlen(src);
	// size_t dst_len = ft_strlen(dst);
	// printf("src_len: %zu, dst_len: %zu\n", src_len, dst_len);


	// strlcpy(dst, "hello", 6);
	// printf("strlcat 11: %zu\n", strlcat(dst, src, 11));
	// strlcpy(dst, "hello", 6);
	// printf("ft_strlcat 11: %zu\n", ft_strlcat(dst, src, 11));

	// strlcpy(dst, "hello", 6);
	// printf("strlcat 9: %zu\n", strlcat(dst, src, 9));
	// strlcpy(dst, "hello", 6);
	// printf("ft_strlcat 9: %zu\n", ft_strlcat(dst, src, 9));

	// strlcpy(dst, "hello", 6);
	// printf("strlcat 0: %zu\n", strlcat(dst, src, 0));
	// strlcpy(dst, "hello", 6);
	// printf("ft_strlcat 0: %zu\n", ft_strlcat(dst, src, 0));

	// strlcpy(dst, "hello", 6);
	// printf("strlcat 3: %zu\n", strlcat(dst, src, 3));
	// strlcpy(dst, "hello", 6);
	// printf("ft_strlcat 3: %zu\n", ft_strlcat(dst, src, 3));

	strlcpy(dst, "hello", 6);
	assert(ft_strlcat(dst, src, 11) == 10);
	strlcpy(dst, "hello", 6);
	assert(ft_strlcat(dst, src, 9) == 10);
	strlcpy(dst, "hello", 6);
	assert(ft_strlcat(dst, src, 3) == 8);

	// assert(strlcat(((void*)0), src, 0) == ft_strlcat(((void*)0), src, 0));
	// printf("%zu\n", strlcat(((void*)0), src, 0));
	// printf("%zu\n", ft_strlcat(((void*)0), src, 0));
	free(dst);
	return(0);
}

int	test_bzero(void)
{
	int a = 0;
	void *s = &a;

	ft_bzero(s, 5);
	return (0);
}

int	test_atoi(void)
{
	ft_atoi("  -+232324");
	return (0);
}

int	test_strdup(void)
{
	// char	*src = "hello";
	// char	*dest;

	// dest = strdup(src);
	// printf("%s\n", dest);
	return (0);
}

int	test_calloc(void)
{
	void * d1 = ft_calloc(20, sizeof(int));
	void * d2 = calloc(20, sizeof(int));
	assert(memcmp(d1, d2, 20 * sizeof(int)) == 0);
	return (0);
}

/* PART 2 */

int	test_substr(void)
{
	char	*s1 = "i just want this part #############";
	size_t	size1 = 22;
	char	*r1 = ft_substr(s1, 0, size1);
	char	*ex1 = "i just want this part ";
	assert(strcmp(r1, ex1) == 0);
	// printf("%s\n", r1);
	char	*s2 = "";
	size_t	size2 = 0;
	char	*r2 = ft_substr(s2, 5, size2);
	char	*ex2 = "";
	assert(strcmp(r2, ex2) == 0);
	// printf("%s\n", r2);
	return (0);
}

int	test_strjoin(void)
{
	// char *s1 = "my favorite animal is ";
	// char *s2 = s1 + 20;
	// printf("%s\n", s2);
	// char *res = ft_strjoin(s2, s1);
	return (0);
}

int	test_strtrim(void)
{
	// char *s1 = "**\t*\n\n*\t\t**\n\n\nHello \t  Please\n Trim me !\n*\n*\n*\t*\t\n***";
	// // char *s2 = "Hello \t  Please\n Trim me !";
	// char *ret = ft_strtrim(s1, "*\n\t");
	// // assert(strcmp(ret, s2));
	// printf("%s\n", ret);
	// char *s3 = "  \t \t \n   \n\n\n\t";
	// // char *s4 = "";
	// char *ret2 = ft_strtrim(s3, " \n\t");
	// printf("%s\n", ret2);
	return (0);
}

int	test_split(void)
{
	// char *s1 = "      split       this for   me  !       ";
	// // char **expected = ((char*[6]){"split", "this", "for", "me", "!", ((void*)0)});
	// char **result1 = ft_split(s1, ' ');
	// while (*result1)
	// 	printf("%s\n", *result1++);
	// char *s2 = "split  ||this|for|me|||||!|";
	// char **result2 = ft_split(s2, '|');
	// while (*result2)
	// 	printf("%s\n", *result2++);
	// char *s3 = "                  olol";
	// char **result3 = ft_split(s3, ' ');
	// while (*result3)
	// 	printf("%s\n", *result3++);
	return (0);
}

int	test_itoa(void)
{
	// char *i1 = ft_itoa(-623);
	// printf("%s\n", i1);
	// char *i2 = ft_itoa((-2147483647 -1));
	// printf("%s\n", i2);
	return (0);
}

char	f_strmapi(unsigned i, char s) { s = i + '0'; return (s); }

int	test_strmapi(void)
{
	char b1[] = "override this !";
	char *r1;
	r1 = ft_strmapi(b1, f_strmapi);
	// printf("%s\n", r1);
	char e1[] = "0123456789:;<=>";
	assert(ft_strncmp(r1, e1, ft_strlen(b1)) == 0);
	return (0);
}

void	f_striteri(unsigned i, char *s) { *s = i + '0'; }

int	test_striteri(void)
{
	char b1[] = "override this !";
	char b2[] = "0123456789:;<=>";
	ft_striteri(b1, f_striteri);
	// printf("%s\n", b1);
	assert(ft_strncmp(b1, b2, ft_strlen(b1)) == 0);
	return (0);
}

int	test_putchar_fd(void)
{
	// ft_putchar_fd('a', 1);
	// ft_putchar_fd('a', 2);
	// ft_putchar_fd('a', 0);
	return (0);
}

int	test_putstr_fd(void)
{
	// ft_putstr_fd("hello", 1);
	return (0);
}

int	test_putendl_fd(void)
{
	// ft_putendl_fd("hello", 1);
	return (0);
}


#define GREEN  "\e[32m"
#define RESET "\e[0m"

int	main(void)
{
	printf(GREEN "%d ft_isalpha		OK\n" RESET, test_isalpha());
	printf(GREEN "%d ft_isalnum		OK\n" RESET, test_isalnum());
	printf(GREEN "%d ft_isascii		OK\n" RESET, test_isascii());
	printf(GREEN "%d ft_isprint		OK\n" RESET, test_isprint());
	printf(GREEN "%d ft_toupper		OK\n" RESET, test_toupper());
	printf(GREEN "%d ft_tolower		OK\n" RESET, test_tolower());
	printf(GREEN "%d ft_memset		OK\n" RESET, test_memset());
	printf(GREEN "%d ft_memchr		OK\n" RESET, test_memchr());
	printf(GREEN "%d ft_memcmp		OK\n" RESET, test_memcmp());
	printf(GREEN "%d ft_memcpy		OK\n" RESET, test_memcpy());
	printf(GREEN "%d ft_memmove		OK\n" RESET, test_memmove());
	printf(GREEN "%d ft_strlen		OK\n" RESET, test_strlen());
	printf(GREEN "%d ft_strchr		OK\n" RESET, test_strchr());
	printf(GREEN "%d ft_strrchr		OK\n" RESET, test_strrchr());
	printf(GREEN "%d ft_strncmp		OK\n" RESET, test_strncmp());
	printf(GREEN "%d ft_strnstr		OK\n" RESET, test_strnstr());
	printf(GREEN "%d ft_strlcpy		OK\n" RESET, test_strlcpy());
	printf(GREEN "%d ft_strlcat		OK\n" RESET, test_strlcat());
	printf(GREEN "%d ft_bzero		OK\n" RESET, test_bzero());
	printf(GREEN "%d ft_atoi		OK\n" RESET, test_atoi());
	printf(GREEN "%d ft_strdup		OK\n" RESET, test_strdup());
	printf(GREEN "%d ft_calloc		OK\n" RESET, test_calloc());
	printf(GREEN "%d ft_substr		OK\n" RESET, test_substr());
	printf(GREEN "%d ft_strjoin		OK\n" RESET, test_strjoin());
	printf(GREEN "%d ft_strtrim		OK\n" RESET, test_strtrim());
	printf(GREEN "%d ft_split		OK\n" RESET, test_split());
	printf(GREEN "%d ft_itoa		OK\n" RESET, test_itoa());
	printf(GREEN "%d ft_strmapi		OK\n" RESET, test_strmapi());
	printf(GREEN "%d ft_striteri		OK\n" RESET, test_striteri());
	printf(GREEN "%d ft_putchar_fd		OK\n" RESET, test_putchar_fd());
	printf(GREEN "%d ft_putstr_fd		OK\n" RESET, test_putstr_fd());
	printf(GREEN "%d ft_putendl_fd		OK\n" RESET, test_putendl_fd());
	return (0);
}
