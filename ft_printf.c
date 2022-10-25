/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:43 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/25 17:53:37 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_argument(va_list arg, char a)
{
	char *output;

	if (a == 'c')
		output = ft_print_char(arg);
	else if (a == 's')
		output = ft_print_str(arg);
	else if (a == 'p')
		output = ft_print_void(arg);
	else if (a == 'd')
		output = ft_print_deci(arg);
	else if (a == 'i')
		output = ft_print_int(arg);
	else if (a == 'u')
		output = ft_print_unsi(arg);
	else if (a == 'x')
		output = ft_print_hexa_low(arg);
	else if (a == 'X')
		output = ft_print_hexa_up(arg);
	else if (a == '%')
		output = ft_print_perc(arg);
	return (output);
}

int	ft_printf(const char *print_string, ...)
{
	char	*current;
	int		i;
	int		total;
	va_list	arg;

	va_start(arg, print_string);
	total = 0;
	i = 0;
	while (print_string[i])
	{
		if (print_string[i] == '%' && print_string[i + 1])
		{
			i++;
			current = ft_argument(arg, print_string[i]);
			ft_putstr_fd(current, 2);
			total += ft_strlen(current);
		}
		else
		{
			ft_putchar_fd(print_string[i], 2);
			total++;
		}
		i++;
	}
	va_end(arg);
	return (total);
}
