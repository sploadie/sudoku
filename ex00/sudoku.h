/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 19:00:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/06 19:00:29 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	<stdlib.h>

/*util.c*/

void	ft_putchar(char c);

int		ft_strlen(char *str);

void	ft_putstr(char *str);

int		ft_str_is_sudoku(char *str);

char	*ft_strdup(char *src);


/*sudoku_util.c*/

int		is_sudoku(int argc, char **argv);

void	print_sudoku(char **sudoku);

char	*get_sudoku(int num, char **sudoku);

char	**save_sudoku(char **argv);

/*sudoku_check.c*/

int		check_sudoku(int num, char **sudoku);

/*blanks.c*/

int		*init_blanks(char **sudoku);

char	blank_next(int blank_space, char **sudoku);
