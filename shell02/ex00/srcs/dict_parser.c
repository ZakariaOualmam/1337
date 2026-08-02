/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:48:19 by idouiri           #+#    #+#             */
/*   Updated: 2026/08/02 18:27:47 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*extract_key(char **cursor)
{
	int		len;
	char	*key;

	len = 0;
	while ((*cursor)[len] >= '0' && (*cursor)[len] <= '9')
		len++;
	key = ft_strndup(*cursor, len);
	*cursor += len;
	return (key);
}

char	*extract_value(char **cursor)
{
	int		total_len;
	int		trim_len;
	char	*value;

	total_len = 0;
	while ((*cursor)[total_len] && (*cursor)[total_len] != '\n')
		total_len++;
	trim_len = total_len;
	while (trim_len > 0 && (*cursor)[trim_len - 1] == ' ')
		trim_len--;
	value = ft_strndup(*cursor, trim_len);
	*cursor += total_len;
	if (**cursor == '\n')
		(*cursor)++;
	return (value);
}

int	parse_single_entry(char **cursor, t_entry *entry)
{
	skip_spaces(cursor);
	if (**cursor == '\n')
	{
		(*cursor)++;
		return (2);
	}
	entry->key = extract_key(cursor);
	skip_spaces(cursor);
	if (**cursor != ':')
	{
		free(entry->key);
		return (0);
	}
	(*cursor)++;
	skip_spaces(cursor);
	entry->value = extract_value(cursor);
	return (1);
}

t_entry	*parse_dictionary(char *content, int total_lines)
{
	t_entry	*dict;
	char	*cursor;
	int		i;
	int		status;

	dict = malloc(sizeof(t_entry) * (total_lines + 1));
	if (!dict)
		return (NULL);
	cursor = content;
	i = 0;
	while (i < total_lines && *cursor)
	{
		status = parse_single_entry(&cursor, &dict[i]);
		if (status == 0)
		{
			dict[i].key = NULL;
			free_dictionary(dict);
			return (NULL);
		}
		if (status == 1)
			i++;
	}
	dict[i].key = NULL;
	return (dict);
}
