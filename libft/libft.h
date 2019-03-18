/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdynia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:50:01 by mdynia            #+#    #+#             */
/*   Updated: 2018/07/28 20:21:29 by mdynia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <float.h>
# define BUFF_SIZE 6
# define FLOAT(q) q == 'f' || q == 'F'
# define SIGN(q) q == 'R' || q == 's' || q == '%' || q == 'Z' || FLOAT(q)
# define FLAGS(k) k == ' ' || k == '+' || k == '-' || k == '#'|| k == '0'
# define C(q) q == 'C' || q == 'S' ||  q == 'c' || q == 's'
# define N(q) q == 'u' || q == 'U' || q == 'o' || q == 'x'
# define N2(q)  q == 'x' || q == 'X' || q == 'p' || q == 'O' || N(q)
# define LIST_NUMBERS(q) q == 'd' || q == 'i' || q == 'D' || N2(q)
# define TYPES_LIST(q) LIST_NUMBERS(q) || SIGN(q) || C(q)
# define SPEC(s) s == 't' || s == 'z' || s == 'j' || s == 'l' || s == 'h'
# define ZERO		1
# define SPACE		2
# define PLUS		4
# define MINUS		8
# define HASHTAG	16
# define NEGATIVE	33
# define ZEROS(f) f == 1 || f == 4 + 1 || f == 2 + 1 || f == 16 + 1
# define NEGATIVES(f) f == 1 + 33 || f == 2 + 1 + 33 || f == 4 + 1 + 33
# define M(f) (f >= 41 && f<= 46 && f != 44)
# define MINUSES(f) (f >= 8 && f < 16) || f == 24|| f == 25 || M(f)
# define PLUSES(f) (f > 3 && f < 7) || (f > 11 && f < 15)
# define ONE_SIGN(f) f == 2 || f == 2 + 8 || f ==  1 + 2 || f == 8 + 2 + 1
# define SPACES(f) f == 2 || f == 2 + 8 || f ==  1 + 2 || f == 2 + 1 + 8
# define HASHTAGS(f) f == 16 || f == 17 || f == 16 + 9 || f == 16 + 8
# define NEED(f)  ONE_SIGN(f) || HASHTAGS(f) || PLUSES(f)
# define P(f) f == PLUS + ZERO || f == SPACE + ZERO || NEGATIVES(f)

typedef struct	s_gnl_struct
{
	int					fd;
	char				*str;
	struct s_gnl_struct	*next;
}				t_gnl_struct;

typedef struct	s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}				t_list;

char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *s1);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const
	char *needle, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strnew(size_t size);

int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

void			ft_bzero(void *s, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memalloc(size_t size);

void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *str);

t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int				ft_sqrt(int nb);
int				*ft_sortint(int *array, int len);
void			ft_swap(int *a, int *b);
size_t			ft_lstcount(t_list *lst);
void			ft_arrprint(char **ar);
void			ft_mem_removal(char **str);
int				ft_part_itoa(int nb);
int				get_next_line(const int fd, char **line);

char			*ft_itoa_long(long long int n);
char			*ft_itoa_double(double n, int precision);
char			*add_to_double(int precision, double *n);
int				ft_len_unsigned(unsigned long long int nb);
char			*ft_itoa_unsigned(unsigned long long int n);
int				ft_printf(char *str, ...);
char			*ft_strjoin_f(char **s1, char **s2);
int				ft_putstr_f(char *s);
int				flag_check_for_char(char *format, int zero, int minus, int i);
int				flag_check(char *format, int i, int zero);
int				flag_check_unsigned(char *format, int i, int zero);
void			precision_check(char **format, int *precision, va_list argm);
void			width_check(char *format, int *width, int *precision,
	va_list argm);
char			*to_check_specificator(char *format, va_list argm);
char			*to_check_specificator_unsigned(char *format, va_list argm);
char			*to_check_specificator_hex(char *format, va_list argm, int x);
char			*to_check_specificator_octal(char *format, va_list argm);
int				to_convert_hex(int s, int x);
char			*to_hex(unsigned long long int k, int x);
char			*to_octal(unsigned long long k);
void			init_wchar(char *f, wchar_t c, int m);
void			ft_putnchar(char *f, int size);
int				ft_print_w(char *p, unsigned int e, wchar_t c);
int				ft_putwchar(wchar_t c);
int				ft_ws_len(wchar_t c);
int				unicode_print_char(va_list argm);
int				unicode_null(int flag, int width, int precision);
int				unicode_flag_dealer(int flag, int width, int ws_length);
int				unicode_precision(int precision, wchar_t *f, int *l);
int				unicode_print(va_list argm, int flag, int width,
	int precision);
void			to_put_string_and_char(int flag, int width, int prec,
	char **to_print);
char			*char_types(char current_type, int *precision, va_list argm);
char			*numb_types(char c_type, va_list argm, char *format, int *flag);
char			*numb_types_helper(int *flag, char c_type, va_list argm,
	char *f);
int				all_flags_checker(char c_type, int *width, char *format);
void			to_sort_width_and_prec(int flag, int w, int prec,
	char **to_print);
void			to_employ_width(int flag, int width, int s_or_z,
	char **to_print);
void			to_employ_precision(int flag, int prec, char **to_print,
	int s_or_z);
char			*precision_helper(int flag, int x, int prec, char *to_join);
int				to_get_x(int *flag);
int				all_for_char(va_list argm, int flag, int width);
int				main_sorter(char *format, va_list argm, char type, int width);
int				to_sort_types(char **str, va_list argm, int current_count);

#endif
