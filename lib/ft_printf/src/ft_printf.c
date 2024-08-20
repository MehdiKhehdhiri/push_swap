/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhehdir <mkhehdir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:43:17 by mkhehdir          #+#    #+#             */
/*   Updated: 2024/08/20 18:43:19 by mkhehdir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	len;
	int		i;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_printformat(&args, str[++i]);
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_printformat(va_list *ap, char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len += ft_printchar((char)va_arg(*ap, int));
	else if (format == 's')
		len += ft_printstr(va_arg(*ap, char *));
	else if (format == 'p')
		len += ft_printptr(va_arg(*ap, void *));
	else if (format == 'd' || format == 'i')
		len += ft_printint(va_arg(*ap, int));
	else if (format == 'u')
		len += ft_printunsigned(va_arg(*ap, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_printhex((int)va_arg(*ap, unsigned int), format);
	else if (format == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
		return (ft_printstr("(null)"));
	while (*str)
		len += ft_printchar(*str++);
	return (len);
}
