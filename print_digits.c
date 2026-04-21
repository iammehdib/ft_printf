/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:28:26 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/21 18:59:11 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_number(int number, size_t *str_length)
{
	long	n_long;

	n_long = number;
	if (n_long < 0)
	{
		print_char('-', str_length);
		n_long = -n_long;
	}
	if (n_long >= 10)
		print_number(n_long / 10, str_length);
	print_char((n_long % 10) + '0', str_length);
}

void	print_number_unsigned(unsigned int number, size_t *str_length)
{
	long	n_long;

	n_long = number;
	if (n_long >= 10)
		print_number(n_long / 10, str_length);
	print_char((n_long % 10) + '0', str_length);
}

void	print_hexadecimal(unsigned long number, int is_upper, size_t *str_len)
{
	unsigned long	n_long;
	char			*str;

	n_long = number;
	if (is_upper == 1)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (n_long >= 16)
		print_hexadecimal(n_long / 16, is_upper, str_len);
	print_char(str[n_long % 16], str_len);
}
