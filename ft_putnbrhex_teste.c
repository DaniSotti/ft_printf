/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:46:33 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/11 17:44:39 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int decimal)
{
	int	len;

	len = 0;
	while (decimal != 0)
	{
		decimal /= 16;
		len++;
	}
	return (len);
}

int	ft_putnbrhex(unsigned int decimal, char *base)
{
	char	hex[25];
	int		len;
	int		i;

	i = 0;
	len = ft_hexlen(decimal);
	if (decimal == 0)
		return (ft_putchar('0'));
	while (decimal != 0)
	{
		hex[i++] = base[decimal % 16];
		decimal /= 16;
	}
	while (i--)
		ft_putchar(hex[i]);
	return (len);
}
