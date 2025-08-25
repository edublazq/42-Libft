/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:39:51 by bamberger12       #+#    #+#             */
/*   Updated: 2025/08/21 16:39:53 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	i = 0;
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		if (ptr_src[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
