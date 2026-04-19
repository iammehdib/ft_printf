/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbuchet <mbuchet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:05:07 by mbuchet           #+#    #+#             */
/*   Updated: 2026/04/19 19:14:10 by mbuchet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	print_char(char c, size_t *str_lenght);
void	print_string(char *str, size_t *str_lenght);
void	print_number(int number, size_t *str_lenght);
void	print_number_unsigned(unsigned int number, size_t *str_lenght);
void	print_hexadecimal(int number, int is_uppercase, size_t *str_lenght);
void	print_pointer(intptr_t pointer, size_t *str_lenght);

#endif
