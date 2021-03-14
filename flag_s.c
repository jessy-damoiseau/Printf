/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:07:44 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 22:09:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_s(char *str, t_flags *flags)
{
	int i;

	i = 0;
	if (!flags->print)
		return ;
	while (str[i] && i < flags->len)
	{
		ft_putchar(str[i], flags);
		i++;
	}
}

void	parsing_calcul_s(int *param_flag,
		int *parse, t_flags *flags, char *str)
{
	if (param_flag[1] >= 0 && param_flag[1] < (int)ft_strlen(str) && parse[2])
		flags->len = param_flag[1];
	else
		flags->len = (int)ft_strlen(str);
	if (param_flag[0] >= 0)
		if (param_flag[0] > flags->len)
			flags->space = param_flag[0] - flags->len;
	if (param_flag[0] < 0)
		if (-param_flag[0] > flags->len)
			flags->space = param_flag[0] + flags->len;
	if ((param_flag[0] < 0 || parse[0]) && flags->space > 0)
		flags->space *= -1;
}

void	parse_s(char *str, t_flags *flags, va_list args)
{
	int		parse[5];
	int		param_flag[2];
	char	*s;

	param_flag[1] = 0;
	*parse = *global_parsing(str, parse);
	*param_flag = *param_flags(flags, parse, args, param_flag);
	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	parsing_calcul_s(param_flag, parse, flags, s);
	if (flags->space < 0)
	{
		print_flag_s(s, flags);
		print_space(flags->space * -1, flags);
	}
	else
	{
		print_space(flags->space, flags);
		print_flag_s(s, flags);
	}
}
