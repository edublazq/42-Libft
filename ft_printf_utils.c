/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:45:18 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/27 14:45:18 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_unsigned(unsigned int nb)
{
	if (nb < 10)
		ft_putchar_fd(nb + '0', 1);
	else
	{
		ft_print_unsigned(nb / 10);
		ft_print_unsigned(nb % 10);
	}
}

void	ft_print_to_base(unsigned int nb, char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (nb < len)
	{
		ft_putchar_fd(base[nb], 1);
	}
	else
	{
		ft_print_to_base(nb / len, base);
		ft_print_to_base(nb % len, base);
	}
}

void	ft_print_ptr_base(uintptr_t nb, char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (nb < len)
	{
		ft_putchar_fd(base[nb], 1);
	}
	else
	{
		ft_print_ptr_base(nb / len, base);
		ft_print_ptr_base(nb % len, base);
	}
}

void	ft_print_ptr(void *ptr)
{
	uintptr_t	address;

	if (ptr == NULL)
	{
		ft_printf("0x0");
		return ;
	}
	address = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	if (!address)
	{
		ft_putchar_fd('0', 1);
	}
	ft_print_ptr_base(address, "0123456789abcdef");
}
