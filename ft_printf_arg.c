/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:22:28 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 15:01:02 by fsandel          ###   ########.fr       */
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
	char	*str;
	int		len;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}

int	ft_print_void(va_list arg)
{
	unsigned long	arg_long;
	int				len;
	char			*hex;

	ft_putstr_fd("0x", 1);
	arg_long = va_arg(arg, unsigned long);
	if (arg_long == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	hex = ft_int_to_hex(arg_long);
	len = write(1, hex, ft_strlen(hex));
	free(hex);
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
