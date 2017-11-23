/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:18:35 by sboilard          #+#    #+#             */
/*   Updated: 2017/11/23 17:36:54 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_sqrti(unsigned int nbr)
{
	unsigned int	li;
	unsigned int	hi;
	unsigned int	i;

	li = 0;
	hi = 1 << 16;
	while (li < hi)
	{
		i = (li + hi) / 2;
		if (i * i < nbr)
			li = i + 1;
		else
			hi = i;
	}
	return (li);
}
