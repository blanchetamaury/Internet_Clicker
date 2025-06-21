/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 15:37:26 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/20 22:02:01 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDE/graph.h"

void    menu_settings(t_all *all)
{
    if (all->menu == SETTINGS_BTN)
	{
        SDL_RenderCopy(all->renderer, find_texture(all->texture, "return"), NULL, find_rect(all->rect, "return"));
		if (all->btn_menu.settings_btn == 1)
        {
            if (animation_btn_settings(all, 5, "settings_theme") == 0)
                SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "settings_theme"));
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "settings_theme_white"), NULL, find_rect(all->rect, "settings_theme_text"));
        }
		else
        {
            if (animation_btn_settings(all, 5, "settings_theme") == 0)
                SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "settings_theme"));
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "settings_theme"), NULL, find_rect(all->rect, "settings_theme_text"));
        }
        if (all->btn_menu.settings_btn == 2)
        {
            if (animation_btn_settings(all, 5, "settings_music") == 0)
                SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "settings_music"));
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "settings_music_white"), NULL, find_rect(all->rect, "settings_music_text"));
        }
		else
        {
            if (animation_btn_settings(all, 5, "settings_music") == 0)
                SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "settings_music"));
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "settings_music"), NULL, find_rect(all->rect, "settings_music_text"));
        }
		if (all->menu_theme == 1)
		{
			if (all->btn_menu.settings_btn == 2)
            {
                if (animation_btn_settings(all, 7, "theme_dark") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_dark"));
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_dark_white"), NULL, find_rect(all->rect, "theme_dark_text"));
            }
			else
            {
                if (animation_btn_settings(all, 7, "theme_dark") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_dark"));
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_dark"), NULL, find_rect(all->rect, "theme_dark_text"));
            }
			if (all->btn_menu.settings_btn == 3)
			{
                if (animation_btn_settings(all, 6, "theme_default") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_default"));
                SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_default_white"), NULL, find_rect(all->rect, "theme_default_text"));
            }
			else
            {
                if (animation_btn_settings(all, 6, "theme_default") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_default"));
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_default"), NULL, find_rect(all->rect, "theme_default_text"));
            }
			if (all->btn_menu.settings_btn == 4)
			{
                if (animation_btn_settings(all, 9, "theme_troll_btn") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_troll_btn"));
                SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_troll_btn_white"), NULL, find_rect(all->rect, "theme_troll_btn_text"));
            }	
			else
			{
                if (animation_btn_settings(all, 9, "theme_troll_btn") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_troll_btn"));
                SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_troll_btn"), NULL, find_rect(all->rect, "theme_troll_btn_text"));
            }	
			if (all->btn_menu.settings_btn == 5)
			{
                if (animation_btn_settings(all, 10, "theme_dog_btn") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_dog_btn"));
                SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_dog_btn_white"), NULL, find_rect(all->rect, "theme_dog_btn_text"));
            }
			else
            {
                if (animation_btn_settings(all, 10, "theme_dog_btn") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_dog_btn"));
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_dog_btn"), NULL, find_rect(all->rect, "theme_dog_btn_text"));
            }
			if (all->btn_menu.settings_btn == 6)
			{
                if (animation_btn_settings(all, 8, "theme_sky_btn") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_sky_btn"));
                SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_sky_btn_white"), NULL, find_rect(all->rect, "theme_sky_btn_text"));
            }
			else
            {
                if (animation_btn_settings(all, 8, "theme_sky_btn") == 0)
                    SDL_RenderCopy(all->renderer, find_texture(all->texture, all->btn_menu.bar_theme), NULL, find_rect(all->rect, "theme_sky_btn"));
				SDL_RenderCopy(all->renderer, find_texture(all->texture, "theme_sky_btn"), NULL, find_rect(all->rect, "theme_sky_btn_text"));
            }
		}
	}
}
