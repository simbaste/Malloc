/*
** func_list.c for  in /home/simomb_s/semestre4/rendu_4/PSU_2015_malloc/tmp2
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Tue Feb  2 21:48:32 2016 stephanedarcy simomba
** Last update Wed Feb  3 18:31:06 2016 stephanedarcy simomba
*/

#include <stdlib.h>
#include <unistd.h>
#include "malloc.h"

static t_list	*g_tab_list[MAX_ALLOCATION];
static int	inc = 0;

void		func_list(t_list **list, t_malloc *mall)
{
  t_list	*elem;

  if (g_tab_list[inc])
    {
      elem = g_tab_list[inc];
      g_tab_list[inc--] = NULL;
      if (inc < 0)
	inc = 0;
    }
  else
    elem = allocation_mem(sizeof(t_list));
  elem->next = NULL;
  elem->mall = mall;
  if ((*list)->end == NULL)
    {
      (*list)->next = elem;
      (*list)->end = elem;
    }
  else
    {
      (*list)->end->next = elem;
      (*list)->end = elem;
    }
}

void		my_put_end_in_list(t_list **list, t_malloc *mall)
{
  if (*list == NULL)
    {
      if (g_tab_list[inc])
	{
	  *list = g_tab_list[inc];
	  g_tab_list[inc--] = NULL;
	  if (inc < 0)
	    inc = 0;
	}
      else
	*list = allocation_mem(sizeof(t_list));
      (*list)->mall = mall;
      (*list)->end = NULL;
      //      (*list)->prev = NULL;
      (*list)->next = NULL;
    }
  func_list(list, mall);
}

t_malloc	*search_list(t_list **list, size_t size)
{
  t_list	*tmp;
  t_list	*offset;
  t_malloc	*elem;

  tmp = *list;
  offset = NULL;
  while(tmp != NULL)
    {
      if (tmp->mall->size >= size)
	{
	  elem = tmp->mall;
	  if (offset == NULL)
	    *list = NULL;
	  else
	    offset->next = tmp->next;
	  g_tab_list[inc++] = tmp;
	  return (elem);
	}
      offset = tmp;
      tmp = tmp->next;
    }
  return (NULL);
}
