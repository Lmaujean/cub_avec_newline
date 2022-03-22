/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:38:55 by lmaujean          #+#    #+#             */
/*   Updated: 2022/03/11 10:38:59 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_valid_fd(char *str, int ac)
{
	int	fd;

	if (ac != 2)
	{
		ft_error(1);
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		ft_error(2);
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_error(3);
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_valid_file(char *str)
{
	if (!ft_check_ext(str, ".cub"))
	{
		ft_error(4);
		exit(EXIT_FAILURE);
	}
}

int	ft_first_line_of_map(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (str[++i])
	{
		if (str[i] != '1' && str[i] != ' ')
			j = 0;
	}
	return (j);
}

char	**ft_get_map(int fd, const char *str, t_game *game)
{
	char	*line;
	int		i;
	int		ret;
	int		y;
	int		j;

	line = NULL;
	j = 1;
	fd = open(str, O_RDONLY);
	y = count_line(fd, line);
	close(fd);
	game->map = malloc(sizeof(char *) * (y + 1));
	fd = open(str, O_RDONLY);
	i = 0;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (j == 1)
		{
			if (ft_first_line_of_map(line))
			{
				game->map[i++] = ft_strdup(line);
				j = 0;
			}
		}
		else
			game->map[i++] = ft_strdup(line);
		free(line);
	}
	game->map[i] = NULL;
	close(fd);
	return (game->map);
}

char	**ft_get_file(int fd, const char *str)
{
	char	**param;
	char	*line;
	int		i;
	int		ret;
	int		y;

	line = NULL;
	fd = open(str, O_RDONLY);
	y = count_line(fd, line);
	close(fd);
	param = malloc(sizeof(char *) * (y + 1));
	fd = open(str, O_RDONLY);
	i = 0;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (*line)
		{
			if ((ft_first_line_of_map(line)))
				break ;
			param[i++] = ft_strdup(line);
		}
		free(line);
	}
	param[i] = NULL;
	//print_map(param);
	close(fd);
	return (param);
}

int	ft_comp_str(char *str, char *str2)
{
	int	i;
	int	size;

	size = 0;
	size = ft_strlen(str2);
	i = 0;
	while (i < size)
	{
		if (str[i] != str2[i])
			return (0);
		else
			i++;
	}
	return (1);
}

int	ft_check_param_file(char *str)
{
	if ((ft_comp_str(str, "NO "))
		|| (ft_comp_str(str, "SO "))
		|| (ft_comp_str(str, "WE "))
		|| (ft_comp_str(str, "EA "))
		|| (ft_comp_str(str, "F "))
		|| (ft_comp_str(str, "C ")))
		return (1);
	return (0);
}
