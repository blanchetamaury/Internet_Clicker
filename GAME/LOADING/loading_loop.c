/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:23:33 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/20 21:48:25 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void	loading_loop_event(t_all *all)
{
	int mouse = 0;
	int	mouse_x = 0;
	int mouse_y = 0;
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			all->status = STOP;
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				all->status = STOP;
		}
		if (event.type == SDL_WINDOWEVENT)
		{
        	if (event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
            	int width = event.window.data1;
            	int height = event.window.data2;
				SDL_GetWindowSize(all->window, &width, &height);
				new_size_texture(all, width, height);
				SDL_RenderClear(all->renderer);
				process_screen(all, all->render);
			}
        }
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
            if (event.button.button == SDL_BUTTON_LEFT)
			{
                if (!mouse) 
				{
					mouse_x = event.button.x;
					mouse_y = event.button.y;
					if (all->render != MAIN_SCREEN && all->button != PLAY_DESTROY && isButtonClicked(*find_rect(all->rect, "play"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						all->button = PLAY_BTN_DOWN;
						all->menu = NONE;
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
	}
}

static int16_t	ft_update_pos(t_all *all, int offset)
{
	SDL_Rect		*tmp;

	tmp = find_rect(all->rect, "play");
	tmp->y += offset;
	tmp = find_rect(all->rect, "meme");
	tmp->x -= offset;
	tmp->y += offset;
	tmp = find_rect(all->rect, "meme1");
	tmp->x -= offset;
	tmp->y += offset;
	tmp = find_rect(all->rect, "meme2");
	tmp->x += offset;
	tmp = find_rect(all->rect, "meme3");
	tmp->x += offset;
	tmp->y += offset;
	tmp = find_rect(all->rect, "meme4");
	tmp->x -= offset;
	tmp->y -= offset;
	tmp = find_rect(all->rect, "meme5");
	tmp->x += offset;
	tmp->y -= offset;
	tmp = find_rect(all->rect, "meme6");
	tmp->x -= offset;
	tmp->y -= offset;
	tmp = find_rect(all->rect, "cat_left");
	tmp->x -= offset;
	tmp = find_rect(all->rect, "cat_right");
	tmp->x += offset;
	tmp = find_rect(all->rect, "title");
	tmp->y -= offset;
	return (tmp->y);
}

void	load_screen_loop(t_all *all, int *offset)
{
	loading_loop_event(all);
	SDL_RenderClear(all->renderer);
	if ((all->button == PLAY_BTN_DOWN) && all->render == LOAD_SCREEN)
	{
		if (all->button != PLAY_DESTROY && ft_update_pos(all, *offset) <= -1000)
		{
			deleteNode(&all->rect, "title");
			deleteNode(&all->rect, "play");
			deleteNode(&all->rect, "meme");
			deleteNode(&all->rect, "meme1");
			deleteNode(&all->rect, "meme2");
			deleteNode(&all->rect, "meme3");
			deleteNode(&all->rect, "meme4");
			deleteNode(&all->rect, "meme5");
			deleteNode(&all->rect, "meme6");
			deleteNode(&all->rect, "cat_left");
			deleteNode(&all->rect, "cat_right");
			init_texture_menu(all);
			init_rect_for_texture_menu(all);
			int width;
            int height;
			SDL_GetWindowSize(all->window, &width, &height);
			new_size_texture(all, width, height);
			all->button = PLAY_DESTROY;
		}
		if (*offset < 10)
			(*offset)++;
		*offset += 2;
	}
	process_screen(all, all->render);
}

