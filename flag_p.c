/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:06:22 by user42            #+#    #+#             */
/*   Updated: 2021/02/04 14:46:40 by jdamoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_p(char *str, t_flags *flags)
{
	int i;

	i = 0;
	if (flags->len > 0)
	{
		while (i < 2)
			ft_putchar(str[i++], flags);
		while (flags->len)
		{
			ft_putchar('0', flags);
			flags->len--;
		}
	}
	while (str[i])
	{
		ft_putchar(str[i], flags);
		i++;
	}
}

void	parsing_calcul_p(int *param_flag, int *parse,
		t_flags *flags, int len)
{
	if (param_flag[0] < 0)
	{
		param_flag[0] *= -1;
		parse[0] = 1;
	}
	flags->print = 1;
	if (param_flag[1] > len)
	{
		flags->len = param_flag[1] - len + 2;
		if (param_flag[1] < param_flag[0])
			flags->space = param_flag[0] - param_flag[1];
		else
			flags->space = 0;
	}
	else
	{
		flags->len = 0;
		if (len < param_flag[0])
			flags->space = param_flag[0] - len;
		else
			flags->space = 0;
	}
	if (parse[0])
		flags->space *= -1;
}

void	parse_p(char *str, t_flags *flags, va_list args)
{
	int				parse[5];
	int				param_flag[2];
	long long int	i;
	char			*s;

	param_flag[1] = 0;
	*parse = *global_parsing(str, parse);
	*param_flag = *param_flags(flags, parse, args, param_flag);
	i = va_arg(args, long long int);
	s = ft_itoa_base(i, 1);
	s = ft_strjoin("0x", s);
	parsing_calcul_p(param_flag, parse, flags, ft_strlen(s));
	if (flags->space < 0)
	{
		print_flag_p(s, flags);
		print_space(flags->space * -1, flags);
	}
	else
	{
		print_space(flags->space, flags);
		print_flag_p(s, flags);
	}
	free(s);
}
