/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beomjuki <beomjuki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:48:48 by beomjuki          #+#    #+#             */
/*   Updated: 2023/03/19 20:30:56 by beomjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)destination;
	src = (unsigned char *)source;
	if (dest == src || num == 0)
		return (destination);
	if (dest < src)
		return (ft_memcpy(dest, src, num));
	else if (dest > src)
	{
		while (num--)
		{
			dest[num] = src[num];
		}
	}
	return (destination);
}
