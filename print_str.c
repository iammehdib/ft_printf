/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:28:26 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/21 18:59:11 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *str, size_t *str_length)
{
	size_t	index;

	if (str == NULL)
	{
		print_string("(null)", str_length);
		return ;
	}
	index = 0;
	while (str[index])
		write(1, &str[index++], 1);
	*str_length += index;
}

void	print_char(char c, size_t *str_length)
{
	write(1, &c, 1);
	*str_length += 1;
}
