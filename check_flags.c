/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 01:48:55 by jessy             #+#    #+#             */
/*   Updated: 2021/02/04 16:27:09 by jdamoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	to_find(char c)
{
	int		i;
	char	*find;

	find = "cspdiuxX%";
	i = 0;
	while (find[i])
	{
		if (find[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_point(char *str, char c, int i)
{
	if (c != '.')
		return (0);
	while (i > 1)
	{
		if (str[i - 1] == '.')
			return (0);
		i--;
	}
	return (1);
}

int	check_star(char *str)
{
	int i;

	i = 0;
	if (str[i] != '*')
		return (0);
	if (str[i] == '*' && (str[i + 1] == '.' || ft_isalpha(str[i + 1])))
		return (1);
	return (0);
}

int	check_flags(char *str)
{
	int i;

	i = 0;
	if (str[i] != '%')
		return (0);
	i++;
	while (str[i] == '-')
		i++;
	while (str[i] && !ft_isalpha(str[i]) && (ft_isdigit(str[i])
		|| check_point(str, str[i], i) || str[i] == '*' || str[i] == '-'))
		i++;
	if (!str[i] || !to_find(str[i]))
	{
		return (0);
	}
	return (i);
}
