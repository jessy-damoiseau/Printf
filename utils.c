/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:52:50 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 21:55:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_flags *flags)
{
	write(1, &c, 1);
	flags->count_char++;
}

void	print_space(long int i, t_flags *flags)
{
	while (i > 0)
	{
		ft_putchar(' ', flags);
		i--;
	}
}

char	*ft_strndup(char *str, size_t len)
{
	size_t	i;
	char	*dest;

	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (0);
	i = 0;
	while (str[i] && i <= len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	j;
	size_t	i;
	char	*c;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(c = malloc(sizeof(*c) * (i + j + 1))))
		return (0);
	i = 0;
	j = -1;
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[++j])
		c[i++] = s2[j];
	c[i] = 0;
	free(s2);
	return (c);
}
