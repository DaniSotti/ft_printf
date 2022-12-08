/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:00:23 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/08 19:54:26 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalen(long int pointer)
{
	int	len;

	len = 0;
	//if (pointer == 0)
	//	return (1);
	while (pointer > 0)
	{
		len++;
		pointer = pointer /16;
	}
	return (len);
}

int	ft_printptr(long int pointer)
{
	char	hexa[100];
	int		len;
	int		i;
	int		remain;

	i = 0;
	len = 0;
	len = ft_hexalen(pointer) + 2;
	if (!pointer)
		ft_putstr("nil");
	else
		write(1, "0x", 2);
	while (pointer != 0)
	{
		//len += ft_hexalen(pointer);
		remain = pointer % 16;
		if (remain < 10)
			remain = 48 + remain;
		else
			remain = remain + 87;
		hexa[i] = remain;
		pointer = pointer / 16;
		i++;
	}
	while (i--)
		ft_putchar(hexa[i]);
	return (len);
}
