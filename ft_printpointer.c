/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:00:23 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/09 22:34:15 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalen(size_t pointer)
{
	int	len;

	len = 0;
	while (pointer != 0)
	{
		len++;
		pointer = pointer / 16;
	}
	return (len);
}

int	ft_printptr(size_t npointer, char *base)
{
	char	hexa[25];
	int		len;
	int		i;

	i = 0;
	len = ft_hexalen(npointer);
	if (npointer == 0)
	{
		write(1, "0x0", 3);
		len += 3;
	}
	else
	{
		write(1, "0x", 2);
		len += 2;
	}
	while (npointer != 0)
	{
		hexa[i++] = base[npointer % 16];
		npointer /= 16;
	}
	while (i--)
		ft_putchar(hexa[i]);
	return (len);
}
