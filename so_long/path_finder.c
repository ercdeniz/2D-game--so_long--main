/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:12:27 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/10/12 11:46:20 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "so_long.h"

static inline void	path_finder(t_game *game, int x, int y)
{
	if (game->map.virtual_map[y][x] == '1')
		return ;
	else if (game->map.virtual_map[y][x] == 'C')
		game->map.collectible[1]++;
	else if (game->map.virtual_map[y][x] == 'E')
		game->map.exit[1] = 1;
	else if (game->map.virtual_map[y][x] != 'P'
		&& game->map.virtual_map[y][x] != '0')
		return (ft_printf("%s\n", game->error.undefined), ft_exit(game));
	game->map.virtual_map[y][x] = '1';
	path_finder(game, x - 1, y);
	path_finder(game, x, y - 1);
	path_finder(game, x + 1, y);
	path_finder(game, x, y + 1);
}

void	is_game(t_game *game)
{
	game->map.collectible[1] = 0;
	game->map.exit[1] = 0;
	path_finder(game, game->map.position[1], game->map.position[0]);
	if (game->map.collectible[1] != game->map.collectible[0])
		return (ft_printf("%s\n", game->error.unreachable_coin), ft_exit(game));
	if (!game->map.exit[1])
		return (ft_printf("%s\n", game->error.unreachable_exit), ft_exit(game));
}
