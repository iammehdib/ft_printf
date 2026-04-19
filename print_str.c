/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:28:26 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/19 19:11:43 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *str, size_t *str_lenght)
{
	size_t	index;

	if (str == NULL)
	{
		print_string("(null)", str_lenght);
		return ;
	}
	index = 0;
	while (str[index])
		write(1, &str[index++], 1);
	*str_lenght += index;
}

void	print_char(char c, size_t *str_lenght)
{
	if (c == 0)
	{
		print_string("(null)", str_lenght);
		return ;
	}
	write(1, &c, 1);
	*str_lenght += 1;
}
