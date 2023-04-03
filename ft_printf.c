/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:38:19 by phijano-          #+#    #+#             */
/*   Updated: 2022/05/18 13:55:04 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length = ft_putchar(va_arg(args, int));
	else if (c == 's')
		length = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		length = ft_putptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		length = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		length = ft_put_unsigned_base(va_arg(args, unsigned int), c);
	else if (c == 'x' || c == 'X')
		length = ft_put_unsigned_base(va_arg(args, unsigned int), c);
	else if (c == '%')
		length = ft_putchar('%');
	return (length);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count;
	int		length;

	va_start(args, str);
	count = 0;
	length = 0;
	while (str[count])
	{
		if (str[count] == '%')
		{
			count++;
			if (str[count])
				length = length + ft_format(args, str[count]);
			else
				count--;
		}
		else
			length = length + ft_putchar(str[count]);
		count++;
	}
	va_end(args);
	return (length);
}
