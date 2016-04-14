/*
** show_alloc_mem.c for showmem in /home/khenki_n/Rendu/PSU_2015_malloc/tmp
**
** Made by khenki_n
** Login   <khenki_n@epitech.net>
**
** Started on Mon Feb  1 17:41:01 2016 khenki_n
** Last update Tue Feb  2 10:42:10 2016 stephanedarcy simomba
*/

#include <unistd.h>
#include "malloc.h"

t_malloc	*g_tab_malloc[MAX_ALLOCATION];

void	show_alloc_mem()
{
  int	i;

  write(1, "break : 0x", my_strlen("break : 0x"));
  print_add((long)sbrk(0), 1);
  write(1, "\n", 1);
  i = 0;
  while (i < MAX_ALLOCATION)
    {
      if (g_tab_malloc[i])
	{
	  write(1, "0x", 2);
	  print_add((long)g_tab_malloc[i]->data, 1);
	  write(1, " - ", 3);
	  write(1, "0x", 2);
	  print_add((long)g_tab_malloc[i]->end, 1);
	  write(1, " : ", 3);
	  my_put_nbr((long)g_tab_malloc[i]->size);
	  write(1, " bytes\n", my_strlen(" bytes\n"));
	}
      ++i;
    }
}
