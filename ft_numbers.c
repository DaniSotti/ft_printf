/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:13:00 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/11 18:47:57 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ft_itoa para transformar um numero inteiro em string
static int	number_len_(unsigned int n)
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

char	*ft_itoa(int n)
{
	char			*n_char;
	unsigned int	len;
	unsigned int	num;

	len = number_len_(num);
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

//Transformar o numero em unsigned
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

char	ft_utoa(unsigned int n)
{
    if (n > 9)
        ft_utoa(n / 10);
    ft_putchar(n % 10 + 48);
	/*char			*n_char;
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
	return (n_char);*/
}

//print pointer

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
		write(1, "(nil)", 5);
		len += 5;
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

//print the hexadecimal
static int	ft_hexlen_(unsigned int decimal)
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
	len = ft_hexlen_(decimal);
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
