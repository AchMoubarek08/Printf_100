/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 02:50:37 by amoubare          #+#    #+#             */
/*   Updated: 2021/11/28 00:17:39 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conditions(char c, void *args, int *count)
{
	if (c == 'd' || c == 'i')
		ft_putnbr((int)args, count);
	else if (c == 'c')
		ft_putchar((int)args, count);
	else if (c == 's')
		ft_putstr((char *)args, count);
	else if (c == 'u')
		ft_putunsigned((unsigned int)args, count);
	else if (c == 'X')
		ft_putnbr_hexa((unsigned int)args, 'X', count);
	else if (c == 'x')
		ft_putnbr_hexa((unsigned int)args, 'x', count);
	else if (c == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_hexa((unsigned long long)args, 'x', count);
	}
}

int	ft_printf(const char *s, ...)
{
	int		c;
	va_list	args;

	va_start(args, s);
	c = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'u' || *s == 'd' || *s == 'i' || *s == 'x'
				|| *s == 'X' || *s == 'p' || *s == 'c' || *s == 's')
			{
				ft_conditions(*s, va_arg(args, void *), &c);
			}
			else
				ft_putchar(*s, &c);
		}
		else
			ft_putchar(*s, &c);
		s++;
	}
	va_end(args);
	return (c);
}
