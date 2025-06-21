/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:54:05 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/22 00:30:52 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
# include <SDL_ttf.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
#include <math.h>
#include <stdbool.h>
# include "struct.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define THEME_DEFAUT_R 133
# define THEME_DEFAUT_G 103
# define THEME_DEFAUT_B 247

# define THEME_DARK_R 67
# define THEME_DARK_G 10
# define THEME_DARK_B 100

#define SCREEN_W 800
#define SCREEN_H 600
#define BOT_SPEED 200         // pixels par seconde
#define ATTAQUE_DIST 100      // distance d’attaque en pixels

#define MAX_BOTS      100     // nombre max de bots
#define SPAWN_INTERVAL 5.0f
#define SPEED_ATTACK 1.0f
#define BOT_RADIUS 32.0f 


int 	isButtonClicked(SDL_Rect  rect, int mouseX, int mouseY);
void	process_screen(t_all *all, t_status_render status);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_lstadd_back_rect(t_rect **lst, t_rect *new);
t_rect	*ft_lstnew_rect(int x, int y , int h, int w, char *name);


void	ft_lstadd_back_texture(t_texture **lst, t_texture *new);
t_texture	*ft_lstnew_texture(SDL_Texture *texture, char *name);


SDL_Texture	*LoadTexture(const char *file, SDL_Renderer *renderer);
SDL_Texture	*find_texture(t_texture *texture, char *name);
SDL_Rect	*find_rect(t_rect *rect, char *name);


void	deleteNode(t_rect** lst, char *name);
void	ft_free_textures(t_texture *textures);
void	ft_free_rec(t_rect *rectangles);

void	init_rect_for_texture(t_all *all);
void	init_texture(t_all *all);


TTF_Font	*init_text(SDL_Renderer *renderer, SDL_Window *window);
void	create_text(TTF_Font *font, SDL_Renderer *renderer, SDL_Window *window, char *text, int pos_x, int pos_y);

void	load_screen_loop(t_all *all, int *offset);

void	init_texture_menu(t_all *all);
void	init_rect_for_texture_menu(t_all *all);

void	menu_loop(t_all *all);
void	menu_loop_event(t_all *all);

void	init_rect_for_texture_level1(t_all *all);
void	init_texture_level1(t_all *all);

void	level1_loop(t_all *all);

void	ft_lstadd_back_rectA(t_rectA **lst, t_rectA *new);
t_rectA	*ft_lstnew_rectA(int x, int y , int h, int w, float vx, float vy, char *name);

void	new_size_texture(t_all *all, int width, int height);
void	menu_loop_load_texture(t_all *all);
int    animation_btn(t_all *all, int status_btn, char *name_rect);
void    menu_settings(t_all *all);
void    menu_all(t_all *all);
void    menu_theme_bg(t_all *all);
int    animation_btn_settings(t_all *all, int status_btn, char *name_rect);

#endif