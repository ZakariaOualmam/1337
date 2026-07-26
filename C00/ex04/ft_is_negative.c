/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 20:54:10 by zoualmam          #+#    #+#             */
/*   Updated: 2026/07/15 21:02:28 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	value;

	value = 'P';
	if (n < 0)
	{		
		value = 'N';
		write(1, &value, 1);
	}
	else
	{
		value = 'P';
		write(1, &value, 1);
	}
}
