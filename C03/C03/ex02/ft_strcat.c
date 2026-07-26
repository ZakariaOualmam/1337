/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 12:29:24 by zoualmam          #+#    #+#             */
/*   Updated: 2026/07/25 12:05:46 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	howmuchsize(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	size;
	int	i;
	int	j;

	size = howmuchsize(src) + howmuchsize(dest);
	i = howmuchsize(dest);
	j = 0;
	while (i <= size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
