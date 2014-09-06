/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 16:06:47 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/06 16:06:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	char *beg;

	beg = str;
	while (*str != '\0')
		str++;
	return (str - beg);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_str_is_sudoku(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		if (*ptr < '0' || *ptr > '9' || *ptr != '.')
			return (0);
		ptr++;
	}
	return (1);
}

char	*ft_strdup(char *src)
{
	int i;
	char	*dest;

	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
