/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 17:20:48 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/19 19:10:57 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(intptr_t pointer, size_t *str_lenght)
{
	print_string("0x", str_lenght);
	print_hexadecimal(pointer, 0, str_lenght);
}
