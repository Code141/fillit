/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:15:18 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/27 16:30:21 by gelambin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n != 0)
	{
		--n;
		((char *)dest)[n] = ((char *)src)[n];
	}
	return (dest);
}
