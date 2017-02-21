
#include "ft_printf.h"


void ft_check(char **s, t_flag *flags)
{
	if (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' ' || **s == '*' || **s == 39)
		ft_flag_char(s, flags);
}

void ft_check4(char **s, t_flag *flags, char *arg_p)
{
	if (**s == '.')
		ft_precision(s, flags, arg_p);
}

void ft_check2(char **s, t_flag *flags, char flag)
{
	if (**s == 'l' || **s == 'h' || **s == 'j' || **s == 'z' || **s == 't' || **s == 'L')
		ft_size_spec(s, flags, flag);
}

void ft_check3(char **s, t_flag *flags, va_list *arg_p)
{
	if (**s == '.')
		ft_precision(s, flags, arg_p);
}

char *ft_precision(char **s, t_flag *flags, va_list *arg_p)
{
	int res;

	if (**s == '.') {
		(*s)++;
		if (**s == '*') {
			res = va_arg(*arg_p, int);
			if (res >= 0) {
				flags->flag_precision = 1;
				flags->precision = res;
				(*s)++;
			}
			else {
				//flags->width = res < 0 ? -res : res;
				(*s)++;
			}
			return (*s);
		}
		else {
			while (ft_isdigit(**s)) {
				flags->precision = flags->precision * 10 + (**s) - 48;
				(*s)++;
			}
			flags->flag_precision = 1;
			if (**s == '.' && !ft_isdigit(**s)) {
				//flags->flag_precision = 0;
				flags->precision = 0;
			}
			ft_precision(s, flags, arg_p);
			ft_check(s, flags);
			return (*s);
		}
	}
	else
		return (*s);
}

char *ft_min_fild_width(char **s, t_flag *flags, va_list *arg_p)
{
	int res;

	while (**s == '*' || ft_isdigit(**s)) {
		if (**s == '*') {
			(*s)++;
			res = va_arg(*arg_p, int);
			/*if (res < 0) {
				flags->flag_align_fild = 1;
				flags->width = -res;
			}
			flags->width = res;*/
			if (res < 0)
				flags->flag_align_fild = 1;
			//flags->flag_align_fild = res < 0 ? 1 : 0;
			flags->width = res < 0 ? -res : res;
			flags->flag_min_fild_width = 1;
		}
		if (ft_isdigit(**s)) {
			flags->flag_min_fild_width = 1;
			flags->width = 0;
			while (ft_isdigit(**s)) {
				flags->width = flags->width * 10 + (**s) - 48;
				(*s)++;
			}
		}
		ft_check(s, flags);
		ft_check3(s, flags, arg_p);
		//if (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' ' || **s == '*' || **s == 39)
		//	ft_flag_char(s, flags);
	}
	return (*s);
}

char *ft_flag_char(char **s, t_flag *flags)
{
	if (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' ' || **s == 39) {
		if (**s == '#')
			flags->flag_alter_form = 1;
		if (**s == '0')
			flags->flag_zero_padd = 1;
		if (**s == '-')
			flags->flag_align_fild = 1;
		if (**s == '+')
			flags->flag_sing_padd = 1;
		if (**s == ' ')
			flags->flag_blank_poss = 1;
		if (**s == 39)
			flags->flag_apostrophe = 1;
		if (**s == '$')
			flags->flag_$ = 1;
		if (**s == 'L')
			flags->flag_L = 1;
		(*s)++;
		if (flags->flag_align_fild)
			flags->flag_zero_padd = 0;
		return (ft_flag_char(s, flags));
	}
	return (*s);
}

char *ft_size_spec(char **s, t_flag *flags, char flag)
{

	if ((**s == 'l' && *(*s + 1) == 'l') || (**s == 'h' && *(*s + 1) == 'h'))
	{
		flags->flag_size_spec = (**s == 'l' && *(*s + 1) == 'l') ? ll : 0;
		flags->flag_size_spec = (**s == 'h' && *(*s + 1) == 'h') ?	hh	:	0;
		*s += 2;
		ft_size_spec(s, flags, flag);
		ft_flag_char(s, flags);
		return (*s);
	}
/*
	if (**s == 'l' && *(*s + 1) == 'l') {
		flags->flag_size_spec = ll;
		*s += 2;
		ft_check2(s, flags, flag);
		ft_check(s, flags);
		return (*s);
		//return (*s += 2);
	}
	else if (**s == 'h' && *(*s + 1) == 'h') {
		flags->flag_size_spec = hh;
		*s += 2;
		ft_check2(s, flags, flag);
		ft_check(s, flags);
		return (*s);
		//ft_check(s, flags);
		//return (*s += 2);
	}
 */
	else if (**s == 'l' || **s == 'h' || **s == 'j' || **s == 'z' || **s == 't' || **s == 'L') {
		if (flag <= **s) {
			flag = **s;
			if (**s == 'l')
				flags->flag_size_spec = l;
			if (**s == 'h')
				flags->flag_size_spec = h;
			if (**s == 'j')
				flags->flag_size_spec = j;
			if (**s == 'z')
				flags->flag_size_spec = z;
			if (**s == 't')
				flags->flag_size_spec = t;
		}
		(*s)++;
	}
	ft_check2(s, flags, flag);
	return (*s);
}

intmax_t singned_size(va_list *arg_p, t_flag *flags)
{
	intmax_t num;

	num = va_arg(*arg_p, intmax_t);
	if (flags->flag_size_spec == hh)
		num = (signed char) num;
	else if (flags->flag_size_spec == h)
		num = (signed short int) num;
	else if (flags->flag_size_spec == l)
		num = (long int) num;
	else if (flags->flag_size_spec == ll)
		num = (long long int) num;
	else if (flags->flag_size_spec == j)
		num = (intmax_t) num;
	else if (flags->flag_size_spec == z)
		num = (size_t) num;
	else
		num = (int) num;
	return (num);
}

uintmax_t unsingned_size(va_list *arg_p, t_flag *flags)
{
	uintmax_t num;

	num = va_arg(*arg_p, uintmax_t);
	if (flags->flag_size_spec == hh)
		num = (unsigned char) num;
	else if (flags->flag_size_spec == h)
		num = (unsigned short int) num;
	else if (flags->flag_size_spec == l)
		num = (unsigned long int) num;
	else if (flags->flag_size_spec == ll)
		num = (unsigned long long int) num;
	else if (flags->flag_size_spec == j)
		num = (uintmax_t) num;
	else if (flags->flag_size_spec == z)
		num = (size_t) num;
	else
		num = (unsigned int) num;
	return (num);
}