/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:28:10 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/21 18:59:11 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	handle_specifier(va_list args, char c, size_t *str_length)
{
	if (c == 'c')
		print_char(va_arg(args, int), str_length);
	else if (c == 's')
		print_string(va_arg(args, char *), str_length);
	else if (c == 'd' || c == 'i')
		print_number(va_arg(args, int), str_length);
	else if (c == 'u')
		print_number_unsigned(va_arg(args, unsigned int), str_length);
	else if (c == 'x')
		print_hexadecimal(va_arg(args, unsigned int), 0, str_length);
	else if (c == 'X')
		print_hexadecimal(va_arg(args, unsigned int), 1, str_length);
	else if (c == 'p')
		print_pointer((uintptr_t) va_arg(args, void *), str_length);
	else
		print_char('%', str_length);
	return (2);
}

int	ft_printf(const char *s, ...)
{
	size_t	index;
	size_t	str_length;
	va_list	args;

	if (s == NULL)
		return (-1);
	index = 0;
	str_length = 0;
	va_start(args, s);
	while (s[index])
	{
		if (s[index] == '%' && s[(index + 1)])
			index += handle_specifier(args, s[(index + 1)], &str_length);
		else
			print_char(s[index++], &str_length);
	}
	va_end(args);
	return (str_length);
}
