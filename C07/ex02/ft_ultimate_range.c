/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:10:04 by zoualmam          #+#    #+#             */
/*   Updated: 2026/08/06 21:13:49 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(i * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (j < i)
	{
		(*range)[j] = min;
		j++;
		min++;
	}
	return (i);
}
/*#include<stdio.h>
int main ()
{
	int	a = 12;
	int	b = 34;
	int	i;
	int	sz;
	int	*std;

	i = 0;
	sz = ft_ultimate_range(&std, a, b);
	while (i < sz)
	{
		printf("%d", std[i]);
		i++;
	}
	return 0;
}*/
