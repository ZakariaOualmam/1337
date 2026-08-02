/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 08:22:23 by idouiri           #+#    #+#             */
/*   Updated: 2026/07/26 08:34:24 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	array = malloc(sizeof (int) * (max - min));
	if (array == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < max - min)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (max - min);
}
