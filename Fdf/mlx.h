/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeller-@student.42sp.org.br <ekeller-@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:09:51 by ekeller-@st       #+#    #+#             */
/*   Updated: 2025/03/20 11:55:16 by ekeller-@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx.h for MinilibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Mon Jul 31 16:37:50 2000 Charlie Root
** Last update Tue May 15 16:23:28 2007 Olivier Crouzet
*/

/*
**   MinilibX -  Please report bugs
*/

/*
** FR msg - FR msg - FR msg
**
** La MinilibX utilise 2 librairies supplementaires qu'il
**      est necessaire de rajouter a la compilation :
**   -lmlx -lXext -lX11
**
** La MinilibX permet le chargement des images de type Xpm.
** Notez que cette implementation est incomplete.
** Merci de communiquer tout probleme de chargement d'image
** de ce type.
*/

#ifndef MLX_H

# define MLX_H

void	*mlx_init(void);
/*
**  needed before everything else.
**  return (void *)0 if failed
*/

/*
** Basic actions
*/

void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
/*
**  return void *0 if failed
*/
int		mlx_clear_window(void *mlx_ptr, void *win_ptr);

/*
**  origin for x & y is top left corner of the window
**  y down is positive
**  color is 0x00RRGGBB
*/

/*int		mlx_loop (void *mlx_ptr);
** Image stuff
*/

void	*mlx_new_image(void *mlx_ptr, int width, int height);
/*
**  return void *0 if failed
**  obsolete : image2 data is stored using bit planes
**  void	*mlx_new_image2(void *mlx_ptr,int width,int height);
*/
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			int *size_line, int *endian);
/*
**  endian : 0 = sever X is little endian, 1 = big endian
**  for mlx_new_image2, 2nd arg of mlx_get_data_addr is number_of_planes
*/
int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
			int x, int y);
int		mlx_loop(void *mlx_ptr);
/*
** dealing with Events
*/

int		mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
int		mlx_loop(void *mlx_ptr);

int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int		mlx_destroy_image(void *mlx_ptr, void *img_ptr);

int		mlx_destroy_display(void *mlx_ptr);

/*
**  generic hook system for all events, and minilibX functions that
**    can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int		mlx_hook(void *win_ptr, int x_event, int x_mask,
			int (*funct)(), void *param);

#endif /* MLX_H */
