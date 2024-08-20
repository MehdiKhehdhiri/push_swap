/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhehdir <mkhehdir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:42:31 by mkhehdir          #+#    #+#             */
/*   Updated: 2024/08/20 18:42:40 by mkhehdir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_printformat(va_list *ap, char format);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printptr(void *ptr);
int	ft_printptr_addr(uintptr_t n, const char format);
int	ft_printint(int n);
int	ft_printunsigned(unsigned int n);
int	ft_printhex(unsigned int n, const char format);

#endif