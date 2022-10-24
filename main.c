/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:31:39 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/24 19:00:08 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	char *str = "test";
	i = 300;
	//ft_printf("s: %s %i\n", "string", 3);
	printf("hexalow: %c!!!!!\n", str);
	ft_printf("hexalow: %c!!!!!\n", str);

}
