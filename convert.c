/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:58:26 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 21:58:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(long int i, int len)
{
	int		j;
	char	*dest;

	j = 0;
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (0);
	dest[len] = '\0';
	len--;
	if (i < 0)
	{
		dest[j++] = '-';
		i *= -1;
	}
	while (len >= j)
	{
		dest[len--] = i % 10 + '0';
		i /= 10;
	}
	return (dest);
}
