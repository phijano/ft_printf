/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:55:01 by phijano-          #+#    #+#             */
/*   Updated: 2022/05/18 12:57:03 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long long ptr);
int	ft_putnbr(int n);
int	ft_put_unsigned_base(unsigned int n, char c);

#endif
