
#include "ft_printf.h"

ssize_t ft_signed(intmax_t num, t_flag *flags, char *base, char *prefix)
{
	size_t str_len;
	//unsigned int str_len;
	size_t prefix_len;
	ssize_t res;

	prefix_len = ft_strlen(prefix);
	str_len = prefix_len + ft_num_strlen(num, base, NULL, flags);
	if (flags->flag_min_fild_width && !flags->flag_align_fild && !flags->flag_zero_padd)
	{
		ft_width_padd(str_len, flags->width, ' ');
		//prefix_len = prefix_len + flags->width > str_len ? ft_max(/*(unsigned int) */(flags->width - str_len), 0) : 0;
		prefix_len = prefix_len + ft_max(/*(unsigned int) */(flags->width - str_len), 0);
		flags->flag_min_fild_width = 0;
	}
	else if (flags->flag_min_fild_width)
		flags->width = (unsigned int) (flags->width - prefix_len);
	ft_putstr(prefix);
	res = ft_unsigned((uintmax_t) num, flags, base, NULL);
	return (res + prefix_len);
}

ssize_t ft_unsigned(uintmax_t num, t_flag *flags, char *base, char *prefix)
{
	unsigned int num_len;
	unsigned int str_len;
	ssize_t res;

	if (flags->flag_precision)
		flags->flag_zero_padd = 0;
	num_len = ft_num_len(num, flags, base);
	if (flags->flag_min_fild_width && !flags->flag_align_fild && flags->flag_zero_padd) {
		if (flags->flag_precision)
			flags->precision = ft_max(flags->width, flags->precision);
		else
			flags->precision = ft_max(flags->width, num_len);
		flags->flag_precision = 1;
		flags->flag_min_fild_width = 0;
	}
	str_len = ft_num_strlen(num, base, prefix, flags);
	if (flags->flag_min_fild_width && !flags->flag_align_fild)
		ft_width_padd(str_len, flags->width, ' ');
	if (flags->flag_alter_form && prefix && num) {
		ft_putstr(prefix);
		if (flags->flag_zero_padd)
		{
			str_len -= 2;
			flags->precision -= 2;
		}
	}
	ft_num_width(num, base, num_len, flags);
	if (flags->flag_min_fild_width && flags->flag_align_fild)
		ft_width_padd(str_len, flags->width, ' ');
	res = (flags->flag_min_fild_width ? ft_max(str_len, flags->width) : str_len);
	return (res);
}

ssize_t ft_signed_int_decimal(va_list *arg_p, t_flag *flags)
{
//	(void) flags;
	intmax_t num;
	char *prefix = NULL;
	ssize_t res;

	num = singned_size(arg_p, flags);
	if (num < 0 || flags->flag_blank_poss || flags->flag_sing_padd) {
		if (num < 0) {
			num = -num;
			prefix = "-";
		}
		else if (flags->flag_sing_padd)
			prefix = "+";
		else if (flags->flag_blank_poss)
			prefix = " ";
		res = ft_signed(num, flags, DEC_BASE, prefix);
		return (res);
	}
	else {
		res = ft_unsigned((uintmax_t) num, flags, DEC_BASE, NULL);
		return (res);
	}
}


ssize_t ft_unsigned_hexadesimal_x(va_list *arg_p, t_flag *flags)
{
	uintmax_t num;
	ssize_t res;

	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, HEx_BASE, "0x");
	return (res);
}

ssize_t ft_unsigned_hexadesimal_X(va_list *arg_p, t_flag *flags)
{
	uintmax_t num;
	ssize_t res;
	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, HEX_BASE, "0X");
	return (res);
}

ssize_t ft_unsigned_decimal_long(va_list *arg_p, t_flag *flags)
{
	ssize_t res;
	uintmax_t num;
	flags->flag_size_spec = l;
	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, DEC_BASE, NULL);
	return (res);
}

ssize_t ft_unsigned_decimal(va_list *arg_p, t_flag *flags)
{

	ssize_t res;
	uintmax_t num;

	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, DEC_BASE, NULL);
	return (res);
}

ssize_t ft_binary(va_list *arg_p, t_flag *flags)
{
	ssize_t res;
	uintmax_t num;

	num = unsingned_size(arg_p, flags);
	res = ft_unsigned(num, flags, BIN_BASE, "0b");
	return (res);
}

ssize_t	ft_single_persent(va_list *arg_p, t_flag *flags)
{
	char width_padd;
	ssize_t res;
	(void) arg_p;

	if (flags->flag_min_fild_width && !flags->flag_align_fild) {
		width_padd = (char) (flags->flag_zero_padd ? '0' : ' ');
		ft_width_padd(1, flags->width, width_padd);
	}
	ft_putchar('%');
	if (flags->flag_min_fild_width && flags->flag_align_fild)
		ft_width_padd(1, flags->width, ' ');
	res = flags->flag_min_fild_width ? ft_max(flags->width, 1) : 1;
	return (res);
}

ssize_t ft_wcharacter(va_list *arg_p, t_flag *flags)
{
	ssize_t res;
	//wchar_t *str;
	wchar_t c;
	//unsigned int str_len;
	unsigned int char_len;
	char width_padd;

	//str = va_arg(*arg_p, wint_t);
	//str_len = ft_wchar_strlen(str);
	c = (wchar_t) va_arg(*arg_p, wint_t);
	//str_len = ft_strlen(str);
	char_len = ft_wcharlen(c);
	width_padd = (char) (flags->flag_zero_padd ? '0' : ' ');
	if (flags->flag_min_fild_width && !flags->flag_align_fild)
		ft_width_padd(char_len, flags->width, width_padd);
		// ft_width_padd(str_len, flags->width, width_padd);
	//ft_putstr((const char *) str)
	ft_putchar(c);
	if (flags->flag_min_fild_width && flags->flag_align_fild)
		ft_width_padd(char_len, flags->width, width_padd);
		//ft_width_padd(str_len, flags->width, width_padd);
	res = flags->flag_min_fild_width ? ft_max(char_len, flags->width) : char_len;
	//res = flags->flag_min_fild_width ? ft_max(str_len, flags->width) : str_len;
	return (res);
}

ssize_t ft_character(va_list *arg_p, t_flag *flags)
{
	char width_padd;
	ssize_t res;

	if (flags->flag_size_spec == l)
		ft_wcharacter(arg_p, flags);
	else {
		if (flags->flag_min_fild_width && !flags->flag_align_fild) {
			width_padd = (char) (flags->flag_zero_padd ? '0' : ' ');
			ft_width_padd(1, flags->width, width_padd);
		}
		ft_putchar(va_arg(*arg_p, int));
		if (flags->flag_min_fild_width && flags->flag_align_fild)
			ft_width_padd(1, flags->width, ' ');
	}
	res = flags->flag_min_fild_width ? ft_max(flags->width, 1) : 1;
	return (res);
}

ssize_t ft_octal(va_list *arg_p, t_flag *flags)
{
	ssize_t res;
	uintmax_t num;
	char width_padd;
	unsigned int num_len;

	num = unsingned_size(arg_p, flags);
	num_len = ft_num_len(num, flags, OCT_BASE);
	if (flags->flag_alter_form && !num && !flags->precision) {
		if (flags->flag_min_fild_width && !flags->flag_alter_form) {
			width_padd = (char) (flags->flag_zero_padd ? '0' : ' ');
			ft_width_padd(1, flags->width, width_padd);
		}
		ft_putchar('0');
		if (flags->flag_min_fild_width && flags->flag_align_fild)
			ft_width_padd(1, flags->width, ' ');
		res = flags->width ? ft_max(flags->width, 1) : 1;
		return (res);
	}
	else if (flags->flag_alter_form && num) {
		flags->flag_precision = 1;
		flags->precision = ft_max(flags->precision, num_len + 1);
	}
	res = ft_unsigned(num, flags, OCT_BASE, NULL);
	return (res);
}

ssize_t ft_octal_long(va_list *arg_p, t_flag *flags)
{
	ssize_t res;

	flags->flag_size_spec = l;
	res = ft_octal(arg_p, flags);
	return (res);
}

ssize_t ft_signed_int_decimal_long(va_list *arg_p, t_flag *flags)
{
	ssize_t res;

	flags->flag_size_spec = l;
	res = ft_signed_int_decimal(arg_p, flags);
	return (res);
}

ssize_t ft_arg_void(va_list *arg_p, t_flag *flags)
{
	ssize_t res;
	uintmax_t num;

	flags->flag_size_spec = z;
	if (flags->flag_precision)
		flags->flag_zero_padd = 0;
	num = unsingned_size(arg_p, flags);
	res = ft_signed(num, flags, HEx_BASE, "0x");
	return (res);

}

ssize_t ft_wstring(va_list *arg_p, t_flag *flags)
{
	ssize_t res;
	wchar_t *str;
	size_t strlen;
	//size_t strlen2;
	char width_padd;

	str = va_arg(*arg_p, wchar_t*);
	if (!str || *str == L'(')
		str = (wchar_t *) "(null)";
	if (flags->flag_precision)
	{
		//strlen = ft_strlen((const char *) str);
		strlen = ft_strnlen((char *) str, flags->precision);
		//strlen = ft_wstrlen(str, flags->precision, 0);
	}
	if (!flags->flag_precision)
		strlen = ft_strlen((const char *) str);
	width_padd = (char) (flags->flag_zero_padd ? '0' : ' ');
	if (flags->flag_min_fild_width && !flags->flag_align_fild)
		ft_width_padd(strlen, flags->width, width_padd);
	ft_putnstr((const char *) str, strlen);
	if (flags->flag_min_fild_width && flags->flag_align_fild)
		ft_width_padd(strlen, flags->width, ' ');
	res = flags->flag_min_fild_width ? ft_max(flags->width, strlen) : strlen;
	return (res);
}

ssize_t ft_string(va_list *arg_p, t_flag *flags)
{
	ssize_t res;
	size_t strlen;
	char *str;
	char width_padd;

	if (flags->flag_size_spec == l)
	{
		res = ft_wstring(arg_p, flags);
		return (res);
	}
	else
	{
		str = va_arg(*arg_p, char*);
		if (!str)
			str = "(null)";
		if (flags->flag_precision)
			strlen = ft_strnlen(str, flags->precision);
		if (!flags->flag_precision)
			strlen = ft_strlen(str);
		width_padd = (char) (flags->flag_zero_padd ? '0' : ' ');
		if (flags->flag_min_fild_width && !flags->flag_align_fild)
			ft_width_padd(strlen, flags->width, width_padd);
		ft_putnstr(str, strlen);
		if (flags->flag_min_fild_width && flags->flag_align_fild)
			ft_width_padd(strlen, flags->width, ' ');
		res = flags->flag_min_fild_width ? ft_max(flags->width, strlen) : strlen;
		return (res);
	}
}

ssize_t ft_null_format(char **format, va_list *arg_p, t_flag *flags)
{
	char width_padd;
	ssize_t res;
	(void) arg_p;

	width_padd = (char) (flags->flag_zero_padd ? '0' : ' ');
	if (flags->flag_min_fild_width && !flags->flag_align_fild)
		ft_width_padd(1, flags->width, width_padd);
	ft_putchar(**format);
	if (flags->flag_min_fild_width && flags->flag_align_fild)
		ft_width_padd(1, flags->width, ' ');
	res = flags->flag_min_fild_width ? ft_max(flags->width, 1) : 1;
	return (res);
}
