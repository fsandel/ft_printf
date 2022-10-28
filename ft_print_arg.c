/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:22:28 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/27 17:57:30 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
	//free(output);
	return (len);
}

int	ft_print_void(va_list arg)
{
	char		*output;
	uintptr_t	ptr_num;
	int			len;

	ptr_num = (uintptr_t)va_arg(arg, uintptr_t);
	//if (ptr_num == NULL)
	//{
	//	ft_putstr_fd("0x0", 1);
	//	return (3);
	//}
	output = ft_int_to_hex(ptr_num);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(output, 1);
	len = ft_strlen(output);
	free(output);
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
