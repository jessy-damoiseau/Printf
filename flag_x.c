/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:13:26 by user42            #+#    #+#             */
/*   Updated: 2021/02/02 22:16:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_flag_x(char *s, t_flags *flags)
{
	if (!flags->print)
		return ;
	while (flags->len > 0)
	{
		ft_putchar('0', flags);
		flags->len--;
	}
	while (*s)
		ft_putchar(*s++, flags);
}

void	parsing_calcul_x_next(int *param_flag, int *parse,
		t_flags *flags, char *str)
{
	if (str[0] == '0' && (int)ft_strlen(str) == 1 &&
	((!parse[1] && !flags->modif_number1 && parse[2] && param_flag[1] == 0)
	|| (!param_flag[1] && parse[2])))
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

void	parsing_calcul_x(int *param_flag, int *parse,
		t_flags *flags, char *str)
{
	if (param_flag[1] > (int)ft_strlen(str))
		flags->len = param_flag[1] - (int)ft_strlen(str);
	if (param_flag[0] >= 0)
		if (param_flag[0] > flags->len + (int)ft_strlen(str))
			flags->space = param_flag[0] - flags->len - (int)ft_strlen(str);
	if (param_flag[0] < 0)
		if (-param_flag[0] > flags->len + (int)ft_strlen(str))
			flags->space = param_flag[0] + (flags->len + (int)ft_strlen(str));
	if (parse[1] && param_flag[0] >= 0 && (param_flag[1] < 0
				|| (param_flag[1] == 0 && !flags->modif_number2)))
	{
		flags->len = param_flag[0] - (int)ft_strlen(str);
		flags->space = 0;
	}
	parsing_calcul_x_next(param_flag, parse, flags, str);
}

void	parse_x(char *str, t_flags *flags, va_list args)
{
	int				parse[5];
	int				param_flag[2];
	unsigned int	i;
	char			*s;

	param_flag[1] = 0;
	*parse = *global_parsing(str, parse);
	*param_flag = *param_flags(flags, parse, args, param_flag);
	i = va_arg(args, unsigned int);
	if (flags->flag == 6)
		s = ft_itoa_base(i, 1);
	else
		s = ft_itoa_base(i, 2);
	parsing_calcul_x(param_flag, parse, flags, s);
	if (flags->space < 0)
	{
		print_flag_x(s, flags);
		print_space(flags->space * -1, flags);
	}
	else
	{
		print_space(flags->space, flags);
		print_flag_x(s, flags);
	}
	free(s);
}
