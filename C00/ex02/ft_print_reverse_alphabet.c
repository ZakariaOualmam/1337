/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:39:13 by zoualmam          #+#    #+#             */
/*   Updated: 2026/07/15 21:08:09 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	let_reverse;

	let_reverse = 'z';
	while (let_reverse >= 'a')
	{
		write(1, &let_reverse, 1);
		let_reverse--;
	}
}
