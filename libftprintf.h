/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:40:21 by fsandel           #+#    #+#             */
/*   Updated: 2022/10/24 18:26:01 by fsandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_bzero(char *str, size_t n);
size_t	ft_strlen(const char *str);


#endif
