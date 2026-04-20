/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:20:48 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/20 19:27:25 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(uintptr_t pointer, size_t *str_lenght)
{
	if (pointer == 0) 
	{
		print_string("(nil)", str_lenght);
		return ;
	}
	print_string("0x", str_lenght);
	print_hexadecimal(pointer, 0, str_lenght);
}
