/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:35:37 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 14:49:09 by fsandel          ###   ########.fr       */
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
	char	*hexa;
	int		i;
	int		temp;

	if (arg_int == 0)
		return (ft_strdup("0"));
	hexa = ft_calloc(30, 1);
	i = 0;
	while (arg_int != 0)
	{
		temp = arg_int % 16;
		if (temp < 10)
			hexa[i++] = temp + '0';
		else
			hexa[i++] = temp + 'a' - 10;
		arg_int = arg_int / 16;
	}
	hexa = ft_rev_string(hexa);
	return (hexa);
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
