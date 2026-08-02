/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:38:38 by idouiri           #+#    #+#             */
/*   Updated: 2026/07/27 09:45:47 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str)
		{
			count++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
	}
	return (count);
}

char	*extract_word(char *str, char *charset)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !is_separator(str[i], charset))
		i++;
	word = malloc(i + 1);
	if (word == NULL)
		return (NULL);
	word[i--] = '\0';
	while (i >= 0)
	{
		word[i] = str[i];
		i--;
	}
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		word_count;
	int		i;

	word_count = count_words(str, charset);
	array = malloc(sizeof (char *) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	array[word_count] = NULL;
	i = 0;
	while (*str)
	{
		while (*str && is_separator(*str, charset))
			str++;
		if (*str)
		{
			array[i] = extract_word(str, charset);
			if (array[i] == NULL)
				return (NULL);
			i++;
			while (*str && !is_separator(*str, charset))
				str++;
		}
	}
	return (array);
}
