#include "ft.h"

void link_sprites(t_sprite *collect, int x, int y)
{
	collect->loc->x = x;
	collect->loc->y = y;
	collect->loc->next = (t_loc *)malloc(sizeof(t_loc));
	collect->loc = collect->loc->next;
	collect->loc->next = NULL;
}
