/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:10:50 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/06 14:25:34 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_join_n_free(char *stash, char *rbuff);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*ft_strchr2(const char *s, int c);

void	*ft_calloc2(size_t count, size_t size);
void	ft_bzero2(void *s, size_t n);

size_t	ft_strlen2(const char *str);

#endif
