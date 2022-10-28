/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:40:21 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/28 15:45:44 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_argument(va_list arg, char a);

int		ft_print_char(va_list arg);
int		ft_print_str(va_list arg);
int		ft_print_void(va_list arg);
int		ft_print_deci(va_list arg);
int		ft_print_int(va_list arg);

int		ft_print_unsi(va_list arg);
int		ft_print_hexa_low(va_list arg);
int		ft_print_hexa_up(va_list arg);
int		ft_print_perc(void);

char	*ft_rev_string(char *str);
int		ft_num_len(int n);
char	*ft_int_to_hex(unsigned long arg_int);
int		ft_unsi_num_len(unsigned int i);
void	ft_putunsi_fd(unsigned int nb, int fd);

#endif
