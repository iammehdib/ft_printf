/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:28:26 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/20 18:58:01 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_number(int number, size_t *str_lenght)
{
	long	n_long;

	n_long = number;
	if (n_long < 0)
	{
		print_char('-', str_lenght);
		n_long = -n_long;
	}
	if (n_long >= 10)
		print_number(n_long / 10, str_lenght);
	print_char((n_long % 10) + '0', str_lenght);
}

void	print_number_unsigned(unsigned int number, size_t *str_lenght)
{
	long	n_long;

	n_long = number;
	if (n_long >= 10)
		print_number(n_long / 10, str_lenght);
	print_char((n_long % 10) + '0', str_lenght);
}

void	print_hexadecimal(unsigned int number, int is_uppercase, size_t *str_lenght)
{
	unsigned long	n_long;
	char		*str;

	n_long = number;
	if (is_uppercase == 1)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (n_long >= 16)
		print_hexadecimal(n_long / 16, is_uppercase, str_lenght);
	print_char(str[n_long % 16], str_lenght);
}
