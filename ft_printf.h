/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozbek <sozbek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:41:25 by sozbek            #+#    #+#             */
/*   Updated: 2024/12/06 22:01:42 by sozbek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char a);
int	ft_putnbr(int a);
int	ft_unsigned(unsigned int a);
int	ft_putstr(char *s);
int	ft_hexadecimal(unsigned int a, char b);
int	ft_point(unsigned long a, int b);

#endif
