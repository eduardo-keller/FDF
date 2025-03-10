/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:02:38 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/10 12:05:55 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int			count;
	long int	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		count += write(1, "-", 1);
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10);
	count += ft_putchar(nb % 10 + '0');
	return (count);
}

int	ft_putnbr_uns(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_hx(unsigned int hx, char *base)
{
	int	count;

	count = 0;
	if (hx >= 16)
		count += ft_putnbr_hx(hx / 16, base);
	count += ft_putchar(base[hx % 16]);
	return (count);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putptr(void *ptr, char *base)
{
	int				count;
	unsigned long	address;

	address = (unsigned long)ptr;
	count = 0;
	if (ptr == NULL)
		return (write (1, "(nil)", 5));
	if (address < 16)
	{
		count += ft_putstr("0x");
		count += ft_putchar(base[address % 16]);
	}
	if (address >= 16)
	{
		count += ft_putptr((void *)(address / 16), base);
		count += ft_putchar(base[address % 16]);
	}
	return (count);
}
