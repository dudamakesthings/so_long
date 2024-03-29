/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   content.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/27 12:04:30 by edribeir      #+#    #+#                 */
/*   Updated: 2024/03/27 18:05:26 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*collectible_counter(char **map, t_game *game)
{
	int	collectible;
	int	line;
	int	col;

	collectible = 0;
	line = 0;
	while(map[line])
	{
		col = 0;
		while(map[line][col])
		{
			if (map[line][col] == 'C')
				collectible++;
			col++;
		}
		line++;
	}
	game->collectable = collectible;
	return (game);
}

t_game	*element_position(char **map, t_game *game)
{
	int		col;
	int		line;

	line = 0;
	while (map[line])
	{
		col = 0;
		while(map[line][col])
		{
			if(map[line][col] == 'P')
			{
				game->player_position_x = line;
				game->player_position_y = col;
			}
			if(map[line][col] == 'E')
			{
				game->exit_position_x = line;
				game->exit_position_y = col;
			}
			col++;
		}
		line++;
	}
	return (game);
}
t_game	*initialize_game_struct(char **map, int height)
{
	t_game	*game;
	
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!game)
		error_message("Memory Allocation Failed");
	game->moves = 0;
	game = collectible_counter(map, game);
	game = element_position(map, game);
	game->height = height;
	game->width = (ft_strlen(map[0]) - 1);
		ft_printf("%i how many carrots\n", game->collectable);
		ft_printf("%i position exit line\n", game->exit_position_x);
		ft_printf("%i position exit column\n", game->exit_position_y);
		ft_printf("%i position player line\n", game->player_position_x);
		ft_printf("%i position player column\n", game->player_position_y);
		ft_printf("%i widht\n", game->width);
		ft_printf("%i height\n", game->height);
	return (game);
}