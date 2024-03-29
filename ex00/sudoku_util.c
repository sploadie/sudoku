/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 17:41:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/07 18:42:06 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sudoku.h"

int		is_sudoku(int argc, char **argv)
{
	int	i;

	if (argc != 10)
		return (0);
	i = 1;
	while (i <= 9)
	{
		if (ft_strlen(argv[i]) != 9 || ft_str_is_sudoku(argv[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	print_sudoku(char **sudoku)
{
	int	i;
	int j;

	i = 1;
	while (i <= 9)
	{
		ft_putchar(sudoku[i][0]);
		j = 1;
		while (j < 9)
		{
			ft_putchar(' ');
			ft_putchar(sudoku[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

char	*get_sudoku(int num, char **sudoku)
{
	int row;
	int column;

	row = ((num - 1) / 9) + 1;
	column = num % 9;
	if (column == 0)
		column = ((num - 1) % 9) + 1;
	return (&sudoku[row][column - 1]);
}

char	**save_sudoku(char **argv)
{
	int		i;
	char	**sudoku;

	sudoku = (char **)malloc(sizeof(*sudoku) * 10);
	if (sudoku == NULL)
		return (sudoku);
	i = 1;
	while (i <= 9)
	{
		sudoku[i] = ft_strdup(argv[i]);
		if (sudoku[i] == NULL)
			return (NULL);
		i++;
	}
	return (sudoku);
}
