/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:12:09 by idouiri           #+#    #+#             */
/*   Updated: 2026/08/02 17:13:21 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

t_entry	*load_dictionary(char *path)
{
	int		size;
	char	*content;
	int		lines;
	t_entry	*dict;

	size = get_file_size(path);
	if (size < 0)
		return (NULL);
	content = malloc(size + 1);
	if (!content)
		return (NULL);
	read_file(path, &content, size);
	content[size] = '\0';
	lines = count_lines(content, size);
	dict = parse_dictionary(content, lines);
	free(content);
	return (dict);
}

void	execute_print(char *nbr, t_entry *dict, int len)
{
	t_print	p;
	int		success;

	p.buffer = malloc(len + 1);
	if (!p.buffer)
		return ;
	p.dict = dict;
	p.first_word = 1;
	if (len == 1 && nbr[0] == '0')
		success = print_word("0", &p);
	else
		success = print_large_numbers(nbr, len, &p);
	if (!success)
		write(1, "Dict Error\n", 11);
	else
		write(1, "\n", 1);
	free(p.buffer);
}

int	main(int argc, char *argv[])
{
	char	*nbr;
	char	*dict_path;
	t_entry	*dict;

	if (argc < 2 || argc > 3 || !is_valid_number(argv[argc - 1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	dict_path = "./numbers.dict";
	if (argc == 3)
		dict_path = argv[1];
	dict = load_dictionary(dict_path);
	if (!dict)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	nbr = trim_number(argv[argc - 1]);
	execute_print(nbr, dict, ft_strlen(nbr));
	free_dictionary(dict);
	return (0);
}
