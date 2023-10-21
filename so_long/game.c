/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:14:24 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/10/20 15:23:20 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include "so_long.h"

static inline int	mlx_exit(t_game *game)
{
	return (ft_exit(game), 0);
}

static inline void	init_mlx(t_game *game)
{
	int	x;
	int	y;

	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, game->map.width * PIXEL,
			game->map.height * PIXEL, "so_long");
	game->mlx.player = mlx_xpm_file_to_image(game->mlx.ptr,
			"../xpm_file/player.xpm", &y, &x);
	game->mlx.exit = mlx_xpm_file_to_image(game->mlx.ptr,
			"../xpm_file/exit.xpm", &y, &x);
	game->mlx.ground = mlx_xpm_file_to_image(game->mlx.ptr,
			"../xpm_file/ground.xpm", &y, &x);
	game->mlx.coin = mlx_xpm_file_to_image(game->mlx.ptr,
			"../xpm_file/coin.xpm", &y, &x);
	game->mlx.wall = mlx_xpm_file_to_image(game->mlx.ptr,
			"../xpm_file/wall.xpm", &y, &x);
	if (!game->mlx.player || !game->mlx.exit || !game->mlx.ground
		|| !game->mlx.coin || !game->mlx.wall || !game->mlx.ptr)
		return (ft_printf("%s\n", game->error.xpm), ft_exit(game));
}

void	ft_mlx(t_game *game)
{
	init_mlx(game);
	mlx_hook(game->mlx.win, 2, 0, keyboard, game);
	mlx_hook(game->mlx.win, 17, 0, mlx_exit, game);
	mlx_loop_hook(game->mlx.ptr, put_xml, game);
	mlx_loop(game->mlx.ptr);
}
