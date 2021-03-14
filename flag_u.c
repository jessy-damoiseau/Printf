/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:09:22 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 22:36:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_u(char *str, t_flags *flags)
{
	int i;

	i = 0;
	if (!flags->print)
		return ;
	while (flags->len > 0)
	{
		ft_putchar('0', flags);
		flags->len--;
	}
	while (str[i])
		ft_putchar(str[i++], flags);
	free(str);
}

void	parsing_calcul_u_next(int *param_flag,
		int *parse, t_flags *flags, unsigned int i)
{
	if (!i && !param_flag[1] && flags->len <= 0 && parse[2])
	{
		if (param_flag[0] && flags->space >= 0)
			flags->space++;
		if (param_flag[0] && flags->space < 0)
			flags->space--;
		flags->print = 0;
	}
	if ((param_flag[0] < 0 || parse[0]) && flags->space > 0)
		flags->space *= -1;
}

void	parsing_calcul_u(int *param_flag,
		int *parse, t_flags *flags, unsigned int i)
{
	if (param_flag[1] > ft_taillenb(i))
		flags->len = param_flag[1] - ft_taillenb(i);
	if (param_flag[0] >= 0)
		if (param_flag[0] > flags->len + ft_taillenb(i))
			flags->space = param_flag[0] - (flags->len + ft_taillenb(i));
	if (param_flag[0] < 0)
		if (-param_flag[0] > flags->len + ft_taillenb(i))
			flags->space = param_flag[0] + flags->len + ft_taillenb(i);
	if (parse[1] && param_flag[0] >= 0 && (param_flag[1] < 0
				|| (param_flag[1] == 0 && !flags->modif_number2)))
	{
		flags->len = param_flag[0] - ft_taillenb(i);
		flags->space = 0;
	}
	parsing_calcul_u_next(param_flag, parse, flags, i);
}

void	parse_u(char *str, t_flags *flags, va_list args)
{
	int				parse[5];
	int				param_flag[2];
	unsigned int	i;

	param_flag[1] = 0;
	*parse = *global_parsing(str, parse);
	*param_flag = *param_flags(flags, parse, args, param_flag);
	i = va_arg(args, unsigned int);
	parsing_calcul_u(param_flag, parse, flags, i);
	if (flags->space < 0)
	{
		print_flag_u(convert(i, ft_taillenb(i)), flags);
		print_space(flags->space * -1, flags);
	}
	else
	{
		print_space(flags->space, flags);
		print_flag_u(convert(i, ft_taillenb(i)), flags);
	}
}
