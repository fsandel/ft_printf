/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:40:21 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/25 18:18:43 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);

char	*ft_argument(va_list arg, char a);

char	*ft_print_char(va_list arg);
char	*ft_print_str(va_list arg);
char	*ft_print_void(va_list arg);
char	*ft_print_deci(va_list arg);
char	*ft_print_int(va_list arg);
char	*ft_print_unsi(va_list arg);
char	*ft_print_hexa_low(va_list arg);
char	*ft_print_hexa_up(va_list arg);
char	*ft_print_perc(va_list arg);

char	*ft_rev_string(char *str);
char	*ft_unsi_itoa(unsigned int i);
int		ft_unsi_num_len(unsigned int i);




#endif
