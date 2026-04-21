/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:05:07 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/21 18:59:11 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *s, ...);
void	print_char(char c, size_t *str_length);
void	print_string(char *str, size_t *str_length);
void	print_number(int number, size_t *str_length);
void	print_number_unsigned(unsigned int number, size_t *str_length);
void	print_hexadecimal(unsigned long number, int is_upper, size_t *str_len);
void	print_pointer(uintptr_t pointer, size_t *str_length);

#endif
