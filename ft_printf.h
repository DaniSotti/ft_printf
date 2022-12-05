/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:36 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/05 22:58:37 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_putstr(const char *arg);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
int		ft_putnbru(unsigned int n);
int		ft_putnbrhex(unsigned int n, char format);
int		ft_putchar(int c);
char	*ft_utoa(unsigned int n);
int     ft_printpointer(unsigned long long decimal);

#endif