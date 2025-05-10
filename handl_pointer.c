/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:20:41 by mel-houa          #+#    #+#             */
/*   Updated: 2024/12/07 22:22:40 by mel-houa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_number(char *arstring, int index, int count)
{
	while (index > 0)
	{
		handl_character(arstring[--index]);
		count++;
	}
	return (count);
}

int	handl_pointer_part1(unsigned long long add)
{
	int		index;
	int		count;
	char	*buffer;
	char	string[25];

	index = 0;
	count = 0;
	buffer = "0123456789abcdef";
	write(1, "0x", 2);
	count += 2;
	if (add == 0)
	{
		write(1, "0", 1);
		return (count + 1);
	}
	while (add != 0)
	{
		string[index] = buffer[add % 16];
		add = add / 16;
		index++;
	}
	return (print_number(string, index, count));
}

int	handl_pointer(void *p)
{
	unsigned long long	add;

	add = (unsigned long long)p;
	if (add == 0)
	{
		return (write(1, "(nil)", 5));
	}
	return (handl_pointer_part1(add));
}
