/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:24:19 by phijano-          #+#    #+#             */
/*   Updated: 2022/05/18 13:54:38 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_base(unsigned int n, char c)
{
	int				length;
	unsigned int	base;

	if (c == 'u')
		base = 10;
	else
		base = 16;
	length = 0;
	if (n >= base)
	{
		length = length + ft_put_unsigned_base(n / base, c);
		length = length + ft_put_unsigned_base(n % base, c);
	}
	else
	{
		if (n < 10)
			length = length + ft_putchar(n % base + '0');
		else if (c == 'x')
			length = length + ft_putchar(n - 10 + 'a');
		else
			length = length + ft_putchar(n - 10 + 'A');
	}
	return (length);
}
