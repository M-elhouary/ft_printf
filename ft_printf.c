/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:20:17 by mel-houa          #+#    #+#             */
/*   Updated: 2024/12/07 22:07:14 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handl_format(int index, const char *s, va_list param)
{
	int	count;

	count = 0;
	index++;
	if (s[index] == 'd' || s[index] == 'i')
		count += handl_int_numbers(va_arg(param, int));
	else if (s[index] == 'u')
		count += handl_unsigned_numbers(va_arg(param, unsigned int));
	else if (s[index] == 'x' || s[index] == 'X')
		count += handl_hex(va_arg(param, unsigned int), s[index]);
	else if (s[index] == 'p')
		count += handl_pointer(va_arg(param, void *));
	else if (s[index] == 's')
		count += handl_string(va_arg(param, const char *));
	else if (s[index] == 'c')
		count += handl_character(va_arg(param, int));
	else
	{
		handl_character(s[index]);
		count++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	param;
	int		count;
	int		index;

	va_start(param, s);
	count = 0;
	index = 0;
	if (!s)
		return (-1);
	while (s[index] != '\0')
	{
		if (s[index] == '%' && s[index + 1] == '\0')
			return (-1);
		if (s[index] == '%' && s[index + 1] != '\0')
		{
			count += handl_format(index, s, param);
			index++;
		}
		else
			count += handl_character(s[index]);
		index++;
	}
	va_end(param);
	return (count);
}
