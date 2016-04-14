/*
** hashage.c for  in /home/simomb_s/semestre4/rendu_4/PSU_2015_malloc/tmp2
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Mon Feb  8 08:16:42 2016 stephanedarcy simomba
** Last update Wed Feb 10 16:00:27 2016 stephanedarcy simomba
*/

#include <stdlib.h>
#include <unistd.h>
#include "malloc.h"

t_malloc	*g_tab_malloc[MAX_ALLOCATION];

int             my_dehash(void *ptr)
{
  unsigned int  tmp;
  unsigned int  i;

  i = 0;
  if (ptr == NULL)
    return (-1);
  tmp = (((long)ptr % MAX_ALLOCATION) + i) % MAX_ALLOCATION;
  if (g_tab_malloc[tmp] && g_tab_malloc[tmp]->data == ptr)
    return (tmp);
  while (g_tab_malloc[tmp] != NULL)
    {
      if (g_tab_malloc[tmp]->data == ptr)
	return (tmp);
      tmp = (((long)ptr % MAX_ALLOCATION) + (i * i)) % MAX_ALLOCATION;
      ++i;
    }
  return (-1);
}

int             my_hash(void *ptr) /// quadratic
{
  unsigned int  tmp;
  unsigned int  i;

  if (ptr == NULL)
    return (-1);
  i = 0;
  //tmp = (long)ptr % MAX_ALLOCATION;
  tmp = (((long)ptr % MAX_ALLOCATION) + i) % MAX_ALLOCATION;
  while (g_tab_malloc[tmp] != NULL)
    {
      tmp = (((long)ptr % MAX_ALLOCATION) + (i * i)) % MAX_ALLOCATION;
      ++i;
    }
  return (tmp);
}
