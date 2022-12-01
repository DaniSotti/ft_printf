/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:07:36 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/01 23:19:25 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Na função principal vericar qual o tipo de variavel recebi e chamar cada uma das funções;
//utilizar os parametros variadic que dá a capacidade de imprimir varias variaveis e mais do que 1 tipo;
//Criar varias funções para imprimir números, string, numeros hexadecimais etc etc;
//Encontrar uma forma de ler %d, %i por exemplo
//1. Descobrir quantos parametros a função tem;
#include "ft_printf.h"

static int  ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

static int	format(char	c, va_list args)
{
    if (c == 'c')
        return (ft_putchar(va_arg(args, int))); //%c Prints a single character.
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
    return (0);
    /*if (c == 'p')
        return (ft_puthexa(va_arg(args, ??)));
    if (c == 'd')
        return (ft_putfloat(va_arg(args, int)));
    if (c == 'i')
        return (ft_putint(va_arg(args, int)));
    if (c == 'u')
        return (ft_putuncdeci(va_arg(args, unsigned int)));
    if (c == 'x' || c == 'X')
        return (ft_puthexa(va_arg(args, unsigned int)));
    if (c == '%')
        ft_putchar('%'); */
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
			len += ft_putstr(str);
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
