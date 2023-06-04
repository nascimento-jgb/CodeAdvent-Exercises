/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:37:18 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/04 16:34:26 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

char	**parse_file(char **argv)
{
	const int	fd = open(argv[1], O_RDONLY);
	const char	*line = get_next_line(fd);
	char		**file = malloc(sizeof(char *));
	int			line_count = 0;
	char		**tokens;

	if (fd == -1)
		return (NULL);
	while (line != NULL)
	{
		tokens = ft_split(line, '\n');
		file[line_count++] = tokens[0];
		file = realloc(file, (line_count + 1) * sizeof(char *));
		free(tokens);
		line = get_next_line(fd);
	}
	file[line_count] = NULL;
	close(fd);
	return (file);
}

int	*calories_count(char **file)
{
	int	*elfs = malloc(sizeof(int *));
	int	index = 0;
	int	partial = 0;

	for (int i = 0; i < 2244; i++)
	{
		if (file[i] != NULL)
			partial += ft_atoi(file[i]);
		else
		{
			elfs[index] = partial;
			elfs = realloc(elfs, (index + 1) * sizeof(char *));
			index++;
			partial = 0;
		}
	}
	elfs[index] = -1;
	return (elfs);
}

int	*sort(int *elfs)
{
	int	aux = 0;
	int	index = 0;

	while (elfs[index + 1] != -1)
	{
		if (elfs[index] < elfs[index + 1])
		{
			aux = elfs[index + 1];
			elfs[index + 1] = elfs[index];
			elfs[index] = aux;
			index = 0;
		}
		else
			index++;
	}
	return (elfs);
}

int	main(int argc, char **argv)
{
	char	**file;
	int		*elfs;

	if (argc == 2)
	{
		file = parse_file(argv);
		elfs = calories_count(file);
		elfs = sort(elfs);
		// for (int i = 0; elfs[i] != -1; i++)
		// 	printf("%d\n", elfs[i]);
		printf("%d\n", elfs[0] + elfs[1] + elfs[2]);
		for (int i = 0; i < 2244; i++)
			free(file[i]);
		free(file);
	}
	return (0);
}
