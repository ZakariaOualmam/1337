/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:34:11 by zoualmam          #+#    #+#             */
/*   Updated: 2026/07/25 16:17:51 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	howmuchsize(char *src)
{
	int	size;

	size = 0;
	while (src[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				o;

	o = howmuchsize(dest);
	i = 0;
	while (src[i] != '\0' && i < nb)
	{
		dest[o] = src[i];
		i++;
		o++;
	}
	dest[o] = '\0';
	return (dest);
}
