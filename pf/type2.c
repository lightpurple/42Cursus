#include "ft_printf.h"

int	print_space(int width, int s_len, char *num, int flag)
{
	int len;

	len = 0;
	if (flag == ONLY)
	{
		while (width-- > s_len)
			len += write(1, " ", 1);
	}
	else if (flag == LEFT)
	{
		if (width > s_len)
			while (width-- > s_len)
				len += write(1, " ", 1);
		len += write(1, num, s_len);
	}
	else
	{
		len += write(1, num, s_len);
		if (width > s_len)
			while (width-- > s_len)
				len += write(1, " ", 1);
	}
	return (len);
}

int	print_zero(int width, int s_len, char *num)
{
	int len;

	len = 0;
	if (width > s_len)
		while (width-- > s_len)
			len += write(1, "0", 1);
	len += write(1, num, s_len);
	return (len);
}

int	print_x(va_list ap, t_info info)
{

}

int	print_ux(va_list ap, t_info info)
{

}

int	print_n(va_list ap, t_info info)
{

}
