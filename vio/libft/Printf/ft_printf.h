/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:26:27 by epascual          #+#    #+#             */
/*   Updated: 2024/12/10 12:54:38 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>

void			checker(int *ret, char check, va_list opc);
int				realprintf(char const *p, va_list opc);
int				ft_printf(char const *print, ...);
unsigned int	strilen(char *s);
int				printchar(char a);
int				printstring(char const *s);
int				printnum(long n, char *base);
int				printunum(unsigned int n, char *base);
int				printpoint(unsigned long long n, char *base);
#endif
