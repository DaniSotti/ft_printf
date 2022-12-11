/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-sott <dde-sott@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:23:36 by dde-sott          #+#    #+#             */
/*   Updated: 2022/12/11 18:44:06 by dde-sott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE_HEX_S = "0123456789abcdef";
# define BASE_HEX_B = "0123456789ABCDEF";

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_putstr(const char *arg);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
int		ft_putnbru(unsigned int n);
int		ft_putnbrhex(unsigned int n, char *base);
int		ft_putchar(int c);
char	ft_utoa(unsigned int n);
int		ft_printptr(size_t npointer, char *base);

#endif