/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:43 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 14:49:14 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (print_string[i] == '%' && print_string[i + 1] == 0)
			return (total);
		if (print_string[i] == '%' && print_string[i + 1])
		{
			i++;
			total += ft_argument(arg, print_string[i]);
		}
		else
			total += write(1, &print_string[i], 1);
		i++;
	}
	va_end(arg);
	return (total);
}

int	ft_argument(va_list arg, char a)
{
	int	len;

	if (a == 'c')
		len = ft_print_char(arg);
	else if (a == 's')
		len = ft_print_str(arg);
	else if (a == 'p')
		len = ft_print_void(arg);
	else if (a == 'd')
		len = ft_print_deci(arg);
	else if (a == 'i')
		len = ft_print_int(arg);
	else if (a == 'u')
		len = ft_print_unsi(arg);
	else if (a == 'x')
		len = ft_print_hexa_low(arg);
	else if (a == 'X')
		len = ft_print_hexa_up(arg);
	else if (a == '%')
		len = ft_print_perc();
	else
		len = write(1, &a, 1);
	return (len);
}
