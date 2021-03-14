/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:24:47 by user42            #+#    #+#             */
/*   Updated: 2021/02/04 16:50:30 by jdamoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*del_before(char *str)
{
	int i;
	int done;

	i = 0;
	done = 0;
	if (str[i] == '%')
		i++;
	while (!ft_isalpha(str[i]) && !done)
	{
		if ((str[i] == '-' && (str[i + 1] == '-' || (str[i + 1] == '0'
		&& (str[i + 2] == '0' || str[i + 2] == '-')))) || (str[i] == '0'
		&& (str[i + 1] == '-' || (str[i + 1] == '0' && (str[i + 2] == '0'
		|| str[i + 2] == '-')))))
			i++;
		else
			done = 1;
	}
	return (&str[i]);
}

int		name_flag(char char_flags)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "cspdiuxX%";
	while (flags[i] && flags[i] != char_flags)
		i++;
	return (i);
}

void	parse_flag(char *str, t_flags *flags, va_list args)
{
	char *s;

	s = del_before(str);
	flags->str = s;
	flags->flag = name_flag(s[ft_strlen(s) - 1]);
	if (flags->flag == 0 || flags->flag == 8)
		parse_c(s, flags, args);
	else if (flags->flag == 1)
		parse_s(s, flags, args);
	else if (flags->flag == 2)
		parse_p(s, flags, args);
	else if (flags->flag == 3 || flags->flag == 4)
		parse_di(s, flags, args);
	else if (flags->flag == 5)
		parse_u(s, flags, args);
	else
		parse_x(s, flags, args);
	free(str);
}
