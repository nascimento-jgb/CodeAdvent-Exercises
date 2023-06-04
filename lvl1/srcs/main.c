/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:37:18 by jonascim          #+#    #+#             */
/*   Updated: 2023/06/04 16:07:10 by jonascim         ###   ########.fr       */
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

int	calories_count(char **file)
{
	int	partial = 0;
	int	highest = 0;

	for (int i = 0; i < 2244; i++)
	{
		if (file[i] != NULL)
			partial += ft_atoi(file[i]);
		else
		{
			if (partial > highest)
				highest = partial;
			partial = 0;
		}
	}
	return (highest);
}

int	main(int argc, char **argv)
{
	char	**file;
	int		calc;

	if (argc == 2)
	{
		file = parse_file(argv);
		calc = calories_count(file);
		printf("%d\n", calc);
		for (int i = 0; i < 2244; i++)
			free(file[i]);
		free(file);
	}
	return (0);
}
