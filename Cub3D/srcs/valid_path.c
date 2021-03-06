/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:31:14 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/15 14:31:16 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	add_in_text(t_game *game, char *str)
{
	char	**split;
	char	*line;

	split = ft_split(str, ' ');
	line = ft_strtrim(split[0], " \t");
	if (!ft_strncmp(line, "NO", 3))
		game->text.no = ft_strdup(split[1]);
	if (!ft_strncmp(line, "SO", 3))
		game->text.so = ft_strdup(split[1]);
	if (!ft_strncmp(line, "WE", 3))
		game->text.we = ft_strdup(split[1]);
	if (!ft_strncmp(line, "EA", 3))
		game->text.ea = ft_strdup(split[1]);
	if (!ft_strncmp(line, "F", 2))
		game->text.f = ft_strdup(split[1]);
	if (!ft_strncmp(line, "C", 2))
		game->text.c = ft_strdup(split[1]);
	ft_freedouble(split);
	free(line);
}

void	ft_check_rgb_sky(t_game *game)
{
	int	i;

	i = -1;
	while (game->text.c[++i])
	{
		if (ft_count_char(game->text.c, ',') != 2)
		{
			ft_error(9);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_check_c(t_game *game)
{
	char	**split;
	int		size;
	int		i;

	split = ft_split(game->text.c, ',');
	size = ft_tab_len(split);
	i = -1;
	if (size != 3)
	{
		ft_error(9);
		exit(EXIT_FAILURE);
	}
	while (split[++i])
	{
		if (!ft_strisdigit(split[i]))
		{
			ft_error(9);
			exit(EXIT_FAILURE);
		}
	}
	ft_freedouble(split);
	ft_check_int_f(game);
}

void	ft_check_param_rgb(t_game *game)
{
	char	**split;
	int		size;
	int		i;

	split = ft_split(game->text.f, ',');
	size = ft_tab_len(split);
	i = -1;
	if (size != 3)
	{
		ft_error(9);
		exit(EXIT_FAILURE);
	}
	while (split[++i])
	{
		if (!ft_strisdigit(split[i]))
		{
			ft_error(9);
			exit(EXIT_FAILURE);
		}
	}
	ft_freedouble(split);
	ft_check_c(game);
}

void	ft_check_rgb_floor(t_game *game)
{
	int	i;

	i = -1;
	while (game->text.f[++i])
	{
		if (ft_count_char(game->text.f, ',') != 2)
		{
			ft_error(9);
			exit(EXIT_FAILURE);
		}
	}
	ft_check_rgb_sky(game);
	ft_check_param_rgb(game);
}
