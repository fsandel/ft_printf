/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:38:43 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/24 18:33:43 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_char(va_list arg)
{
	ft_putchar(va_arg(arg, int));
}

void	ft_print_str(va_list arg)
{
	ft_putstr(va_arg(arg, char*));
}

void	ft_print_void(va_list arg)
{
	ft_putstr("void");
}

void	ft_print_deci(va_list arg)
{
	ft_putstr("deci");
}

void	ft_print_int(va_list arg)
{
	ft_putnbr(va_arg(arg, int));
}

void	ft_print_unsi(va_list arg)
{
	ft_putstr("unsi");
}

void	ft_print_hexa_low(va_list arg)
{
	char	*hexa;
	int		i;
	int		temp;
	int		arg_int;
	int		n;

	arg_int = va_arg(arg, int);
	hexa = ft_calloc(30, 1);
	i = 0;
	temp = 0;
	while (arg_int != 0)
	{
		temp = arg_int % 16;
		if (temp < 10)
			hexa[i++] = temp + '0';
		else
			hexa[i++] = temp + 'a' - 10;
		arg_int = arg_int / 16;
	}
	n = ft_strlen(hexa);
	free(hexa);
	while (n--)
		ft_putchar(hexa[n]);
}

void	ft_print_hexa_up(va_list arg)
{
	char	*hexa;
	int		i;
	int		temp;
	int		arg_int;
	int		n;

	arg_int = va_arg(arg, int);
	hexa = ft_calloc(30, 1);
	i = 0;
	temp = 0;
	while (arg_int != 0)
	{
		temp = arg_int % 16;
		if (temp < 10)
			hexa[i++] = temp + '0';
		else
			hexa[i++] = temp + 'A' - 10;
		arg_int = arg_int / 16;
	}
	n = ft_strlen(hexa);
	free(hexa);
	while (n--)
		ft_putchar(hexa[n]);
}

void	ft_print_perc(va_list arg)
{
	ft_putchar('%');
}

void	ft_argument(va_list arg, char a)
{
	if (a == 'c')
		ft_print_char(arg);
	else if (a == 's')
		ft_print_str(arg);
	else if (a == 'p')
		ft_print_void(arg);
	else if (a == 'd')
		ft_print_deci(arg);
	else if (a == 'i')
		ft_print_int(arg);
	else if (a == 'u')
		ft_print_unsi(arg);
	else if (a == 'x')
		ft_print_hexa_low(arg);
	else if (a == 'X')
		ft_print_hexa_up(arg);
	else if (a == '%')
		ft_print_perc(arg);
}

int	ft_printf(const char *print_string, ...)
{
	int		i;
	va_list	arg;

	va_start(arg, print_string);
	
	i = 0;
	while (print_string[i])
	{
		if (print_string[i] == '%' && print_string[i + 1])
		{
			i++;
			ft_argument(arg, print_string[i]);
		}
		else
			ft_putchar(print_string[i]);
		i++;
	}
	va_end(arg);
	return (0);
}
