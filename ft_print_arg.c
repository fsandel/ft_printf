/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:22:28 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/25 18:20:29 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_print_char(va_list arg)
{
	char	*output;

	output = ft_calloc(2,1);
	output[0] = va_arg(arg, int); 
	return (output);
}

char	*ft_print_str(va_list arg)
{
	char *output;

	output = ft_strdup((const char *)va_arg(arg, char*));
	return (output);
}

char	*ft_print_void(va_list arg)
{
	char *output;

	output = ft_strdup("void");
	return (output);
}

char	*ft_print_deci(va_list arg)
{
	char *output;

	output = ft_itoa(va_arg(arg, int));
	return (output);
}

char	*ft_print_int(va_list arg)
{
	char *output;

	output = ft_itoa(va_arg(arg, int));
	return (output);
}

char	*ft_print_unsi(va_list arg)
{
	char *output;

	output = ft_unsi_itoa(va_arg(arg, unsigned int));
	return (output);

}

char	*ft_print_hexa_low(va_list arg)
{
	char	*hexa;
	char	*output;
	int		i;
	int		temp;
	int		arg_int;

	arg_int = va_arg(arg, int);
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

char	*ft_print_hexa_up(va_list arg)
{
	char	*hexa;
	char	*output;
	int		i;
	int		temp;
	int		arg_int;

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
	output = ft_rev_string(hexa);
	free(hexa);
	return (output);
}

char	*ft_print_perc(va_list arg)
{
	char *output;

	output = ft_strdup("%");
	return (output);
}
