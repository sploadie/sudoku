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

int		check_sudoku(int num, char **sudoku)
{
	char	space;
	int		row;
	int		column;

	row = ((num - 1) / 9) + 1;
	column = num % 9;
	if (column == 0)
		column = ((num - 1) / 9) + 1;
	if    ((check_sudoku_row(row, column, sudoku) == 0)
		|| (check_sudoku_col(row, column, sudoku) == 0)
		|| (check_sudoku_sqr(row, column, sudoku) == 0))
		return (0);
	return (1);
}

int		check_sudoku_row(int row, int column, char **sudoku)
{
	int		i;
	char	space;

	space = sudoku[row][column - 1];
}

int		check_sudoku_col(int row, int column, char **sudoku)
{
	int		i;
	char	space;

	space = sudoku[row][column - 1];

}

int		check_sudoku_sqr(int row, int column, char **sudoku)
{
	int		i;
	char	space;

	space = sudoku[row][column - 1];
}
