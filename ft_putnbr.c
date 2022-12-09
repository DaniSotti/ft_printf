/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:05:12 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/09 23:36:34 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	ft_nlen(size_t n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}*/

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}
/*char	num[25];
int		len;
int		i;

i = 0;
len = ft_nlen(n);
if (n == 0)
	return (ft_putchar('0'));
if (n < 0)
{
	write(1, "-", 1);
	n *= -1;
	len++;
}
while (n != 0)
{
	num[i++] = base[n % 10];
	n /= 10;
}
while (i--)
	ft_putchar(num[i]);
return (len);*/

