/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:20:52 by mel-houa          #+#    #+#             */
/*   Updated: 2024/12/07 22:24:39 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	part_for_low(unsigned int number, int *count)
{
	char	*buffer;

	buffer = "0123456789abcdef";
	if (number >= 16)
		part_for_low(number / 16, count);
	*count += handl_character(buffer[number % 16]);
}

int	handl_hex_low(unsigned int number)
{
	int	count;

	count = 0;
	part_for_low(number, &count);
	return (count);
}

static void	part_for_up(unsigned int number, int *count)
{
	char	*buffer2;

	buffer2 = "0123456789ABCDEF";
	if (number >= 16)
		part_for_up(number / 16, count);
	*count += handl_character(buffer2[number % 16]);
}

int	handl_hex_up(unsigned int number)
{
	int	count;

	count = 0;
	part_for_up(number, &count);
	return (count);
}

int	handl_hex(unsigned int nb, char c)
{
	if (c == 'x')
		return (handl_hex_low(nb));
	else
		return (handl_hex_up(nb));
}
