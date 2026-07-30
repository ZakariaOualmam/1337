/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:26:24 by zoualmam          #+#    #+#             */
/*   Updated: 2026/07/28 20:45:18 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
int ft_iterative_factorial(int nb)
{
	int	i;
	int	count;

	if(nb < 0)
		return (0);
	count = 1;
	i = 1;
	while(nb = 1)
	{
		count *= i;
		i++;
	}
	return (count);
}


