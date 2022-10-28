/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:31:39 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 14:36:37 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char const	*s = "c %c\ns %s\np %p\nd %d\ni %d\nu %u\nx %x\nX %X\n%%\n %";
	int			meine;
	int			trash;

	meine = ft_printf(s, 'a', "string", s, 69, 420, 42069, 420, 6969);
	printf("\n");
	trash = printf(s, 'a', "string", s, 69, 420, 42069, 420, 6969);
	printf("\n\nmeine: %d\ntrash: %d\n", meine, trash);
	return (0);
}
