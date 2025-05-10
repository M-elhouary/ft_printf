/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:28:46 by mel-houa          #+#    #+#             */
/*   Updated: 2024/12/07 22:29:36 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

int	handl_int_numbers(int param);
int	handl_character(char c);
int	handl_string(const char *s);
int	handl_hex(unsigned int nb, char c);
int	handl_pointer(void *p);
int	handl_unsigned_numbers(unsigned int num);
int	ft_printf(const char *s, ...);

#endif
