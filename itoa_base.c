/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:21:00 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 22:49:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_abs(long long int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

static char				*set_tab(int base)
{
	char *tab;

	if (base == 1)
		tab = "0123456789abcdef";
	else
		tab = "0123456789ABCDEF";
	return (tab);
}

char					*ft_itoa_base(long long int value, int base)
{
	char				*str;
	long long int		size;
	char				*tab;
	long long int		tmp;

	size = 0;
	tab = set_tab(base);
	tmp = value;
	while (tmp /= 16)
		size++;
	size = size + 1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[ft_abs(value % 16)];
		size--;
		value /= 16;
	}
	return (str);
}
