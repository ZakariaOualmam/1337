/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 18:26:35 by idouiri           #+#    #+#             */
/*   Updated: 2026/08/02 18:27:58 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dictionary(t_entry *dict)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (dict[i].key)
	{
		free(dict[i].key);
		if (dict[i].value)
			free(dict[i].value);
		i++;
	}
	free(dict);
}

char	*get_value(char *key, t_entry *dict)
{
	int	i;
	int	j;

	i = 0;
	while (dict[i].key)
	{
		j = 0;
		while (key[j] && dict[i].key[j] == key[j])
			j++;
		if (key[j] == '\0' && dict[i].key[j] == '\0')
			return (dict[i].value);
		i++;
	}
	return (0);
}
