/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:22:28 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 15:03:33 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsi(va_list arg)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(arg, unsigned int);
	len = ft_unsi_num_len(nb);
	ft_putunsi_fd(nb, 1);
	return (len);
}

int	ft_print_hexa_low(va_list arg)
{
	char			*hex;
	unsigned int	arg_int;
	int				len;

	arg_int = va_arg(arg, unsigned int);
	hex = ft_int_to_hex(arg_int);
	len = ft_strlen(hex);
	ft_putstr_fd(hex, 1);
	free(hex);
	return (len);
}

int	ft_print_hexa_up(va_list arg)
{
	char			*hex;
	unsigned int	arg_int;
	int				i;
	int				len;

	arg_int = va_arg(arg, unsigned int);
	hex = ft_int_to_hex(arg_int);
	i = 0;
	while (hex[i])
	{
		hex[i] = ft_toupper(hex[i]);
		i++;
	}
	len = ft_strlen(hex);
	ft_putstr_fd(hex, 1);
	free(hex);
	return (len);
}

int	ft_print_perc(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
