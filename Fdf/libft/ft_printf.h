/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller- <ekeller-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:20:22 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/05 17:47:12 by ekeller-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf_putnbr(int n);
int	ft_printf_putnbr_uns(unsigned int n);
int	ft_printf_putnbr_hx(unsigned int hx, char *base);
int	ft_printf_putstr(char *str);
int	ft_printf_putptr(void *ptr, char *base);
int	ft_printf(const char *str, ...);
int	ft_printf_format(char specifier, va_list ap);
int	ft_printf_putchar(char c);

#endif