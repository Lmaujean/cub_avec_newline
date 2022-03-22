/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:49:37 by lmaujean          #+#    #+#             */
/*   Updated: 2022/02/28 10:49:40 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx_utils/header/mlx_utils.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# ifdef __linux__
#  include "../mlx_linux/mlx.h"
# elif __APPLE__
#  include <mlx.h>
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/******* STRUCTURE POSITION *******/

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

/******* STRUCTURE COULEUR *******/

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

/******* STRUCTURE TEXTURE *******/

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}				t_texture;

typedef struct s_param
{
	int		exist;
	char	*value;
}	t_param;

typedef struct s_check
{
	t_param		no;
	t_param		so;
	t_param		we;
	t_param		ea;
	t_param		f;
	t_param		c;
}	t_check;

/******* STRUCTURE GLOBAL DU JEU *******/

typedef struct s_game
{
	char		**map;
	char		*texture[6];
	t_texture	text;
	t_pos		tex;
	t_pos		line;
}				t_game;

/******* GNL *******/

char	*ft_strdup(const char *src);
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	free_save(char **save);
int		get_line(char **line, char **save);
int		return_l(char **line, char **save, int byte_lu);
char	*ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);

/******* PARSING *******/

int		ft_valid_fd(char *str, int ac);
void	ft_valid_file(char *str);
char	**ft_get_file(int fd, const char *str);
void	check_text(int fd, t_game *game);
void	ft_get_param(int fd, char *str, t_game *game);
int		ft_check_param_file(char *str);
int		ft_comp_str(char *str, char *str2);
void	ft_one_position(t_game *game);
void	ft_check_nbr_carac(t_game *game);
void	ft_check_carac_map(t_game *game);
void	ft_check_first_line(t_game *game);
void	ft_check_last_line(t_game *game);
void	ft_check_first_carac(t_game *game);
void	ft_check_rgb_floor(t_game *game);
void	add_in_text(t_game *game, char *str);
void	ft_check_int_f(t_game *game);
void	valid_path_texture(char *str);
char	**ft_get_map(int fd, const char *str, t_game *game);

/******* UTILS *******/

int		ft_error(int c);
int		ft_strlen(const char *str);
int		ft_check_ext(const char *file, const char *ext);
void	print_map(char **tab);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	print_text(t_game *game);
char	**ft_split(char const *s, char c);
int		ft_tab_len(char **tab);
int		ft_strcomp(const char *s1, char *s2);
char	*ft_str_nospace(char *str);
int		len_str_with_space(char *str);
void	init_check(t_check *check);
char	*ft_strtrim(char *s1, char *set);
void	ft_freedouble(char **ptr);
void	init_carac(t_game *game);
int		ft_count_char(char *str, char c);
void	ft_free_texture(t_texture *text);
int		ft_strisdigit(char *str);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t count, size_t size);
int		count_line(int fd, char *str);
void	ft_save_text(t_game *game, char **file);

#endif
