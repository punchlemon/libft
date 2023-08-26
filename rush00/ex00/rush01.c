/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusatou <yusatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 21:15:22 by yusatou           #+#    #+#             */
/*   Updated: 2023/08/13 21:22:40 by yusatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	g_char[3][3] = {
{'/', '*', '\\'},
{'*', ' ', '*'},
{'\\', '*', '/'}
};

void	ft_putchar(char c);

void	locate(int *xy, int *wh)
{
	int	ix;
	int	iy;

	ix = 1;
	iy = 1;
	if (xy[0] == 0)
		ix = 0;
	else if (xy[0] == (wh[0] - 1))
		ix = 2;
	if (xy[1] == 0)
		iy = 0;
	else if (xy[1] == (wh[1] - 1))
		iy = 2;
	ft_putchar(g_char[iy][ix]);
}

void	rush01(int width, int height)
{
	int		wh[2];
	int		xy[2];

	wh[0] = width;
	wh[1] = height;
	xy[1] = 0;
	while (xy[1] < wh[1])
	{
		xy[0] = 0;
		while (xy[0] < wh[0])
		{
			locate(xy, wh);
			xy[0]++;
		}
		ft_putchar('\n');
		xy[1]++;
	}
}
