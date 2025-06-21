/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:41:31 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/20 21:58:10 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void	ft_scroll(t_all *all, int pos)
{
	SDL_Rect *tmp;
	
	tmp = find_rect(all->rect, "exit_bar");
	tmp->y += pos;
	tmp = find_rect(all->rect, "play_bar");
	tmp->y += pos;
	tmp = find_rect(all->rect, "save_bar");
	tmp->y += pos;
	tmp = find_rect(all->rect, "settings_bar");
	tmp->y += pos;
	tmp = find_rect(all->rect, "title_menu");
	tmp->y += pos;
	tmp = find_rect(all->rect, "text_exit");
	tmp->y += pos;
	tmp = find_rect(all->rect, "text_save");
	tmp->y += pos;
	tmp = find_rect(all->rect, "text_play");
	tmp->y += pos;
	tmp = find_rect(all->rect, "text_settings");
	tmp->y += pos;
	tmp = find_rect(all->rect, "cochon");
	tmp->y += pos;
}

void	menu_loop_event(t_all *all)
{
	int mouse = 0;
	int	mouse_x = 0;
	int mouse_y = 0;
	int width;
    int height;
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		mouse_x = event.button.x;
		mouse_y = event.button.y;
		if (event.type == SDL_QUIT)
			all->status = STOP;
		if (isButtonClicked(*find_rect(all->rect, "settings_theme"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 1;
		else if (isButtonClicked(*find_rect(all->rect, "theme_dark"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 2;
		else if (isButtonClicked(*find_rect(all->rect, "theme_default"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 3;
		else if (isButtonClicked(*find_rect(all->rect, "theme_troll_btn"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 4;
		else if (isButtonClicked(*find_rect(all->rect, "theme_dog_btn"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 5;
		else if (isButtonClicked(*find_rect(all->rect, "theme_sky_btn"), mouse_x, mouse_y))
			all->btn_menu.settings_btn = 6;
		else
			all->btn_menu.settings_btn = 0;
		if (event.type == SDL_MOUSEWHEEL)
		{
			if (event.wheel.y < 0)
			{
				all->btn_menu.scroll -= all->btn_menu.scrollspeed;
				if (all->btn_menu.scroll <= -1080)
				{
					all->btn_menu.scroll = -1080;
				}
				else
					ft_scroll(all, -all->btn_menu.scrollspeed);
			}
			else if (event.wheel.y > 0)
			{
				all->btn_menu.scroll += all->btn_menu.scrollspeed;
				if (all->btn_menu.scroll > 0)
				{
					all->btn_menu.scroll = 0;
				}
				else
					ft_scroll(all, all->btn_menu.scrollspeed);
			}
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE && all->menu == NONE)
				all->status = STOP;
			if (event.key.keysym.sym == SDLK_ESCAPE && all->menu == SETTINGS_BTN)
			{
				all->menu_theme = 0;
				all->menu  = NONE;
			}
			if (event.key.keysym.sym == SDLK_ESCAPE && all->menu == SAVE_BTN)
				all->menu = NONE;
		}
		if (event.type == SDL_WINDOWEVENT)
		{
        	if (event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
            	width = event.window.data1;
            	height = event.window.data2;
				SDL_GetWindowSize(all->window, &width, &height);
				new_size_texture(all, width, height);
				menu_loop_load_texture(all);
			}
        }
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
            if (event.button.button == SDL_BUTTON_LEFT)
			{
                if (!mouse) 
				{
					if (all->menu == NONE)
					{
						if (isButtonClicked(*find_rect(all->rect, "text_play"), mouse_x, mouse_y))
						{
							Mix_PlayChannel(-1, all->click, 0);
							all->status_btn_down = 1;
							all->alpha = 255;
							init_rect_for_texture_level1(all);
							init_texture_level1(all);
							SDL_GetWindowSize(all->window, &width, &height);
							new_size_texture(all, width, height);
						}
						if (isButtonClicked(*find_rect(all->rect, "text_settings"), mouse_x, mouse_y))
						{
							Mix_PlayChannel(-1, all->click, 0);
							all->alpha = 255;
							all->status_btn_down = 2;
						}
						if (isButtonClicked(*find_rect(all->rect, "text_save"), mouse_x, mouse_y))
						{
							Mix_PlayChannel(-1, all->click, 0);
							all->alpha = 255;
							all->status_btn_down = 3;
						}
						if (isButtonClicked(*find_rect(all->rect, "text_exit"), mouse_x, mouse_y))
						{
							Mix_PlayChannel(-1, all->click, 0);
							all->alpha = 255;
							all->status_btn_down = 4;
						}
					}
				}
				if (all->menu == SETTINGS_BTN && all->menu_theme == 0)
				{
					if (isButtonClicked(*find_rect(all->rect, "settings_theme"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						all->menu_theme = 1;
						all->btn_menu.settings_btn = 1;
						all->status_btn_down = 5;
					}
				}
				if (all->menu == SETTINGS_BTN)
				{
					if (isButtonClicked(*find_rect(all->rect, "settings_music"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						all->menu_theme = 0;
						all->btn_menu.settings_btn = 2;
						all->status_btn_down = 11;
					}
				}
				if (all->menu_theme == 1 && all->menu == SETTINGS_BTN)
				{
					if (isButtonClicked(*find_rect(all->rect, "theme_default"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						all->param_theme = 0;
						all->btn_menu.bar_theme = "menu_bar";
						all->btn_menu.bar_theme_down = "menu_bar_down";
						all->status_btn_down = 6;
					}
					if (isButtonClicked(*find_rect(all->rect, "theme_dark"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						all->param_theme = 1;
						all->btn_menu.bar_theme = "btn_dark";
						all->btn_menu.bar_theme_down = "btn_dark_down";
						all->status_btn_down = 7;
					}
					if (isButtonClicked(*find_rect(all->rect, "theme_sky_btn"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						all->param_theme = 2;
						all->btn_menu.bar_theme = "btn_sky";
						all->btn_menu.bar_theme_down = "btn_sky_down";
						all->status_btn_down = 8;
					}
					if (isButtonClicked(*find_rect(all->rect, "theme_troll_btn"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						all->param_theme = 3;
						all->btn_menu.bar_theme = "btn_troll";
						all->btn_menu.bar_theme_down = "btn_troll_down";
						all->status_btn_down = 9;
					}
					if (isButtonClicked(*find_rect(all->rect, "theme_dog_btn"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						all->param_theme = 4;
						all->btn_menu.bar_theme = "btn_dog";
						all->btn_menu.bar_theme_down = "btn_dog_down";
						all->status_btn_down = 10;
					}
				}
			}
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{
            if (event.button.button == SDL_BUTTON_LEFT)
			{
               mouse = 0;
    	    }
		}
		if (isButtonClicked(*find_rect(all->rect, "text_play"), mouse_x, mouse_y))
			all->status_btn = 1;
		else if (isButtonClicked(*find_rect(all->rect, "text_settings"), mouse_x, mouse_y))
			all->status_btn = 2;
		else if (isButtonClicked(*find_rect(all->rect, "text_save"), mouse_x, mouse_y))
			all->status_btn = 3;
		else if (isButtonClicked(*find_rect(all->rect, "text_exit"), mouse_x, mouse_y))
			all->status_btn = 4;
		else
			all->status_btn = 0;
	}
}