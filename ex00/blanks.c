/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blanks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 17:40:53 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/06 17:40:54 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"sudoku_util.c"

int		*init_blanks(char **sudoku)
{
	int	*blanks;
	int b;
	int	i;

	blanks = (int *)malloc(sizeof(int) * 82);
	if (blanks == NULL)
		return (blanks);
	b = 0;
	i = 1;
	while (i <= 81)
	{
		if (*get_sudoku(i, sudoku) == '.')
			blanks[++b] = i;
		i++;
	}
	*blanks = b;
	return (b);
}

char	blank_next(int blank_space, char **sudoku)
{
	int *blank;

	blank = get_sudoku(blank_space, sudoku);
	if (*blank == '.' || *blank == ':')
		*blank = '1';
	while (check_sudoku(blank_space, sudoku) == 0 && *blank != ':')
		(*blank)++;
	return (*blank);
}
