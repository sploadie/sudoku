/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 16:06:47 by tgauvrit          #+#    #+#             */
/*   Updated: 2014/09/06 16:06:47 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	char *beg;

	beg = str;
	while (*str != '\0')
		str++;
	return (str - beg);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		ft_str_is_sudoku(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		if ((*ptr < '0' || *ptr > '9') && *ptr != '.')
			return (0);
		ptr++;
	}
	return (1);
}

char	*ft_strdup(char *src)
{
	int i;
	char	*dest;

	dest = (char *)malloc(sizeof(*dest) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

//FIXME V
void	ft_putdigit(int digit)
{
	ft_putchar('0' + digit);
}

void	ft_putnbr(int nb)
{
	char	rev_nb[10];
	int		rev_count;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	nb = nb * -1;
	rev_count = -1;
	while (nb < -9)
	{
		rev_count++;
		rev_nb[rev_count] = (nb - ((nb / 10) * 10)) * -1;
		nb = nb / 10;
	}
	ft_putdigit(nb * -1);
	while (rev_count > -1)
	{
		ft_putdigit(rev_nb[rev_count]);
		rev_count--;
	}
	return ;
}

