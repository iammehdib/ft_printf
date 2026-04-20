/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:28:10 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/20 20:31:08 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	handle_specifier(va_list args, char c, size_t *str_lenght)
{
	if (c == 'c')
		print_char(va_arg(args, int), str_lenght);
	else if (c == 's')
		print_string(va_arg(args, char *), str_lenght);
	else if (c == 'd' || c == 'i')
		print_number(va_arg(args, int), str_lenght);
	else if (c == 'u')
		print_number_unsigned(va_arg(args, unsigned int), str_lenght);
	else if (c == 'x')
		print_hexadecimal(va_arg(args, unsigned int), 0, str_lenght);
	else if (c == 'X')
		print_hexadecimal(va_arg(args, unsigned int), 1, str_lenght);
	else if (c == 'p')
		print_pointer((uintptr_t) va_arg(args, void *), str_lenght);
	else
		print_char('%', str_lenght);
	return (2);
}

int	ft_printf(const char *s, ...)
{
	size_t	index;
	size_t	str_lenght;
	va_list	args;

	if (s == NULL)
		return (-1);
	index = 0;
	str_lenght = 0;
	va_start(args, s);
	while (s[index])
	{
		if (s[index] == '%' && s[(index + 1)])
			index += handle_specifier(args, s[(index + 1)], &str_lenght);
		else
			print_char(s[index++], &str_lenght);
	}
	va_end(args);
	return (str_lenght);
}

/*#include <stdio.h>

int	main(void)
{
	ft_printf("\nprint len; %d\n", ft_printf("Coucou %s", "Mehdi "));
	ft_printf("%s\n", (char *) NULL);
	ft_printf(" %c %c %c \n", '2', '1', 0);
	ft_printf(" %p \n", -1);
	ft_printf(" %x \n", 0);


	ft_printf("1:jdhsjhds%z %%% \n");
	ft_printf("2: %%%% \n");
	printf("1:jdhsjhds%z %%% \n");
	printf("2: %%%% \n");
}*/
