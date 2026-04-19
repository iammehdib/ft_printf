/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 19:28:10 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/19 19:14:52 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	find_type_pourcentage(va_list args, char c, size_t *str_lenght)
{
	int	number_of_writing_char;

	number_of_writing_char = 2;
	if (c == 'c')
		print_char(va_arg(args, int), str_lenght);
	else if (c == 's')
		print_string(va_arg(args, char *), str_lenght);
	else if (c == 'd' || c == 'i')
		print_number(va_arg(args, int), str_lenght);
	else if (c == 'u')
		print_number_unsigned(va_arg(args, unsigned int), str_lenght);
	else if (c == 'x')
		print_hexadecimal(va_arg(args, int), 0, str_lenght);
	else if (c == 'X')
		print_hexadecimal(va_arg(args, int), 1, str_lenght);
	else if (c == 'p')
		print_pointer(va_arg(args, intptr_t), str_lenght);
	else if (c == '%')
		write(1, &"%", 1);
	return (number_of_writing_char);
}

int	ft_printf(const char *s, ...)
{
	size_t	index;
	size_t	str_lenght;
	va_list	args;

	index = 0;
	str_lenght = 0;
	va_start(args, s);
	while (s[index])
	{
		if (s[index] == '%' && s[(index + 1)])
			index += find_type_pourcentage(args, s[(index + 1)], &str_lenght);
		else if (s[(index + 1)])
			print_char(s[index++], &str_lenght);
	}
	return (str_lenght);
}

/*int	main()
{
	printf("\nprint len; %d\n", ft_printf("Coucou %s", "Mehdi "));
	ft_printf("%s", (char*) NULL);
}*/
