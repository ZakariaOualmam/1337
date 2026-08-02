/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_engine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:47:00 by idouiri           #+#    #+#             */
/*   Updated: 2026/08/02 18:25:11 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	print_word(char *key, t_print *p)
{
	char	*val;

	val = get_value(key, p->dict);
	if (val == NULL)
		return (0);
	if (p->first_word == 0)
		write(1, " ", 1);
	ft_putstr(val);
	p->first_word = 0;
	return (1);
}

int	is_chunk_zero(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	print_tens(char *nbr, t_print *p)
{
	if (nbr[0] == '0')
		return (print_triplet(nbr + 1, 1, p));
	if (nbr[0] == '1')
	{
		p->buffer[0] = nbr[0];
		p->buffer[1] = nbr[1];
		p->buffer[2] = '\0';
		return (print_word(p->buffer, p));
	}
	p->buffer[0] = nbr[0];
	fill_with_zeros(p->buffer, 1);
	if (!print_word(p->buffer, p))
		return (0);
	return (print_triplet(nbr + 1, 1, p));
}

int	print_large_numbers(char *nbr, int len, t_print *p)
{
	int	chunk_len;

	if (len == 0)
		return (1);
	chunk_len = len % 3;
	if (chunk_len == 0)
		chunk_len = 3;
	if (!is_chunk_zero(nbr, chunk_len))
	{
		if (!print_triplet(nbr, chunk_len, p))
			return (0);
		if (len > 3)
		{
			p->buffer[0] = '1';
			fill_with_zeros(p->buffer, len - chunk_len);
			if (!print_word(p->buffer, p))
				return (0);
		}
	}
	return (print_large_numbers(nbr + chunk_len, len - chunk_len, p));
}
