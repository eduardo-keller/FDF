/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:20:22 by ekeller-@st       #+#    #+#             */
/*   Updated: 2024/11/27 18:35:06 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr(int n);
int	ft_putnbr_uns(unsigned int n);
int	ft_putnbr_hx(unsigned int hx, char *base);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr, char *base);
int	ft_printf(const char *str, ...);
int	ft_print_format(char specifier, va_list ap);
int	ft_putchar(char c);

#endif