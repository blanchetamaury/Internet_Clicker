/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rect_for_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:12:59 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/22 00:30:12 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDE/graph.h"

void	init_rect_for_texture(t_all *all)
{
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 1920, 1080, "loading"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(469, 487, 300, 210, "cat_left"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1147, 487, 300, 210, "cat_right"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 87, 11, "loading_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(253, 771, 182, 206, "meme"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(714, 914, 157, 157, "meme1"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1598, 565, 253, 184, "meme2"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1214, 791, 186, 245, "meme3"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(80, 69, 201, 485, "meme4"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1215, 97, 338, 230, "meme5"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(492, 97, 277, 252, "meme6"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(890, 950, 160, 46, "play"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(730, 414, 572, 252, "title"));
}

void	init_texture(t_all *all)
{
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/cat_left.png", all->renderer), "cat_left"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/cat_right.png", all->renderer), "cat_right"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/loading_bar.png", all->renderer), "loading_bar"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme.png", all->renderer), "meme"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme1.png", all->renderer), "meme1"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme2.png", all->renderer), "meme2"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme3.png", all->renderer), "meme3"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme4.png", all->renderer), "meme4"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme5.png", all->renderer), "meme5"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/meme6.png", all->renderer), "meme6"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/play.png", all->renderer), "play"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LOADING/tilte.png", all->renderer), "title"));
}

void	init_rect_for_texture_menu(t_all *all)
{
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(726, 856, 470, 120, "exit_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(880, 866, 162, 90, "text_exit"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(740, 414, 442, 120, "play_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(869, 424, 182, 90, "text_play"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(715, 705, 490, 120, "save_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(869, 715, 184, 90, "text_save"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(547, 560, 826, 120, "settings_bar"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(787, 570, 346, 90, "text_settings"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(597, 11, 728, 309, "title_menu"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(-125, 1820, 2252, 408, "cochon"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(20, 20, 50, 50, "return"));
	//settings
		//bar
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(40, 100, 826, 105, "settings_theme"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1050, 100, 826, 105, "theme_default"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1050, 300, 826, 105, "theme_dark"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1050, 500, 826, 105, "theme_sky_btn"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 1920, 1080, "theme_troll"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 1920, 1080, "theme_dog"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1050, 700, 826, 105, "theme_troll_btn"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1050, 900, 826, 105, "theme_dog_btn"));

	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(40, 300, 826, 105, "settings_music"));
		//text
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(366, 133, 174, 39, "settings_theme_text"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1355, 133, 217, 39, "theme_default_text"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1395, 333, 137, 39, "theme_dark_text"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1297, 533, 333, 39, "theme_sky_btn_text"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1269, 733, 388, 39, "theme_troll_btn_text"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1297, 933, 333, 39, "theme_dog_btn_text"));

	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(366, 333, 159, 39, "settings_music_text"));
	//save
}

void	init_texture_menu(t_all *all)
{
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/cochon.png", all->renderer), "cochon"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/return.png", all->renderer), "return"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/menu_bar.png", all->renderer), "menu_bar"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "menu_bar"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/menu_bar_down.png", all->renderer), "menu_bar_down"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "menu_bar_down"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/btn_sky.png", all->renderer), "btn_sky"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "btn_sky"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/btn_sky_down.png", all->renderer), "btn_sky_down"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "btn_sky_down"), SDL_BLENDMODE_BLEND);

	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/btn_troll.png", all->renderer), "btn_troll"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "btn_troll"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/btn_troll_down.png", all->renderer), "btn_troll_down"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "btn_troll_down"), SDL_BLENDMODE_BLEND);

	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/btn_dog.png", all->renderer), "btn_dog"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "btn_dog"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/btn_dog_down.png", all->renderer), "btn_dog_down"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "btn_dog_down"), SDL_BLENDMODE_BLEND);

	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/btn_dark.png", all->renderer), "btn_dark"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "btn_dark"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/btn_dark_down.png", all->renderer), "btn_dark_down"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "btn_dark_down"), SDL_BLENDMODE_BLEND);
	
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/title.png", all->renderer), "title_menu"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "title_menu"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/title_sky.png", all->renderer), "title_menu_sky"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "title_menu_sky"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/title_troll.png", all->renderer), "title_menu_troll"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "title_menu_troll"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/title_dog.png", all->renderer), "title_menu_dog"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "title_menu_dog"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/text_exit.png", all->renderer), "text_exit"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "text_exit"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/text_exit_white.png", all->renderer), "text_exit_white"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "text_exit_white"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/text_save.png", all->renderer), "text_save"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "text_save"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/text_save_white.png", all->renderer), "text_save_white"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "text_save_white"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/text_play.png", all->renderer), "text_play"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "text_play"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/text_play_white.png", all->renderer), "text_play_white"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "text_play_white"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/text_settings.png", all->renderer), "text_settings"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "text_settings"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/text_settings_white.png", all->renderer), "text_settings_white"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "text_settings_white"), SDL_BLENDMODE_BLEND);
	//settings
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/settings_theme.png", all->renderer), "settings_theme"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/settings_theme_white.png", all->renderer), "settings_theme_white"));

	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/settings_music.png", all->renderer), "settings_music"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/settings_music_white.png", all->renderer), "settings_music_white"));
	
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_dark.png", all->renderer), "theme_dark"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_dark_white.png", all->renderer), "theme_dark_white"));
	
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_default.png", all->renderer), "theme_default"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_default_white.png", all->renderer), "theme_default_white"));
	
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_troll_btn.png", all->renderer), "theme_troll_btn"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_troll_btn_white.png", all->renderer), "theme_troll_btn_white"));
	
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_dog_btn.png", all->renderer), "theme_dog_btn"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_dog_btn_white.png", all->renderer), "theme_dog_btn_white"));

	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_sky_btn.png", all->renderer), "theme_sky_btn"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_sky_btn_white.png", all->renderer), "theme_sky_btn_white"));
	
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/theme_sky.png", all->renderer), "theme_sky"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/troll_wallpaper.png", all->renderer), "theme_troll"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/MENU/SETTINGS/dog_wallpaper.png", all->renderer), "theme_dog"));
	//save
}

void	init_rect_for_texture_level1(t_all *all)
{
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(0, 0, 1920, 1080, "bg_level1"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(659, 239, 602, 602, "logo_level1"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1100, 120, 700, 824, "shop_box"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(400, 970, 100, 100, "shop_lvl1"));
	ft_lstadd_back_rect(&all->rect, ft_lstnew_rect(1142, 219, 308, 70, "shop_btn"));
}

void	init_texture_level1(t_all *all)
{
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LEVEL_1/bg.png", all->renderer), "bg_level1"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LEVEL_1/shop_lvl1.png", all->renderer), "shop_lvl1"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LEVEL_1/shop_box.png", all->renderer), "shop_box"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LEVEL_1/shop_btn.png", all->renderer), "shop_btn"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LEVEL_1/logo.png", all->renderer), "logo_fond_level1"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LEVEL_1/logo.png", all->renderer), "logo_level1"));
	SDL_SetTextureBlendMode(find_texture(all->texture, "logo_level1"), SDL_BLENDMODE_BLEND);
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LEVEL_1/zombie.png", all->renderer), "zombie"));
	ft_lstadd_back_texture(&all->texture, ft_lstnew_texture(LoadTexture("GAME/TEXTURE/IMAGE/LEVEL_1/zombie_open.png", all->renderer), "zombie_open"));
}

void	new_size_texture(t_all *all, int width, int height)
{
	t_rect *tmp;
	
	tmp = all->rect;
	if (height > 480 || width > 680)
	{
		while (tmp)
		{
			if (height > 480)
			{
				tmp->rect.y = tmp->origine.y * (100 * height / all->window_y) / 100;
				tmp->rect.h = tmp->origine.h * (100 * height / all->window_y) / 100;
			}
			if (width > 680)
			{
				tmp->rect.x = tmp->origine.x * (100 * width / all->window_x) / 100;
				tmp->rect.w = tmp->origine.w * (100 * width / all->window_x) / 100;
			}
			tmp = tmp->next;
		}
	}
}
