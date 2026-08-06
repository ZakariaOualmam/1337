/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:09:34 by zoualmam          #+#    #+#             */
/*   Updated: 2026/08/06 21:12:42 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	i;
	unsigned int	j;
	int				*arr;

	j = 0;
	if (min >= max)
		return (NULL);
	i = max - min;
	arr = malloc(i * sizeof(int));
	if (arr == NULL)
		return (NULL);
	while (j < i)
	{
		arr[j] = min;
		min++;
		j++;
	}
	return (arr);
}
/*#include<stdio.h>
int main (){
	int a = -12;
	int b = -22;
	int *arr1;
	unsigned int i = 0;
	arr1 = ft_range(b,a);
	if (arr1 == NULL)
	{
		printf ("no alloc || min >= max \n");
		return -1;
	}
	while (i < (unsigned int)(a - b))
	{
		printf("%d \n", *arr1++);
		i++;
	}
	return 0;
}*/
