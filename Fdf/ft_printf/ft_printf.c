/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:43:52 by ekeller-@st       #+#    #+#             */
/*   Updated: 2024/11/28 11:25:49 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == '\0')
				break ;
			count += ft_print_format(*str, ap);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}

int	ft_print_format(char specifier, va_list ap)
{
	int	count;	

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(ap, void *), "0123456789abcdef");
	else if (specifier == 'i' || specifier == 'd')
		count += ft_putnbr(va_arg(ap, int));
	else if (specifier == 'u')
		count += ft_putnbr_uns(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		count += ft_putnbr_hx(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (specifier == 'X')
		count += ft_putnbr_hx(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
