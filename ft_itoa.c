/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:24:05 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/03 14:47:21 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//Encontrar o tamanho do número (nova função)

static int	number_len(int n)
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
//alocar a memoria de acordo com o tamanho
//lidar com os numeros negativos
//transformar o numero inteiro em string

char	*ft_itoa(int n)
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