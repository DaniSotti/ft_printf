/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:07:36 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/08 19:49:01 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Na função principal vericar qual o tipo de variavel recebi e chamar cada uma das funções;
//utilizar os parametros variadic que dá a capacidade de imprimir varias variaveis e mais do que 1 tipo;
//Criar varias funções para imprimir números, string, numeros hexadecimais etc etc;
//Encontrar uma forma de ler %d, %i por exemplo
//1. Descobrir quantos parametros a função tem;
#include "ft_printf.h"

static int	format(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
    if (c == 'p')
        return (ft_printptr(va_arg(args, long int)));
    if (c == 'd')
        return (ft_putnbr(va_arg(args, int)));
    else if (c == 'i')
       return (ft_putnbr(va_arg(args, int)));
    if (c == 'u')
        return (ft_putnbru(va_arg(args, unsigned int)));
    if (c == 'x' || c == 'X')
       return (ft_putnbrhex(va_arg(args, unsigned int), c));
    else if (c == '%')
        return (ft_putchar(c));
    else 
        return (0);
}
	
int	ft_printf(const char *str, ...)
{
	va_list args;
	int		len;
	int		i;	
	
	i = 0;
    len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += format(str[i], args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end (args);
	return (len);
    
    /*
    %s Prints a string (as defined by the common C convention).
    %p The void * pointer argument has to be printed in hexadecimal format.
    %d Prints a decimal (base 10) number.
    %i Prints an integer in base 10.
    %u Prints an unsigned decimal (base 10) number.
    %x Prints a number in hexadecimal (base 16) lowercase format.
    %X Prints a number in hexadecimal (base 16) uppercase format.
    %% Prints a percent sign.*/

}

//ft_printf
//validacao do tipo da variavel 
//calcular o tamanho da string 
