/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:18:22 by user42            #+#    #+#             */
/*   Updated: 2021/02/04 16:27:04 by jdamoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_second_number(char *str, t_flags *flags)
{
	int result;
	int i;

	result = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		flags->modif_number2 = 1;
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	get_first_number(char *str, t_flags *flags)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (!ft_isdigit(str[i]) && !ft_isalpha(str[i])
			&& str[i] != '%' && str[i] != '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		flags->modif_number1 = 1;
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}

int	*param_flags(t_flags *flags, int *parse, va_list args, int *param_flag)
{
	if (parse[2])
	{
		param_flag[0] = get_first_number(flags->str, flags);
		param_flag[1] = get_second_number(flags->str, flags);
	}
	else
		param_flag[0] = get_first_number(flags->str, flags);
	if (parse[3])
	{
		flags->modif_number1 = 1;
		param_flag[0] = va_arg(args, int);
	}
	if (parse[4])
	{
		flags->modif_number2 = 1;
		param_flag[1] = va_arg(args, int);
	}
	return (param_flag);
}

int	*global_parsing_next(char *str, int *parse)
{
	int i;

	i = 0;
	while (str[i] != '%' && !ft_isalpha(str[i]))
	{
		if (str[i] == '*')
		{
			if (str[i - 1] == '.' && (ft_isalpha(str[i + 1])
						|| str[i + 1] == '%'))
				parse[4] = 1;
			else if (str[i + 1] == '.' || ft_isalpha(str[i + 1])
					|| str[i + 1] == '%')
				parse[3] = 1;
		}
		i++;
	}
	return (parse);
}

int	*global_parsing(char *str, int *parse)
{
	int i;

	i = 0;
	while (i <= 4)
		parse[i++] = 0;
	i = 0;
	while (str[i] != '%' && !ft_isalpha(str[i]))
	{
		if (str[i] == '-' || (str[i] == '0'
					&& (i == 0 || str[i - 1] == '-')) || str[i] == '.')
		{
			if (str[i] == '-')
				parse[0] = 1;
			if (str[i] == '0')
				parse[1] = 1;
			if (str[i] == '.')
				parse[2] = 1;
		}
		i++;
	}
	return (global_parsing_next(str, parse));
}
