/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 05:06:00 by amoubare          #+#    #+#             */
/*   Updated: 2021/11/28 00:00:33 by amoubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hexa(unsigned long long n, char c, int *count)
{
	if (n <= 9)
	{
		ft_putchar(n + '0', count);
	}
	else if (n >= 10 && n <= 15)
	{
		if (c == 'X')
			ft_putchar(n + 55, count);
		else
			ft_putchar(n + 87, count);
	}
	else
	{
		ft_putnbr_hexa(n / 16, c, count);
		ft_putnbr_hexa(n % 16, c, count);
	}
}
