/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_int_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <mel-houa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:21:29 by mel-houa          #+#    #+#             */
/*   Updated: 2024/12/07 22:36:35 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(char *buffer, int index, int count)
{
	while (--index >= 0)
	{
		handl_character(buffer[index]);
		count++;
	}
	return (count);
}

int	fill_buffer(int nb, char *buffer)
{
	int	index;

	index = 0;
	while (nb >= 0)
	{
		buffer[index] = nb % 10 + 48;
		nb = nb / 10;
		index++;
		if (nb == 0)
			break ;
	}
	buffer[index] = '\0';
	return (index);
}

int	handl_int_numbers(int nb)
{
	int		count;
	char	buffer[11];

	count = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			count += 11;
			return (count);
		}
		handl_character('-');
		count++;
		nb = -nb;
	}
	return (print_number(buffer, fill_buffer(nb, buffer), count));
}
