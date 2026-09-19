/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:41:40 by amblanch          #+#    #+#             */
/*   Updated: 2026/09/19 11:38:12 by nda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDE/graph.h"
# include <string.h>

SDL_Texture	*LoadTexture(const char *file, SDL_Renderer *renderer)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = IMG_Load(file);
	if (!surface)
	{
		SDL_Log("Erreur, chargement de l'image : %s", IMG_GetError());
		return (NULL);
	}
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture)
	{
		SDL_Log("Erreur, création de la texture : %s", SDL_GetError());
		return (NULL);
	}
	return (texture);
}
