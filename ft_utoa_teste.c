/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:42:18 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/09 22:15:54 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	number_len(unsigned int n)
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
}

char	*ft_utoa(unsigned int n)
{
	char			*n_char;
	unsigned int	len;
	unsigned int	num;

	len = number_len(n);
	n_char = (char *)malloc(sizeof(char) * (len + 1));
	if (!n_char)
		return (0);
	if (n < 0)
	{
		n_char[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		n_char[0] = '0';
	n_char[len] = '\0';
	while (num != 0)
	{
		n_char[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (n_char);
}
