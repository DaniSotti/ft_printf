/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:46:33 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/05 22:30:04 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned int decimal)
{
	int	len;

	len = 0;
	while (decimal != 0)
	{
		len++;
		decimal = decimal /16;
	}
	return (len);
}
int	ft_putnbrhex(unsigned int decimal, char format)
{
	char hexa[23];
	int	len;
    int i = 0;
    int remain;

	len = ft_hexalen(decimal);
	if (decimal == 0)
		return (ft_putchar('0'));
    while (decimal != 0)
    {
        remain = decimal % 16;
        if (remain < 10)
            remain = 48 + remain;
        else
            if (format == 'x')
                remain = remain + 87;
            else
                if (format == 'X')
                	remain = remain + 55;
            hexa[i] = remain;
            decimal = decimal / 16;
            i++;
    }
    while (i--)
		ft_putchar(hexa[i]);
	return (len);
}

/*int main()
{
	unsigned int i = 19827487;
	char format = 'X';

	ft_putnbrhex(i, format);
	return (0);
}*/
