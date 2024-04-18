/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:27 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/18 18:47:11 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message_exit_clean(t_game *game, char *message)
{
	free_map(game->map, game->height);
	error_message(message);
	// free(game->textures);
	// exit(EXIT_FAILURE);
}

void	error_message(char *message)
{
	ft_putendl_fd("ERROR", 2);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	checker_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(&file[len - 4], ".ber", 4))
		error_message("Please, use a .ber file for the Map");
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_message("Insert ONE FILE! Just ONE MAP!");
	checker_file_extension(argv[1]);
	game = turn_file_into_data(argv[1]);
	game.mlx = mlx_init((game.width * PIXELS),
			(game.height * PIXELS + 22), "so_long", true);
	ft_putendl_fd("Let's Play! Mr Rabbit is hungry!", 1);
	if (!game.mlx)
		message_exit_clean(&game, "MLX problem");
	game.textures = initialize_image_struct(&game);
	add_floor_window(&game);
	add_texture_window(&game);
	message_to_screen(&game);
	mlx_key_hook(game.mlx, ft_hook_moves, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(game.map, game.height);
	return (free(game.textures), (EXIT_SUCCESS));
}
