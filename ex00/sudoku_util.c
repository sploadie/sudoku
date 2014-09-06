/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 17:41:25 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/06 17:41:26 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int		is_sudoku(int argc, char **argv)
{
	int	i;

	if (argc != 10)
		return (0);
	i = 1;
	while (i <= 10)
	{
		if (ft_strlen(argv[i]) != 9 || ft_str_is_sudoku(argv[i]) != 1)
			return (0);
	}
	return (1);
}

void	print_sudoku(char **sudoku)
{
	int	i;

	i = 1;
	while (i <= 10)
		ft_putstr(argv[i]);
}

char	*get_sudoku(int num, char **sudoku)
{
	int row;
	int column;

	row = ((num - 1) / 9) + 1;
	column = num % 9;
	if (column == 0)
		column = ((num - 1) / 9) + 1;
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
	while (i <= 10)
	{
		sudoku[i] = ft_strdup(argv[i]);
		if (sudoku[i] == NULL)
			return (NULL);
	}
	return	sudoku;
}
