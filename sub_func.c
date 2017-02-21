
#include "ft_printf.h"

/*unsigned*/ int ft_max(/*unsigned*/ int width, /*unsigned*/ int len)
{
	if (width > len)
		return (width);
	else
		return (len);
}

unsigned int ft_num_len(uintmax_t num, t_flag *flags, char *base)
{
	(void) flags;
	ssize_t base_len;
	unsigned int i;

	i = 0;
	base_len = ft_strlen(base);
	if (!num)
		return (1);
	while (num) {
		num = num / base_len;
		i++;
	}
	return (i);
}

unsigned int ft_num_strlen(uintmax_t num, char *base, char *prefix, t_flag *flags)
{
	unsigned int num_len;
	unsigned int num_strlen;

	num_len = ft_num_len(num, flags, base);
	if (!num && flags->flag_precision && !flags->precision)
		num_strlen = 0;
	else if (flags->flag_precision)
		num_strlen = ft_max(num_len, flags->precision);
	else
		num_strlen = num_len;
	if (flags->flag_alter_form && prefix && num)
		num_strlen = num_strlen + ft_strlen(prefix);
	return (num_strlen);
}

void ft_width_padd(size_t num_len, unsigned int width, char width_padd)
{
	while (num_len < width) {
		ft_putchar(width_padd);
		num_len++;
	}
}

void ft_put_num_base(uintmax_t num, char *base)
{
	if (num >= ft_strlen(base)) {
		ft_put_num_base(num / ft_strlen(base), base);
		ft_put_num_base(num % ft_strlen(base), base);
	}
	else
		ft_putchar(base[num]);
}

void ft_num_width(uintmax_t num, char *base, unsigned int num_len, t_flag *flags)
{
	if (flags->flag_precision)
		ft_width_padd(num_len, flags->precision, '0');
	if (!num && flags->flag_precision && !flags->precision)
		return;
	else
		ft_put_num_base(num, base);
}

/*void	ft_putnstr(char const *s, size_t len)
{
	while (*s) {
		if (*s >= 32 && *s <= 126)
			ft_putchar(*s);
		else
			write(1, s, 1);
		s++;
	}
}*/


void	ft_putnstr(char const *s, size_t len)
{
	if (s)
		write(1, s, len);
}

char    *ft_strndup(char *sorc, size_t n)
{
	char        *dup;

	if (!(dup = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	dup = ft_strncpy(dup, sorc, n);
	dup[n] = '\0';
	return (dup);
}

char    *ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char        *s3;

	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen(s1) + len)))
		return (NULL);
	s3 = ft_strcpy(s3, s1);
	s3 = ft_strncat(s3, s2, len);
	return (s3);
}

size_t ft_strnlen(char *str, size_t strlen)
{
	size_t i;

	i = 0;
	while (strlen) {
		i++;
		strlen--;
		str++;
	}
	return (i);
}

size_t ft_wstrlen(wchar_t *s, unsigned int precision, size_t len)
{
	if (!s || !precision)
		return (len);
	else if (*s <= 0x7F)
		return (ft_wstrlen(s + 1, precision - 1, len + 1));
	else if (*s <= 0x7FF && precision >= 2)
		return (ft_wstrlen(s + 1, precision - 2, len + 2));
	else if (*s <= 0xFFFF && precision >= 3)
		return (ft_wstrlen(s + 1, precision - 3, len + 3));
	else if (*s <= 0x10FFFF && precision >= 4)
		return (ft_wstrlen(s + 1, precision - 4, len + 4));
	else
		return (len);
}

size_t ft_wcharlen(int c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	else
		return (0);
}