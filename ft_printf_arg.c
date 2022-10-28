/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:22:28 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 14:49:03 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list arg)
{
	ft_putchar_fd(va_arg(arg, int), 1);
	return (1);
}

int	ft_print_str(va_list arg)
{
	char	*output;
	int		len;

	output = va_arg(arg, char *);
	if (output == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(output);
	ft_putstr_fd(output, 1);
	return (len);
}

int	ft_print_void(va_list arg)
{
	unsigned long	arg_int;
	int				len;
	char			*hexa;

	arg_int = va_arg(arg, unsigned long);
	if (arg_int == 0)
		return (write(1, "0x0", 3));
	hexa = ft_int_to_hex(arg_int);
	ft_putstr_fd("0x", 1);
	len = write(1, hexa, ft_strlen(hexa));
	free(hexa);
	return (len + 2);
}

int	ft_print_deci(va_list arg)
{
	int		nb;
	int		len;

	nb = va_arg(arg, int);
	len = ft_num_len(nb);
	ft_putnbr_fd(nb, 1);
	return (len);
}

int	ft_print_int(va_list arg)
{
	int		nb;
	int		len;

	nb = va_arg(arg, int);
	len = ft_num_len(nb);
	ft_putnbr_fd(nb, 1);
	return (len);
}
