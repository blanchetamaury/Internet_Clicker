/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:53:07 by mlahonta          #+#    #+#             */
/*   Updated: 2025/06/22 00:53:09 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum __attribute__((__packed__)) e_status
{
	RUNNING,
	STOP
}	t_status;

typedef enum __attribute__((__packed__)) e_statusbtn
{
	PLAY_BTN_UP,
	PLAY_BTN_DOWN,
	PLAY_DESTROY
}	t_status_btn;

typedef enum __attribute__((__packed__)) e_status_menu
{
	NONE,
	PLAY_BTN,
	SETTINGS_BTN,
	SAVE_BTN,
	EXIT_BTN,
}	t_status_menu;

typedef enum __attribute__((__packed__)) e_statusrender
{
	LOAD_SCREEN,
	MAIN_SCREEN,
	EDGE_SCREEN,
	CHROME_SCREEN,
	OPERA_SCREEN,
	OPERAGX_SCREEN,
	TRANSI,
	TRANSI_REVERS,
	ERR
}	t_status_render;

typedef struct s_texture
{
	char				*name;
	SDL_Texture			*texture;
	struct s_texture	*next;
}		t_texture;

typedef struct s_rect
{
	char				*name;
	SDL_Rect			rect;
	SDL_Rect			origine;
	struct s_rect		*next;
}		t_rect;

typedef struct s_rectA
{
	char				*name;
	SDL_Rect			rect;
	int					alpha;
	float				x, y;
    float				vx, vy;
    int					w, h;   
	struct s_rectA		*next;
}		t_rectA;

typedef	struct s_btn_lvl1
{
	int		shop_btn_1;

} t_btn_lvl1;

typedef struct s_btn_menu
{
	int		settings_btn;
	int		scroll;
	int		scrollspeed;
	char	*bar_theme;
	char	*bar_theme_down;
}	t_btn_menu;

typedef struct {
    float x, y;      // position
    float vx, vy;    // vitesse (unitaires ou à l’échelle de BOT_SPEED)
    bool attacking;
	Uint64 attack_start;
} Bot;

typedef struct s_all
{
	t_rect				*rect;
	t_texture			*texture;
	t_status			status;
	t_status_btn		button;
	t_status_menu		menu;
	t_status_render		render;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	Mix_Chunk			*click;
	TTF_Font			*counter;
	SDL_Color			counter_color;
	SDL_Texture			*counter_texture;
	t_btn_lvl1			btn_lvl1;
	t_btn_menu			btn_menu;
	int					tmp;
	int					alpha;
	int					status_btn;
	int					window_x;
	int					window_y;
	int					nb_count;
	int					param_theme;
	int					menu_theme;
	int 				lvl1_box_shop;
	int					mouse_power;
	int					status_btn_down;
	int					count_time_btn;
	Bot					bot;
	float				dt;
	t_rectA				*clicker_rec;
}		t_all;

#endif
