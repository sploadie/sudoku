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

#include	<unistd.h>
#include	<stdlib.h>
#include	"util.c"
#include	"sudoku_util.c"
#include	"blanks.c"

int		print_error(void)
{
	write(1, "Erreur\n", 7);
	return (0);
}

int solve(char **argv, int *blanks, int curr_blank)
{
	if (blank_next(blanks[curr_blank], argv) != ':')
		if (curr_blank != blanks[0])
			return (solve(argv, blanks, curr_blank + 1));
		else
			return (curr_blank);
	else if (curr_blank == 1)
		return (0);
	else
		return (solve(argv, blanks, curr_blank - 1));
}

int	main(int argc, char **argv)
{
	int	*blanks;
	char **solution;

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
