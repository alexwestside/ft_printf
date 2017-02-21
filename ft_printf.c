
#include "ft_printf.h"

ssize_t ft_parse(char **f, va_list *arg_p, t_flag *flags)
{
	char flag;
	ssize_t res = 0;

	if (*(*f)++ == '\0')
		return (res);
	ft_flag_char(f, flags);
	ft_min_fild_width(f, flags, arg_p);
	ft_precision(f, flags, arg_p);
	flag = **f;
	ft_size_spec(f, flags, flag);
	if (!**f)
		return (0);
	res = ft_print_format(f, arg_p, flags);
		(*f)++;
	return (int) (res);
}

/*
ssize_t ft_parse(char **f, va_list *arg_p, t_flag *flags)
{
	ssize_t res = 0;

	if (*(*f)++ == '\0')
		return (res);
	ft_flag_char(f, flags);
	ft_min_fild_width(f, flags, arg_p);
	ft_precision(f, flags, arg_p);
	ft_size_spec(f, flags);
	if (!**f)
		return (0);
	//if ((res = ft_print_format(**f, arg_p, flags)) == NULL) {
	//	(*f)++;
	//	res = ft_null_format(f, arg_p, flags);
	//}
	//else
	res = ft_print_format(**f, arg_p, flags);
	(*f)++;
	return (int) (res);
}
*/


/*
ssize_t ft_parse(char **f, va_list *arg_p, t_flag *flags)
{
	ssize_t res = 0;
	convers_form h;

	if (*(*f)++ == '\0')
		return (0);
	ft_flag_char(f, flags);
	ft_min_fild_width(f, flags, arg_p);
	ft_precision(f, flags, arg_p);
	ft_size_spec(f, flags);
	if (!**f)
		return (0);
	if (ft_print_format(**f, arg_p, flags) == NULL)
		h = (convers_form) ft_null_format(f, arg_p, flags);
	else
		h = (convers_form) ft_print_format(**f, arg_p, flags);
	res = ft_print_format(**f, arg_p, flags);
	(*f)++;
	return (int) (res);
}
*/

size_t ft_finder(const char *f, va_list *arg_p, size_t res)
{
	char *p;
	ssize_t len;
	t_flag flags;

	p = strchr(f, '%');
	if (*f == '\0')
		return (res);
	if (p > f)
	{
		ft_putnstr(f, (p - f));
		res = ft_finder(p, arg_p, res + (p - f));
		return (res);
	}
	else if (p == NULL)
	{
		res += ft_strlen(f);
		ft_putstr(f);
		return (res);
	}
	else
	{
		ft_bzero(&flags, sizeof(flags));
		len = ft_parse((char **) &f, arg_p, &flags);
		res = ft_finder(f, arg_p, res + len);
		return (res);
	}
}

int ft_printf(const char *format, ...)
{
    va_list arg_p;
    //char *f;
    size_t res;
	res = 0;

    //f = (char *) format;
    va_start(arg_p, format);
    //arg = va_arg(arg_p, void *);
	res = ft_finder(format, &arg_p, res);
    //if ((res = ft_find_spec_form(f, &arg_p, res)) < 0)
    //   return (-1);
    va_end(arg_p);
    return (int) (res);
	//return (5);
}