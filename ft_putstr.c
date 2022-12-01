/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:02:51 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/01 23:19:34 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		write(1, &arg[i], 1);
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
int main ()
{
    char str[] = "Dani";
    ft_putstr(str);
    return (0);
} */