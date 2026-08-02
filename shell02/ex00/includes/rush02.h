/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 10:53:52 by idouiri           #+#    #+#             */
/*   Updated: 2026/08/02 18:53:08 by idouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_entry
{
	char	*key;
	char	*value;
}			t_entry;

typedef struct s_print
{
	char	*buffer;
	t_entry	*dict;
	int		first_word;
}			t_print;

int		is_valid_number(char *str);
char	*trim_number(char *str);
void	ft_putstr(char *str);
void	skip_spaces(char **cursor);
int		ft_strlen(char *str);
void	fill_with_zeros(char *buffer, int n);
int		is_chunk_zero(char *str, int n);
int		print_word(char *key, t_print *p);
int		print_large_numbers(char *nbr, int len, t_print *p);
int		print_triplet(char *nbr, int len, t_print *p);
int		get_file_size(char *path);
int		count_lines(char *buffer, int size);
void	read_file(char *path, char **buffer, int size);
int		parse_single_entry(char **cursor, t_entry *entry);
t_entry	*parse_dictionary(char *content, int total_lines);
char	*get_value(char *key, t_entry *dict);
char	*ft_strndup(char *src, int n);
int		print_tens(char *nbr, t_print *p);
void	free_dictionary(t_entry *dict);

#endif
