/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 08:39:15 by idouiri           #+#    #+#             */
/*   Updated: 2026/07/26 10:58:59 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_strs_len(char **strs, int size)
{
	int	i;
	int	len_total;

	i = 0;
	len_total = 0;
	while (i < size)
	{
		len_total += ft_strlen(strs[i]);
		i++;
	}
	return (len_total);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*buffer;

	if (size <= 0)
	{
		buffer = malloc(1);
		if (buffer)
			buffer[0] = '\0';
		return (buffer);
	}
	buffer = malloc(get_strs_len(strs, size) + (size - 1) * ft_strlen(sep) + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(buffer, strs[i]);
		if (i < size - 1)
			ft_strcat(buffer, sep);
	}
	return (buffer);
}
