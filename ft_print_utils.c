/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:35:37 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/25 18:24:50 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"



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
	int counter;

	if (i == 0)
		return (0);
	counter = 0;
	while(i > 0)
	{
		i /= 10;
		counter++;
	}
	return (counter);
}
