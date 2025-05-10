/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_unsigned_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:19:57 by mel-houa          #+#    #+#             */
/*   Updated: 2024/12/07 19:20:02 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	part_rec(unsigned int number, int *count)
{
	if (number >= 10)
	{
		part_rec(number / 10, count);
	}
	*count += handl_character(number % 10 + '0');
}

int	handl_unsigned_numbers(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (handl_character('0'));
	part_rec(num, &count);
	return (count);
}
