/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 00:34:03 by mmonier           #+#    #+#             */
/*   Updated: 2019/08/13 01:37:33 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
//#include "SDL.h"
#include <stdlib.h>

/*static void		waiting(void)
{
	int			loop;
	SDL_Event	event;

	loop = 1;
	while (loop == 1)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				loop = 0;
		}
	}
}*/

int				main(int ac, char **av)
{
	t_id		*id;

	if (!(id = (t_id *)ft_memalloc(sizeof(t_id))))
		return (0);
	parse_input(id);
/*	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		exit(EXIT_FAILURE);
	SDL_Window *screen = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 2000, 1400, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 23, 109, 97, 255);
	SDL_RenderClear(renderer);
//	SDL_Surface* image = IMG_Load("image.png");
	SDL_SetRenderDrawColor(renderer, 0, 50, 97, 255);
	SDL_RenderDrawLine(renderer, 320, 200, 300, 240);
	SDL_RenderDrawLine(renderer, 200, 240, 340, 240);
	SDL_RenderDrawLine(renderer, 240, 240, 320, 200);
//	SDL_RenderClear(renderer);
	SDL_Delay(500);
	SDL_RenderPresent(renderer);
	SDL_Delay(500);
	waiting();*/
	t_room *room;

	room = id->room;
	print_loading();
	while (room)
	{
	//	printf("ROOM = %s X = %d Y = %d\n", room->name, room->x, room->y);
		print_square(room->x, room->y);
		t_link *link = room->link;
	/*	while (link)
		{
			printf("links = %s\n", link->lkd_room->name);
			link = link->next;
		}*/
		room = room->next;
	}
//	SDL_Quit();
	return (0);
}
