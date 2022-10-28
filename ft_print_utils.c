/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:35:37 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 10:50:13 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_rev_string(char *str)
{
	char	*output;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	output = ft_calloc(len + 1, 1);
	while (str[i])
	{
		output[i] = str[len - i - 1];
		i++;
	}
	return (output);
}

char	*ft_unsi_itoa(unsigned int i)
{
	char	*output;
	int		len;

	len = ft_unsi_num_len(i);
	output = ft_calloc(len + 1, 1);
	while (i > 0)
	{
		output[--len] = ((i % 10) + '0');
		i /= 10;
	}
	return (output);
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

char	*ft_int_to_hex(long long arg_int)
{
	char	*hexa;
	char	*output;
	long long	i;
	long long temp;

	if (arg_int == 0)
		return(ft_strdup("0"));
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
	output = ft_rev_string(hexa);
	free(hexa);
	return (output);
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
