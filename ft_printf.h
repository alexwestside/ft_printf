// Created by Rizhiy Alexandr on 06.01.17.

#ifndef PRINTF_H
#define PRINTF_H

#define DEC_BASE "0123456789"
#define OCT_BASE "01234567"
#define BIN_BASE "01"
#define HEx_BASE "0123456789abcdef"
#define HEX_BASE "0123456789ABCDEF"

#include "libft.h"
#include <stddef.h>
#include <stdarg.h>
#include <locale.h>
#include <wchar.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>

typedef struct  s_flag
{
	int flag_alter_form     : 1;    // #
	int flag_zero_padd      : 1;    // 0
	int flag_align_fild     : 1;    // -
	int flag_sing_padd      : 1;    // +
	int flag_blank_poss     : 1;    // ' '
	int flag_min_fild_width : 1;    // *
	int flag_precision      : 1;    // .
	int flag_apostrophe     : 1;    // '
	int  flag_$             : 1;    // $
	int  flag_L             : 1;    // L
	unsigned int width;             // установка ширины
	unsigned int precision;         // установка точности

	enum {none, h, hh, l, ll, j, z, t} flag_size_spec;
}               t_flag;

typedef ssize_t (*convers_form)(va_list *, t_flag *);

int 			ft_printf(const char* format, ...);
size_t ft_finder(const char *f, va_list *arg_p, size_t res);
ssize_t ft_parse(char **f, va_list *arg_p, t_flag *flags);
uintmax_t 		unsingned_size(va_list *arg_p, t_flag *flags);
intmax_t 		singned_size(va_list *arg_p, t_flag *flags);
char 			*ft_size_spec(char **s, t_flag *flags, char flag);
char 			*ft_flag_char(char **s, t_flag *flags);
char 			*ft_min_fild_width(char **s, t_flag *flags, va_list *arg_p);
char 			*ft_precision(char **s, t_flag *flags, va_list *arg_p);

/*
convers_form ft_print_format(char c, va_list *arg_p, t_flag *flags);
*/

ssize_t ft_print_format(char **f, va_list *arg_p, t_flag *flags);


ssize_t 		ft_arg_void(va_list *arg_p, t_flag *flags);
ssize_t 		ft_signed_int_decimal_long(va_list *arg_p, t_flag *flags);
ssize_t 		ft_octal_long(va_list *arg_p, t_flag *flags);
ssize_t 		ft_octal(va_list *arg_p, t_flag *flags);
ssize_t 		ft_character(va_list *arg_p, t_flag *flags);
ssize_t 		ft_wcharacter(va_list *arg_p, t_flag *flags);
ssize_t 		ft_single_persent(va_list *arg_p, t_flag *flags);
ssize_t 		ft_binary(va_list *arg_p, t_flag *flags);
ssize_t 		ft_unsigned_decimal(va_list *arg_p, t_flag *flags);
ssize_t 		ft_unsigned_decimal_long(va_list *arg_p, t_flag *flags);
ssize_t 		ft_unsigned_hexadesimal_X(va_list *arg_p, t_flag *flags);
ssize_t 		ft_unsigned_hexadesimal_x(va_list *arg_p, t_flag *flags);
ssize_t 		ft_signed(intmax_t num, t_flag *flags, char *base, char *prefix);
ssize_t 		ft_signed_int_decimal(va_list *arg_p, t_flag *flags);
ssize_t 		ft_unsigned(uintmax_t num, t_flag *flags, char *base, char *prefix);
ssize_t 		ft_string(va_list *arg_p, t_flag *flags);
ssize_t 		ft_wstring(va_list *arg_p, t_flag *flags);
ssize_t 		ft_null_format(char **format, va_list *arg_p, t_flag *flags);

void 			ft_num_width(uintmax_t num, char *base, unsigned int num_len, t_flag *flags);
void 			ft_put_num_base(uintmax_t num, char *base);
void 			ft_width_padd(size_t num_len, unsigned int width, char width_padd);
unsigned int 	ft_num_strlen(uintmax_t num, char *base, char *prefix, t_flag *flags);
unsigned int 	ft_num_len(uintmax_t num, t_flag *flags, char *base);
/*unsigned*/ int 	ft_max(/*unsigned*/ int width, /*unsigned*/ int len);
void			ft_putnstr(char const *s, size_t len);
char    		*ft_strndup(char *sorc, size_t n);
char    		*ft_strnjoin(char const *s1, char const *s2, size_t len);
size_t 			ft_strnlen(char *str, size_t strlen);

void ft_check(char **s, t_flag *flags);
void ft_check2(char **s, t_flag *flags, char flag);
void ft_check3(char **s, t_flag *flags, va_list *arg_p);
void ft_check4(char **s, t_flag *flags, char *arg_p);


size_t ft_wstrlen(wchar_t *str, unsigned int precision, size_t len);
size_t ft_wcharlen(int c);


#endif //TEST_ARR_POINT_PRINTF_H