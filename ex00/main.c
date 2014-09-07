/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 16:07:34 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/06 16:07:34 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sudoku.h"

int		print_error(void)
{
	write(1, "Erreur\n", 7);
	return (0);
}

int solve(char **sudoku, int *blanks, int curr_blank)
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

int	main(int argc, char **argv)
{
	int	*blanks;
	char **solution;

	if (is_sudoku(argc, argv) == 0)
		return (print_error());

	write(1, "A\n", 2); //FIXME

	blanks = init_blanks(argv);

	write(1, "B\n", 2); //FIXME

	if (blanks == NULL || blanks[0] == 0 || blanks[0] > 64)
		return (print_error());

	write(1, "C\n", 2); //FIXME

	if (solve(argv, blanks, 1) == 0)
		return (print_error());

	write(1, "D\n", 2); //FIXME

	solution = save_sudoku(argv);

	write(1, "E\n", 2); //FIXME

	if (solution == NULL)
		return (print_error());

	write(1, "F\n", 2); //FIXME

	if (solve(argv, blanks, blanks[0]) != 0)
		return (print_error());

	write(1, "G\n", 2); //FIXME

	print_sudoku(solution);

	write(1, "H\n", 2); //FIXME

	free(blanks);

	write(1, "I\n", 2); //FIXME

	free(solution);

	write(1, "J\n", 2); //FIXME

	return (0);
}
