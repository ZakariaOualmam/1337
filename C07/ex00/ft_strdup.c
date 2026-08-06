/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoualmam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 21:19:43 by zoualmam          #+#    #+#             */
/*   Updated: 2026/08/06 21:19:53 by zoualmam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
	{
		i++;
	}
	dest = malloc((i + 1) * sizeof(*dest));
	if (dest == NULL)
		return (NULL);
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}
/*int main()
{
    char source[] = "Geldouch";

    char* target = ft_strdup(source);

    printf("%s", target);
    return 0;
}*/
