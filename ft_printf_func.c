/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:40:02 by sozbek            #+#    #+#             */
/*   Updated: 2024/12/06 22:01:43 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int a)
{
	int	len;
	int	tmp;

	len = 0;
	if (a == 0)
		return (ft_putchar('0'));
	if (a == -2147483648)
		return (ft_putstr("-2147483648"));
	if (a < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len++;
		a *= -1;
	}
	if (a > 9)
	{
		tmp = ft_putnbr(a / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar((a % 10) + 48) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int a)
{
	int	len;
	int	tmp;

	len = 0;
	if (a > 9)
	{
		tmp = ft_unsigned(a / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (ft_putchar(a % 10 + 48) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[++i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
	}
	return (i);
}

int	ft_hexadecimal(unsigned int a, char b)
{
	int	len;
	int	tmp;

	len = 0;
	if (a >= 16)
	{
		tmp = ft_hexadecimal(a / 16, b);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (b == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[a % 16], 1) == -1)
			return (-1);
	}
	if (b == 'x')
	{
		if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_point(unsigned long a, int b)
{
	int	len;
	int	tmp;

	len = 0;
	if (!a)
		return (ft_putstr("(nil)"));
	if (b == 1)
	{
		tmp = ft_putstr("0x");
		if (tmp == -1)
			return (-1);
		len += tmp;
		b = 0;
	}
	if (a >= 16)
	{
		tmp = ft_point(a / 16, b);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789abcdef"[a % 16], 1) == -1)
		return (-1);
	return (len + 1);
}
