/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_sprites.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/17 17:05:07 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/17 18:34:18 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_image	*add_player_direction_texture_2(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*hero_left;
	mlx_texture_t	*hero_right;

	hero_left = mlx_load_png("texture/hero_left.png");
	if (hero_left == NULL)
		error_message("Problem with loading P.Image");
	image->p_left = mlx_texture_to_image(mlx, hero_left);
	if (image->p_left == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero_left);
	hero_right = mlx_load_png("texture/hero_right.png");
	if (hero_right == NULL)
		error_message("Problem with loading P.Image");
	image->p_right = mlx_texture_to_image(mlx, hero_right);
	if (image->p_right == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero_right);
	return (image);
}

t_image	*add_player_direction_texture_1(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*hero_up;
	mlx_texture_t	*hero_down;

	hero_up = mlx_load_png("texture/hero_up.png");
	if (hero_up == NULL)
		error_message("Problem with loading P.Image");
	image->p_up = mlx_texture_to_image(mlx, hero_up);
	if (image->p_up == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero_up);
	hero_down = mlx_load_png("texture/hero_down.png");
	if (hero_down == NULL)
		error_message("Problem with loading P.Image");
	image->p_down = mlx_texture_to_image(mlx, hero_down);
	if (image->p_down == NULL)
		error_message("Problem adding texture P.Image");
	mlx_delete_texture(hero_down);
	image = add_player_direction_texture_2(mlx, image);
	return (image);
}
void	direction_texture(t_game *game, char c)
{
	if (c == 'U')
	{
		game->textures->p_up->instances->enabled = true;
		game->textures->player->instances->enabled = false;
		game->textures->p_down->instances->enabled = false;
		game->textures->p_right->instances->enabled = false;
		game->textures->p_left->instances->enabled = false;
	}
	if (c == 'D')
	{
		game->textures->p_down->instances->enabled = true;
		game->textures->player->instances->enabled = false;
		game->textures->p_up->instances->enabled = false;
		game->textures->p_right->instances->enabled = false;
		game->textures->p_left->instances->enabled = false;
	}
	if (c == 'L')
	{
		game->textures->p_left->instances->enabled = true;
		game->textures->player->instances->enabled = false;
		game->textures->p_up->instances->enabled = false;
		game->textures->p_down->instances->enabled = false;
		game->textures->p_right->instances->enabled = false;
	}
	if (c == 'R')
	{
		game->textures->p_right->instances->enabled = true;
		game->textures->player->instances->enabled = false;
		game->textures->p_up->instances->enabled = false;
		game->textures->p_down->instances->enabled = false;
		game->textures->p_left->instances->enabled = false;
	}
}