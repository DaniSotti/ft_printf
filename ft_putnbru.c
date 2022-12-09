/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 23:16:12 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/09 22:17:55 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_utoa(n);
	len = ft_putstr(str);
	free(str);
	return (len);
}
