/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:08:46 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/21 20:26:32 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "INCLUDE/graph.h"

int isButtonClicked(SDL_Rect  rect, int mouseX, int mouseY)
{
    return mouseX >= rect.x && mouseX <= rect.x + rect.w &&
           mouseY >= rect.y && mouseY <= rect.y + rect.h;
}

static uint8_t	init_vars(t_all *all)
{
	all->rect = 0;
	all->alpha = 0;
	all->status_btn = -1;
	all->tmp = SCREEN_HEIGHT / 2;
	all->texture = 0;
	all->status = RUNNING;
	all->button = PLAY_BTN_UP;
	all->render = LOAD_SCREEN;
	all->menu = NONE;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		exit (1);
	if (TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur TTF_Init : %s\n", TTF_GetError());
		SDL_Quit();
		return (1);
	}
	all->window = SDL_CreateWindow("CLICKER Internet", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_HIDDEN | SDL_WINDOW_RESIZABLE);
	if (!all->window)
		exit(1);
	SDL_SetWindowMinimumSize(all->window, 680, 480);
	all->renderer = SDL_CreateRenderer(all->window, -1, SDL_RENDERER_ACCELERATED);
	if (!all->renderer)
		exit(1);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("Erreur Mix_OpenAudio: %s\n", Mix_GetError());
		return 1;
	}
	all->counter = TTF_OpenFont("FONT/ARCADECLASSIC.TTF", 36);
    if (!all->counter) {
        fprintf(stderr, "Erreur TTF_OpenFont: %s\n", TTF_GetError());
        SDL_DestroyRenderer(all->renderer);
        SDL_DestroyWindow(all->window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
	all->counter_color.a = 255;
	all->counter_color.b = 255;
	all->counter_color.g = 255;
	all->counter_color.r = 255;
	all->nb_count = 0;
	all->btn_menu.scroll = 0;
	all->btn_menu.scrollspeed = 20;
	all->counter_texture = NULL;
	all->btn_menu.bar_theme = "menu_bar";
	all->btn_menu.bar_theme_down = "menu_bar_down";
	return (0);
}

void		ft_init_btn(t_all *all)
{
	all->btn_lvl1.shop_btn_1 = 60;

	all->btn_menu.settings_btn = 0;
}

void drawOutsideCircle(SDL_Renderer *renderer, int a, int b, int r, SDL_Color outColor, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x - a;
            int dy = y - b;
            if (dx * dx + dy * dy > r * r) {
                SDL_SetRenderDrawColor(renderer, outColor.r, outColor.g, outColor.b, outColor.a);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }
}

void transition_reverse(t_all *all)
{
    static float count = 10.0f;
    int width = 0, height = 0;
    SDL_GetWindowSize(all->window, &width, &height);
    int diagonal = (int)sqrt(width * width + height * height); 
    SDL_Color outside = {0, 0, 0, 255};

    SDL_SetRenderDrawColor(all->renderer, 0, 0, 0, 255);
    SDL_RenderClear(all->renderer);
	level1_loop(all);
    if (count <= diagonal)
    {
        drawOutsideCircle(all->renderer, width / 2, height / 2, (int)count, outside, width, height);
        count = count * 1.04f + 4;
    }
    else
    {
        all->render = EDGE_SCREEN;
    }
}

void	transition(t_all *all)
{
    static float count = 0;
    int width = 0, height = 0;
    SDL_GetWindowSize(all->window, &width, &height);
    int diagonal = (int)sqrt(width * width + height * height); 
    SDL_Color outside = {0, 0, 0, 255};

    SDL_SetRenderDrawColor(all->renderer, 0, 0, 0, 255);
    SDL_RenderClear(all->renderer);
    if (count < diagonal)
    {
		menu_loop_load_texture(all);
        float rayon = diagonal - count; 
        drawOutsideCircle(all->renderer, width / 2, height / 2, (int)rayon, outside, width, height);
        count += 20;
    }
    else
    {
        count = 0;
        all->render = TRANSI_REVERS;
    }
}

void	main_loop(t_all	*all)
{
	Uint32			start_time;
	Uint32			frame_duration;
	int				offset;

	offset = 1;
	all->clicker_rec = NULL;
	Mix_Chunk* son1 = Mix_LoadWAV("GAME/MUSIQUE/menu.mp3");
	all->click = Mix_LoadWAV("GAME/MUSIQUE/click.mp3");
	SDL_Surface* surface = IMG_Load("UTILITAIRE/cursor.png");
	SDL_Cursor* cursor = SDL_CreateColorCursor(surface, 1, 1);
	SDL_SetCursor(cursor);
	SDL_FreeSurface(surface);
	if (!son1 || !all->click)
	{
        printf("Erreur de chargement du son: %s\n", Mix_GetError());
        return ;
    }
	Mix_PlayChannel(-1, son1, 0);
	SDL_ShowWindow(all->window);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	all->window_y = 1080;
	all->window_x = 1920;
	all->param_theme = 0;
	all->menu_theme = 0;
	all->lvl1_box_shop = 0;
	all->mouse_power = 1;
	all->status_btn_down = 0;
	all->count_time_btn = 0;
	ft_init_btn(all);
	Uint32 lastTicks = SDL_GetTicks();
	while (all->status == RUNNING)
	{
		start_time = SDL_GetTicks();
		Uint32 current = SDL_GetTicks();
        all->dt = (current - lastTicks) / 1000.0f;
        lastTicks = current;
		switch (all->render)
		{
			case LOAD_SCREEN:
				load_screen_loop(all, &offset);
				break ;
			case MAIN_SCREEN:
				menu_loop(all);
				break ;
			case EDGE_SCREEN:
				level1_loop(all);
				break ;
			case CHROME_SCREEN:
				break ;
			case OPERA_SCREEN:
				break ;
			case OPERAGX_SCREEN:
				break ;
			case TRANSI:
				transition(all);
				break;
			case TRANSI_REVERS:
				transition_reverse(all);
				break;
			case ERR:
				all->status = STOP;
				break ;
		}
		SDL_RenderPresent(all->renderer);
		frame_duration = SDL_GetTicks() - start_time;
		if (frame_duration < 1000 / 80)
			SDL_Delay((1000 / 80) - frame_duration);
	}
	SDL_FreeCursor(cursor);
	Mix_FreeChunk(son1);
	Mix_FreeChunk(all->click);
}

int	main(void)
{
	t_all			all;

	if (init_vars(&all))
		return (1);
	init_rect_for_texture(&all);
	init_texture(&all);
	main_loop(&all);
	ft_free_textures(all.texture);
	ft_free_rec(all.rect);
	SDL_DestroyRenderer(all.renderer);
	SDL_DestroyWindow(all.window);
	SDL_Quit();
}
