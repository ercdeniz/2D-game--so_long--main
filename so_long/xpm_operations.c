/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:52:11 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/10/16 10:06:18 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx/mlx.h"
#include "../libft/libft.h"

int	keyboard(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_exit(game);
	else if (keycode == W && game->map.area[game->map.position[0] - 1]
		[game->map.position[1]] != '1')
		game->map.position[0]--;
	else if (keycode == A && game->map.area[game->map.position[0]]
		[game->map.position[1] - 1] != '1')
		game->map.position[1]--;
	else if (keycode == S && game->map.area[game->map.position[0] + 1]
		[game->map.position[1]] != '1')
		game->map.position[0]++;
	else if (keycode == D && game->map.area[game->map.position[0]]
		[game->map.position[1] + 1] != '1')
		game->map.position[1]++;
	else
		return (0);
	ft_printf("Number of steps ~> %d\n", ++game->mlx.step);
	if (game->map.area[game->map.position[0]][game->map.position[1]] == 'C')
		game->map.collectible[0]--;
	if (game->map.area[game->map.position[0]][game->map.position[1]] == 'C')
		game->map.area[game->map.position[0]][game->map.position[1]] = '0';
	else if (!game->map.collectible[0]
		&&game->map.area[game->map.position[0]][game->map.position[1]] == 'E')
		return (ft_printf ("❤️Home Sweet Home❤️\n"), ft_exit(game), 0);
	return (0);
}

static inline void	render(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	mlx_clear_window(game->mlx.ptr, game->mlx.win);
	while (game->map.area[++y])
	{
		x = -1;
		while (game->map.area[y][++x])
		{
			if (game->map.area[y][x] == '1')
				mlx_put_image_to_window (game->mlx.ptr, game->mlx.win,
					game->mlx.wall, x * PIXEL, y * PIXEL);
			else if (game->map.area[y][x] == 'C')
				mlx_put_image_to_window (game->mlx.ptr, game->mlx.win,
					game->mlx.coin, x * PIXEL, y * PIXEL);
			else if (game->map.area[y][x] == 'E')
				mlx_put_image_to_window (game->mlx.ptr, game->mlx.win,
					game->mlx.exit, x * PIXEL, y * PIXEL);
			else
				mlx_put_image_to_window (game->mlx.ptr, game->mlx.win,
					game->mlx.ground, x * PIXEL, y * PIXEL);
		}
	}
}

int	put_xml(t_game *game)
{
	render(game);
	mlx_put_image_to_window
		(game->mlx.ptr, game->mlx.win, game->mlx.player,
		game->map.position[1] * PIXEL, game->map.position[0] * PIXEL);
	return (0);
}
