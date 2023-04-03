/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:21:52 by phijano-          #+#    #+#             */
/*   Updated: 2022/05/18 13:53:44 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
		length = ft_putstr("-2147483648");
	else if (n < 0)
	{
		length = ft_putchar('-');
		length = length + ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		length = length + ft_putnbr(n / 10);
		length = length + ft_putchar(n % 10 + '0');
	}
	else
		length = length + ft_putchar(n + '0');
	return (length);
}
