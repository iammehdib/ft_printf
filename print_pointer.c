/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:20:48 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/21 18:59:11 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(uintptr_t pointer, size_t *str_length)
{
	if (pointer == 0)
	{
		print_string("(nil)", str_length);
		return ;
	}
	print_string("0x", str_length);
	print_hexadecimal(pointer, 0, str_length);
}
