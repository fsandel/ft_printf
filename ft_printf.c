/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:43 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/27 16:37:56 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_return(char *str);
int	ft_putchar_return(char c);

int	ft_argument(va_list arg, char a)
{
	int	output;

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

			total += ft_argument(arg, print_string[i]);
		}
		else
			total += ft_putchar_return(print_string[i]);
		i++;
	}
	va_end(arg);
	return (total);
}

int	ft_putstr_return(char *str)
{
	int	len;
	
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);

	return (len);
}

int	ft_putchar_return(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
