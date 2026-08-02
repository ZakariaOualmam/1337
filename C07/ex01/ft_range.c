/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:18:05 by idouiri           #+#    #+#             */
/*   Updated: 2026/07/26 08:20:33 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	range = malloc(sizeof (int) * (max - min));
	if (range == NULL)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
