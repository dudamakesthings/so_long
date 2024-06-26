/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_map_checkers_bonus.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: edribeir <edribeir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/19 17:08:35 by edribeir      #+#    #+#                 */
/*   Updated: 2024/04/19 17:17:50 by edribeir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_map_occurrences(char *map)
{
	int	i;
	int	player;
	int	e_xit;
	int	collectible;

	i = 0;
	player = 0;
	e_xit = 0;
	collectible = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			player++;
		if (map[i] == 'E')
			e_xit++;
		if (map[i] == 'C')
			collectible++;
		i++;
	}
	if (player != 1 || e_xit != 1 || collectible < 1)
	{
		free (map);
		error_message("Invalid Map content. Please try a different file.");
	}
}

static void	check_map_invalid_char(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr("01PECS\n", map[i]) == NULL)
		{
			ft_putendl_fd("ERROR", 2);
			ft_printf("Invalid Map, there is a Invalid Character, ");
			ft_printf("please try a different file\n");
			free(map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	check_map_empty_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && (map[i + 1]) == '\n'))
		{
			ft_putendl_fd("ERROR", 2);
			ft_printf("Invalid Map,there is a Empty Line, ");
			ft_printf("please try a different file\n");
			free(map);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

void	str_map_checkers(char *str_map)
{
	check_map_empty_line(str_map);
	check_map_invalid_char(str_map);
	check_map_occurrences(str_map);
}
