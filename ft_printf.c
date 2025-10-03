/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:32:05 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/25 23:32:06 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list vargs, char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(vargs, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(vargs, char *), 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(vargs, int), 1);
	else if (c == 'u')
		ft_print_unsigned(va_arg(vargs, unsigned int));
	else if (c == 'x')
		ft_print_to_base(va_arg(vargs, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		ft_print_to_base(va_arg(vargs, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'p')
		ft_print_ptr(va_arg(vargs, void *));
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list		vargs;
	int			i;
	int			valid;

	va_start(vargs, str);
	i = 0;
	valid = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			valid = ft_format(vargs, str[i + 1]);
			if (!valid)
				return (-1);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(vargs);
	return (i);
}
