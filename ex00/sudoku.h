/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 19:00:28 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/07 18:38:10 by eruffieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SUDOKU_H
# define __SUDOKU_H

# include	<unistd.h>
# include	<stdlib.h>

void	ft_putchar(char c);

int		ft_strlen(char *str);

void	ft_putstr(char *str);

int		ft_str_is_sudoku(char *str);

char	*ft_strdup(char *src);

int		is_sudoku(int argc, char **argv);

void	print_sudoku(char **sudoku);

char	*get_sudoku(int num, char **sudoku);

char	**save_sudoku(char **argv);

int		check_sudoku(int num, char **sudoku);

int		*init_blanks(char **sudoku);

char	blank_next(int blank_space, char **sudoku);

void	ft_putnbr(int nb);

#endif
