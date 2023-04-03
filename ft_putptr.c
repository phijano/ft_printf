/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:20:04 by phijano-          #+#    #+#             */
/*   Updated: 2022/05/18 13:54:01 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr(unsigned long long num)
{
	int	length;

	length = 0;
	if (num >= 16)
	{
		length = length + ft_print_ptr(num / 16);
		length = length + ft_print_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			length = length + ft_putchar(num + '0');
		else
			length = length + ft_putchar(num - 10 + 'a');
	}
	return (length);
}

int	ft_putptr(unsigned long long ptr)
{
	int	length;

	length = 2;
	write(1, "0x", 2);
	if (ptr == 0)
		length = length + ft_putchar('0');
	else
	{
		length = length + ft_print_ptr(ptr);
	}
	return (length);
}
