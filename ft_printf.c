/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:20:39 by jessy             #+#    #+#             */
/*   Updated: 2021/02/02 22:18:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_init(t_flags *flags)
{
	flags->print = 1;
	flags->space = 0;
	flags->modif_number1 = 0;
	flags->modif_number2 = 0;
	flags->flag = 0;
	flags->len = 0;
}

int		print(va_list args, char *str)
{
	int			i;
	int			len_flags;
	t_flags		*flags;

	i = 0;
	if (!(flags = malloc(sizeof(t_flags))))
		return (0);
	flags->count_char = 0;
	while (str[i])
	{
		flags_init(flags);
		if ((len_flags = check_flags(&str[i])))
		{
			parse_flag(ft_strndup(&str[i], len_flags), flags, args);
			i += len_flags + 1;
		}
		else
		{
			ft_putchar(str[i], flags);
			i++;
		}
	}
	i = flags->count_char;
	free(flags);
	return (i);
}

int		ft_printf(const char *input, ...)
{
	va_list		args;
	char		*str;
	int			char_count;

	if (!input)
		return (0);
	va_start(args, input);
	str = ft_strndup((char *)input, ft_strlen(input));
	char_count = print(args, str);
	free(str);
	va_end(args);
	return (char_count);
}
