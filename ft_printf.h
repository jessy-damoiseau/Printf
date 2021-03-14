/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:27:57 by user42            #+#    #+#             */
/*   Updated: 2021/02/04 16:04:29 by jdamoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			print;
	int			space;
	int			flag;
	int			len;
	int			modif_number1;
	int			modif_number2;
	char		*str;
	int			count_char;
}				t_flags;

int				to_find(char c);
int				check_star(char *str);
int				check_flags(char *str);
int				check_point(char *str, char c, int i);

void			flags_init(t_flags *flags);
int				print(va_list args, char *str);
int				ft_printf(const char *input, ...);

char			*ft_strndup(char *str, size_t len);
void			ft_putchar(char c, t_flags *flags);
void			print_space(long int i, t_flags *flags);
char			*ft_strjoin(char *s1, char *s2);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_taillenb(long int n);
size_t			ft_strlen(const char *str);

char			*del_before(char *str);
int				name_flag(char char_flags);
void			parse_flag(char *str, t_flags *flags, va_list args);

void			parse_c(char *str, t_flags *flags, va_list args);
void			parse_s(char *str, t_flags *flags, va_list args);
void			parse_p(char *str, t_flags *flags, va_list args);
void			parse_u(char *str, t_flags *flags, va_list args);
void			parse_x(char *str, t_flags *flags, va_list args);
void			parse_di(char *str, t_flags *flags, va_list args);

int				get_first_number(char *str, t_flags *flags);
int				get_second_number(char *str, t_flags *flags);
int				*global_parsing(char *str, int *parse);
int				*global_parsing_next(char *str, int *parse);
int				*param_flags(t_flags *flags,
				int *parse, va_list args, int *param_flag);

char			*ft_itoa_base(long long int value, int base);

char			*convert(long int i, int len);

#endif
