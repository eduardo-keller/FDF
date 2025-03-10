/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:54:47 by ekeller-          #+#    #+#             */
/*   Updated: 2025/03/10 15:22:10 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int	    ft_atoi(char *ptr);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_putnbr(int n);
int		ft_putnbr_uns(unsigned int n);
int		ft_putnbr_hx(unsigned int hx, char *base);
int		ft_putstr(char *str);
int		ft_putptr(void *ptr, char *base);
int		ft_printf(const char *str, ...);
int		ft_print_format(char specifier, va_list ap);
int		ft_putchar(char c);

#endif