/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/05 15:23:27 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/04 18:33:18 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	t_game *game;

	if (argc != 2)
		error_message("Insert ONE FILE! Just ONE MAP!");
	checker_file_extension(argv[1]);
	game = turn_file_into_data(argv[1]); 
	if (!(game->mlx = mlx_init((game->width * PIXELS), (game->height * PIXELS), "so_long", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	game->textures = initialize_image_struct(game);
	add_floor_window(game);
	add_texture_window(game);
	mlx_key_hook(game->mlx, ft_hook_moves, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
