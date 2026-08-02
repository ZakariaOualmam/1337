/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_triplet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 16:14:37 by idouiri           #+#    #+#             */
/*   Updated: 2026/08/02 18:24:14 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

int	print_triplet(char *nbr, int len, t_print *p)
{
	if (len == 1 && nbr[0] != '0')
	{
		p->buffer[0] = nbr[0];
		p->buffer[1] = '\0';
		return (print_word(p->buffer, p));
	}
	if (len == 2)
		return (print_tens(nbr, p));
	if (len == 3 && nbr[0] != '0')
	{
		p->buffer[0] = nbr[0];
		p->buffer[1] = '\0';
		if (!print_word(p->buffer, p) || !print_word("100", p))
			return (0);
	}
	if (len == 3)
		return (print_triplet(nbr + 1, 2, p));
	return (1);
}
