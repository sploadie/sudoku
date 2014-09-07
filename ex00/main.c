/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 16:07:34 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/07 18:34:31 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sudoku.h"

int		print_error(void)
{
	write(1, "Erreur\n", 7);
	return (0);
}

int		solve(char **sudoku, int *blanks, int curr_blank)
{
	while (curr_blank != blanks[0] + 1 && curr_blank != 0)
	{
		if (blank_next(blanks[curr_blank], sudoku) != ':')
		{
			curr_blank++;
		}
		else
		{
			curr_blank--;
		}
	}
	return (curr_blank);
}

int		main(int argc, char **argv)
{
	int		*blanks;
	char	**solution;

	if (is_sudoku(argc, argv) == 0)
		return (print_error());
	blanks = init_blanks(argv);
	if (blanks == NULL || blanks[0] == 0 || blanks[0] > 64)
		return (print_error());
	if (solve(argv, blanks, 1) == 0)
		return (print_error());
	solution = save_sudoku(argv);
	if (solution == NULL)
		return (print_error());
	if (solve(argv, blanks, blanks[0]) != 0)
		return (print_error());
	print_sudoku(solution);
	free(blanks);
	free(solution);
	return (0);
}
