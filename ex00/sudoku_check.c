/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 00:31:16 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/07 00:31:23 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sudoku.h"

int		check_sudoku_r_c(int row, int column, char **sudoku)
{
	int		i;
	char	space;

	space = sudoku[row][column - 1];
	i = 1;
	while (i <= 9)
	{
		if (sudoku[row][i - 1] == space && i != column)
		{
			return (0);
		}
		if (sudoku[i][column - 1] == space && i != row)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		check_sudoku_sqr(int row, int column, char **sudoku)
{
	int		i;
	int		j;
	int		box_row;
	int		box_col;
	char	space;

	space = sudoku[row][column - 1];
	box_col = ((column - 1) / 3) * 3;
	box_row = ((row - 1) / 3) * 3;
	i = 1;
	while (i <= 3)
	{
		j = 1;
		while (j <= 3)
		{
			if (sudoku[box_row + i][(box_col + j) - 1] == space
				&& box_row + i != row
				&& box_col + j != column)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		check_sudoku(int num, char **sudoku)
{
	int		row;
	int		column;

	row = ((num - 1) / 9) + 1;
	column = num % 9;
	if (column == 0)
		column = ((num - 1) % 9) + 1;

	if    ((check_sudoku_r_c(row, column, sudoku) == 0)
		|| (check_sudoku_sqr(row, column, sudoku) == 0))
		return (0);
	return (1);
}
