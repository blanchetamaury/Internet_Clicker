/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:49:00 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/22 01:14:09 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDE/graph.h"

Bot bots[MAX_BOTS];
int botCount = 0;

float spawnTimer = 0.0f; 

void bot_update(Bot *bot, int mouseX, int mouseY) {
    int dx    = mouseX - (int)bot->x;
    int dy    = mouseY - (int)bot->y;
    int dist2 = dx*dx + dy*dy;
    int seuil2= ATTAQUE_DIST * ATTAQUE_DIST;

    if (dist2 < seuil2) {
        if (bot->attacking == 0) {
            bot->attacking    = true;
            bot->attack_start = SDL_GetTicks64();  // ==> mémorise T0 en ms
        }
        // on ne bouge plus pendant l’attaque
    } else {
        bot->attacking = false;
        // remise à zéro de l’instant (optionnel, pour éviter une relecture)
        bot->attack_start = 0;
    }
}


void bot_render(Bot *bot, t_all *all) {
    SDL_Rect r = {
        .x = (int)bot->x - 16,
        .y = (int)bot->y - 16,
        .w = 83, .h = 95
    };

    if (bot->attacking) {
        // temps écoulé depuis le début de l’attaque, en secondes float
        float elapsed = (SDL_GetTicks64() - bot->attack_start) / 1000.0f;

        printf("elapsed = %f | bot = %ld | soutraction = %f\n", elapsed, bot->attack_start, elapsed - bot->attack_start);
        if (elapsed < SPEED_ATTACK) {
            r.h = 103; // ajustement taille si besoin
            SDL_RenderCopy(all->renderer,
                           find_texture(all->texture, "zombie_open"),
                           NULL, &r);
        }
        // 2) une fois SPEED_ATTACK atteint, on repasse en zombie fermé
        else {
            SDL_RenderCopy(all->renderer,
                           find_texture(all->texture, "zombie"),
                           NULL, &r);
            // et si on veut sortir de l’état attaque après 1s de zombie fermé
            if (elapsed >= SPEED_ATTACK + 1.0f) {
                bot->attacking    = false;
                bot->attack_start = 0;
            }
        }
    } else {
        // rendu normal hors attaque
        SDL_RenderCopy(all->renderer,
                       find_texture(all->texture, "zombie"),
                       NULL, &r);
    }
}


void bot_update_velocity(Bot *bot, int mouseX, int mouseY) {
    int dx = mouseX - (int)bot->x;
    int dy = mouseY - (int)bot->y;
    int dist2 = dx*dx + dy*dy;
    int seuil2 = ATTAQUE_DIST * ATTAQUE_DIST;

    if (dist2 < seuil2) {
        bot->attacking = true;
        bot->vx = bot->vy = 0.0f;
    } else {
        bot->attacking = false;
        float dist = sqrtf((float)dist2);
        if (dist > 1.0f) {
            bot->vx = BOT_SPEED * dx / dist;
            bot->vy = BOT_SPEED * dy / dist;
        }
    }
}

void resolve_bot_collisions(Bot bots[], int botCount) {
    for (int i = 0; i < botCount; i++) {
        for (int j = i + 1; j < botCount; j++) {
            float dx = bots[j].x - bots[i].x;
            float dy = bots[j].y - bots[i].y;
            float dist2 = dx*dx + dy*dy;
            float minDist = BOT_RADIUS * 2;
            if (dist2 > 0 && dist2 < minDist * minDist) {
                float dist = sqrtf(dist2);
                // calcul du vecteur de correction
                float overlap = 0.5f * (minDist - dist);
                float nx = dx / dist;
                float ny = dy / dist;
                // repousser bots i et j chacun de la moitié de l’overlap
                bots[i].x -= overlap * nx;
                bots[i].y -= overlap * ny;
                bots[j].x += overlap * nx;
                bots[j].y += overlap * ny;
                // (optionnel) échanger les vitesses comme un simple rebond élastique
                float vix = bots[i].vx, viy = bots[i].vy;
                bots[i].vx = bots[j].vx * 0.8f;  // coefficient de restitution
                bots[i].vy = bots[j].vy * 0.8f;
                bots[j].vx = vix * 0.8f;
                bots[j].vy = viy * 0.8f;
            }
        }
    }
}

Bot createBot(void) {
    Bot b;
    b.x = SCREEN_W + BOT_RADIUS;
    b.y = rand() % SCREEN_H;
    // Vitesse initiale : vers la souris, normalisée, sera recalculée chaque frame
    b.vx = b.vy = 0.0f;
    b.attacking = false;
	b.attack_start = 0;
    return b;
}


void	level1_loop_event(t_all *all)
{
	int mouse = 0;
	int	mouse_x = 0;
	int mouse_y = 0;
	int width;
    int height;
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		SDL_GetMouseState(&mouse_x, &mouse_y);
		if (event.type == SDL_QUIT)
		{
			all->render = MAIN_SCREEN;
			all->menu = NONE;
			all->status = RUNNING;
		}
		if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				all->status = STOP;
		}
		if (event.type == SDL_WINDOWEVENT)
		{
        	if (event.window.event == SDL_WINDOWEVENT_RESIZED)
			{
            	width = event.window.data1;
            	height = event.window.data2;
				SDL_GetWindowSize(all->window, &width, &height);
				new_size_texture(all, width, height);
			}
        }
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
            if (event.button.button == SDL_BUTTON_LEFT)
			{
                if (!mouse) 
				{
					if (isButtonClicked(*find_rect(all->rect, "shop_lvl1"), mouse_x, mouse_y))
					{
						all->lvl1_box_shop = 1;
					}
					else if (all->lvl1_box_shop == 1 && isButtonClicked(*find_rect(all->rect, "shop_btn"), mouse_x, mouse_y) && all->btn_lvl1.shop_btn_1 <= all->nb_count)
					{
						all->nb_count -= all->btn_lvl1.shop_btn_1;
						all->btn_lvl1.shop_btn_1 *= 3.14;
						all->mouse_power += 1;
					}
					else if (!isButtonClicked(*find_rect(all->rect, "shop_box"), mouse_x, mouse_y) && all->lvl1_box_shop == 1)
					{
						all->lvl1_box_shop = 0;
					}
					else if (isButtonClicked(*find_rect(all->rect, "bg_level1"), mouse_x, mouse_y))
					{
						Mix_PlayChannel(-1, all->click, 0);
						float angle = (rand() % 360) * 3.14 / 180.0f;
						float rayon = 0 + rand() % 120;

						float x  = mouse_x + cosf(angle) * rayon;
						float y  = mouse_y + sinf(angle) * rayon;
						float vx = ((rand() % 200) - 100) / 100.0f;
						float vy = -3.0f - (rand() % 100) / 100.0f;
						all->nb_count += all->mouse_power;
						ft_lstadd_back_rectA(&all->clicker_rec, ft_lstnew_rectA(x, y, 100, 100, vx, vy, "prop_lvl1"));
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

void delete_node(t_rectA **head)
{
    if (!head || !*head)
        return ;

    t_rectA *curr = *head;
    *head = curr->next;
    free(curr);
}

void	level1_loop(t_all *all)
{
	int count;
	int width;
    int height;
	SDL_Rect	dst;
	char	buf[64];

	count = 0;
	// … dans la boucle principale, après calcul de dt
	spawnTimer += all->dt;
	if (spawnTimer >= SPAWN_INTERVAL) {
		spawnTimer -= SPAWN_INTERVAL;      // on retire 5s (ou spawnTimer = 0.0f;)
		if (botCount < MAX_BOTS) {
			bots[botCount++] = createBot();
		}
	}
	level1_loop_event(all);
	SDL_RenderClear(all->renderer);
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "bg_level1"), NULL, find_rect(all->rect, "bg_level1"));
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "logo_fond_level1"), NULL, find_rect(all->rect, "logo_level1"));
	SDL_RenderCopy(all->renderer, find_texture(all->texture, "shop_lvl1"), NULL, find_rect(all->rect, "shop_lvl1"));
	int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    // 1) update de la vélocité de chaque bot
   for (int i = 0; i < botCount; i++) {
		// met à jour attack_start et attacking
		bot_update(&bots[i], mouseX, mouseY);
		// met à jour vx/vy seulement si pas en attaque
		if (!bots[i].attacking)
			bot_update_velocity(&bots[i], mouseX, mouseY);
	}


    // 2) résolution des collisions entre bots
    resolve_bot_collisions(bots, botCount);

    // 3) déplacement final selon vx, vy
    for (int i = 0; i < botCount; i++) {
        bots[i].x += bots[i].vx * all->dt;
        bots[i].y += bots[i].vy * all->dt;
    }
	for (int i = 0; i < botCount; i++) {
    	bot_render(&bots[i], all);
	}
	if (all->lvl1_box_shop  == 1)
	{
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "shop_box"), NULL, find_rect(all->rect, "shop_box"));
		SDL_RenderCopy(all->renderer, find_texture(all->texture, "shop_btn"), NULL, find_rect(all->rect, "shop_btn"));
		create_text(all->counter, all->renderer, all->window, SDL_itoa(all->btn_lvl1.shop_btn_1, buf, 10), 1350, 205);
	}
	t_rectA	*rec;
	rec = all->clicker_rec;
	if (rec && rec->rect.y <= -200)
		delete_node(&all->clicker_rec);
	while(rec)
	{
		if (count >= 20)
		{
			delete_node(&all->clicker_rec);
			break ;
		}
		else
		{
			SDL_SetTextureAlphaMod(find_texture(all->texture, "logo_level1"), rec->alpha);
			SDL_RenderCopy(all->renderer, find_texture(all->texture, "logo_level1"), NULL, &rec->rect);
			rec->x += rec->vx * 1;
        	rec->y += rec->vy * 1;
			rec->x += ((rand() % 3) - 1) * 0.1f;
			if (rec->alpha > 2) rec->alpha -= 2;
			else              rec->alpha  = 0;
			rec->rect.y -= 3;
			if (rec->alpha > 1)
				rec->alpha -= 2;
		}
		if (rec)
			rec = rec->next;
		count++;
	}
	SDL_Surface *surf = TTF_RenderText_Blended(all->counter, SDL_itoa(all->nb_count, buf, 10), all->counter_color);
	if (!surf)
	{
	    fprintf(stderr, "Erreur TTF_RenderText: %s\n", TTF_GetError());
	    return ;
	}
	if (all->counter_texture) SDL_DestroyTexture(all->counter_texture);
	all->counter_texture = SDL_CreateTextureFromSurface(all->renderer, surf);
	SDL_GetWindowSize(all->window, &width, &height);
	dst.x = (width - surf->w - 80);
	dst.y = 35;
	dst.w = surf->w;
	dst.h = surf->h;
	SDL_FreeSurface(surf);
	SDL_RenderCopy(all->renderer, all->counter_texture, NULL, &dst);
}