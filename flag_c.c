/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:59:13 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 22:00:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_c(int *param_flag, t_flags *flags)
{
	while (flags->len > 0)
	{
		ft_putchar('0', flags);
		flags->len--;
	}
	ft_putchar(param_flag[2], flags);
}

void	parsing_calcul_c(int *param_flag, int *parse, t_flags *flags)
{
	if (param_flag[0] < 0)
	{
		if (!parse[0])
			parse[0] = 1;
		param_flag[0] *= -1;
	}
	if (parse[1] && !parse[0])
	{
		flags->len = param_flag[0] - 1;
		flags->space = 0;
	}
	else
	{
		flags->len = 0;
		if (param_flag[0])
			flags->space = param_flag[0] - 1;
		else
			flags->space = param_flag[0];
		if (parse[0])
			flags->space *= -1;
	}
	flags->print = 1;
}

void	parse_c(char *str, t_flags *flags, va_list args)
{
	int parse[5];
	int param_flag[3];

	param_flag[1] = 0;
	param_flag[2] = 0;
	*parse = *global_parsing(str, parse);
	*param_flag = *param_flags(flags, parse, args, param_flag);
	if (flags->flag == 0)
		param_flag[2] = va_arg(args, int);
	else
		param_flag[2] = '%';
	parsing_calcul_c(param_flag, parse, flags);
	if (flags->space >= 0)
	{
		print_space(flags->space, flags);
		print_flag_c(param_flag, flags);
	}
	else
	{
		print_flag_c(param_flag, flags);
		print_space(flags->space * -1, flags);
	}
}
