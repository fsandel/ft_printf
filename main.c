/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:31:39 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 10:57:21 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char const *s = "myadress";
	int			meine;
	int			trash;

	meine = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("\n");
	trash = printf(" %p %p ", LONG_MIN, LONG_MAX);

	printf("\n\nmeine: %d\ntrash: %d\n", meine, trash);

	printf("\n\n%s", ft_int_to_hex(LONG_MIN));
	return (0);
}
