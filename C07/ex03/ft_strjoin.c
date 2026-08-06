/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:10:20 by zoualmam          #+#    #+#             */
/*   Updated: 2026/08/06 21:13:20 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	size_sep(char *sep)
{
	int	i;

	i = 0;
	while (sep[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	size_strs(char **strs, int count)
{
	int	j;
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (i < count)
	{
		j = 0;
		while (strs[i][j])
		{
			s++;
			j++;
		}
		i++;
	}
	return (s);
}

void	ft_fill(int size, char **strs, char *st, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			st[k++] = strs[i][j++];
		i++;
		if (i < size)
		{
			j = 0;
			while (sep[j])
				st[k++] = sep[j++];
		}
	}
	st[k] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		a;
	int		b;
	char	*st;

	a = size_strs(strs, size);
	b = size_sep(sep);
	if (size == 0)
	{
		st = malloc(sizeof(char));
		if (st == NULL)
			return (NULL);
		st[0] = '\0';
		return (st);
	}
	if (size == 1)
		st = malloc((a + 1) * sizeof(char));
	else
		st = malloc((a + b * (size - 1) + 1) * sizeof(char));
	if (st == NULL)
		return (NULL);
	ft_fill(size, strs, st, sep);
	return (st);
}
/*#include<stdio.h>
int main()
{
	char *stt[] = {"abc"};
	char sp[] = "---";
	printf("%s \n", ft_strjoin(1, stt, sp));
	return 0;
}*/
