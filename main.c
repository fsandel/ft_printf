/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:31:39 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/25 18:34:38 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char			*str = "test";
	char			c = 'c';
	unsigned int	i;
	i = -5;
	char	*main_string = "%p";
	printf("     og return: %d\n", 	printf(main_string, c));
	printf("     my return: %d\n", 	ft_printf(main_string, i));



}
