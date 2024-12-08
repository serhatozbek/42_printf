/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:38:27 by sozbek            #+#    #+#             */
/*   Updated: 2024/12/06 22:03:10 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_check(char a)
{
	return (a == 'c' || a == 'd' || a == 'i' || a == 'u' || a == '%' || a == 's'
		|| a == 'x' || a == 'X' || a == 'p' || a == '\0');
}

int	ft_putchar(char a)
{
	return (write(1, &a, 1));
}

static int	ft_format(va_list argument, char a)
{
	if (a == 'c')
		return (ft_putchar(va_arg(argument, int)));
	else if (a == 'd' || a == 'i')
		return (ft_putnbr(va_arg(argument, int)));
	else if (a == 'u')
		return (ft_unsigned(va_arg(argument, unsigned int)));
	else if (a == 's')
		return (ft_putstr(va_arg(argument, char *)));
	else if (a == '%')
		return (ft_putchar(a));
	else if (a == 'x' || a == 'X')
		return (ft_hexadecimal(va_arg(argument, unsigned int), a));
	else if (a == 'p')
		return (ft_point(va_arg(argument, unsigned long), 1));
	else if (a == '\0')
		return (-1);
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	argument;
	int		tmp;
	int		index;
	int		len;

	if (str == NULL)
		return (-1);
	va_start(argument, str);
	len = 0;
	index = -1;
	while (str[++index])
	{
		if (str[index] == '%' && ft_check(str[index + 1]))
		{
			tmp = ft_format(argument, str[++index]);
			if (tmp == -1)
				return (va_end(argument), -1);
			len += tmp - 1;
		}
		else if (ft_putchar(str[index]) == -1)
			return (va_end(argument), -1);
		len++;
	}
	return (va_end(argument), len);
}
