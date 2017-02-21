
#include "ft_printf.h"

ssize_t ft_print_format(char **f, va_list *arg_p, t_flag *flags)
{
	//int i = 0;
	ssize_t res = 0;
	convers_form arr_convers[300];
	char *str = (char *)"sSpdDioOuUxXcCb%";

	arr_convers['s'] = (convers_form) &ft_string;
	//arr_convers['S'] = (convers_form) &ft_string;
	arr_convers['S'] = (convers_form) &ft_wstring;
	arr_convers['p'] = (convers_form) &ft_arg_void;
	arr_convers['d'] = (convers_form) &ft_signed_int_decimal;
	arr_convers['D'] = (convers_form) &ft_signed_int_decimal_long;
	arr_convers['i'] = (convers_form) &ft_signed_int_decimal;
	arr_convers['o'] = (convers_form) &ft_octal;
	arr_convers['O'] = (convers_form) &ft_octal_long;
	arr_convers['u'] = (convers_form) &ft_unsigned_decimal;
	arr_convers['U'] = (convers_form) &ft_unsigned_decimal_long;
	arr_convers['x'] = (convers_form) &ft_unsigned_hexadesimal_x;
	arr_convers['X'] = (convers_form) &ft_unsigned_hexadesimal_X;
	arr_convers['c'] = (convers_form) &ft_character;
	arr_convers['C'] = (convers_form) &ft_character;
	//arr_convers['C'] = (convers_form) &ft_wcharacter;
	arr_convers['b'] = (convers_form) &ft_binary;
	arr_convers['%'] = (convers_form) &ft_single_persent;

	//arr_convers['n'] = (convers_form) ft_arg_int;
	//arr_convers['f'] = (convers_form) ft_signed_decimal;
	//arr_convers['F'] = (convers_form) ft_signed_decimal;
	//arr_convers['e'] = (convers_form) ft_signed_decimal;
	//arr_convers['E'] = (convers_form) ft_signed_decimal;
	//arr_convers['g'] = (convers_form) ft_signed_decimal;
	//arr_convers['G'] = (convers_form) ft_signed_decimal;
	//arr_convers['a'] = (convers_form) ft_signed_hexadecimal;
	//arr_convers['A'] = (convers_form) ft_signed_hexadecimal;

	if (!ft_strchr((const char *)str, **f)) {
		res = ft_null_format(f, arg_p, flags);
		//(*f)++;
		return (res);
	}
	else
		return ((arr_convers[**f])(arg_p, flags));
}

/*
ssize_t ft_print_format(char c, va_list *arg_p, t_flag *flags)
{
	convers_form arr_convers[300];

	arr_convers['s'] = (convers_form) &ft_string;
	arr_convers['S'] = (convers_form) &ft_wstring;
	arr_convers['p'] = (convers_form) &ft_arg_void;
	arr_convers['d'] = (convers_form) &ft_signed_int_decimal;
	arr_convers['D'] = (convers_form) &ft_signed_int_decimal_long;
	arr_convers['i'] = (convers_form) &ft_signed_int_decimal;
	arr_convers['o'] = (convers_form) &ft_octal;
	arr_convers['O'] = (convers_form) &ft_octal_long;
	arr_convers['u'] = (convers_form) &ft_unsigned_decimal;
	arr_convers['U'] = (convers_form) &ft_unsigned_decimal_long;
	arr_convers['x'] = (convers_form) &ft_unsigned_hexadesimal_x;
	arr_convers['X'] = (convers_form) &ft_unsigned_hexadesimal_X;
	arr_convers['c'] = (convers_form) &ft_character;
	arr_convers['C'] = (convers_form) &ft_wcharacter;
	arr_convers['b'] = (convers_form) &ft_binary;
	arr_convers['%'] = (convers_form) &ft_single_persent;

	//arr_convers['n'] = (convers_form) ft_arg_int;
	//arr_convers['f'] = (convers_form) ft_signed_decimal;
	//arr_convers['F'] = (convers_form) ft_signed_decimal;
	//arr_convers['e'] = (convers_form) ft_signed_decimal;
	//arr_convers['E'] = (convers_form) ft_signed_decimal;
	//arr_convers['g'] = (convers_form) ft_signed_decimal;
	//arr_convers['G'] = (convers_form) ft_signed_decimal;
	//arr_convers['a'] = (convers_form) ft_signed_hexadecimal;
	//arr_convers['A'] = (convers_form) ft_signed_hexadecimal;

	return ((arr_convers[(int) c])(arg_p, flags));
}
*/