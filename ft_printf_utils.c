/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:35:37 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 15:45:01 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_rev_string(char *str)
{
	int		len;
	int		i;
	char	temp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[len - 1 - i];
		str[len - 1 - i] = str[i];
		str[i] = temp;
		i++;
	}
	return (str);
}

char	*ft_int_to_hex(unsigned long arg_int)
{
	char			*hex;
	int				i;
	int				temp;
	unsigned long	arg_copy;
	int				size;

	arg_copy = arg_int;
	size = 3;
	while (arg_copy > 16 && size++)
		arg_copy /= 16;
	if (arg_int == 0)
		return (ft_strdup("0"));
	hex = ft_calloc(size, 1);
	i = 0;
	while (arg_int != 0)
	{
		temp = arg_int % 16;
		if (temp < 10)
			hex[i++] = temp + '0';
		else
			hex[i++] = temp + 'a' - 10;
		arg_int = arg_int / 16;
	}
	hex = ft_rev_string(hex);
	return (hex);
}

int	ft_num_len(int n)
{
	int	length;

	if (n == -2147483648)
		return (11);
	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
	{
		length++;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		length++;
	}
	return (length);
}

int	ft_unsi_num_len(unsigned int i)
{
	int	counter;

	if (i == 0)
		return (1);
	counter = 0;
	while (i > 0)
	{
		i /= 10;
		counter++;
	}
	return (counter);
}

void	ft_putunsi_fd(unsigned int nb, int fd)
{
	if (nb >= 10)
	{
		ft_putunsi_fd(nb / 10, fd);
		ft_putunsi_fd(nb % 10, fd);
	}
	if (nb < 10)
		ft_putchar_fd(nb + '0', fd);
}
