/*
** alloc_mem.c for alloc_mem in /home/khenki_n/Rendu/2/PSU_2015_malloc
**
** Made by khenki_n
** Login   <khenki_n@epitech.net>
**
** Started on Mon Feb  8 16:30:47 2016 khenki_n
** Last update Wed Feb 10 22:49:11 2016 nicolas khenkittisak
*/

#include <unistd.h>
#include "malloc.h"

void		*alloc_container(t_type type, int s_size)
{
  static t_page page_tree;
  static t_page page_elem;
  static t_page page_list;
  int		size;
  t_page	*tmp;
  void		*data;

  tmp = (type == TREE ? &page_tree : type == ELEM ? &page_elem : &page_list);
  size = (type == TREE ? sizeof(t_free) * 5000 : type == ELEM ?
	  MEM(sizeof(t_malloc)) : MEM(sizeof(t_malloc)));
  if (tmp->size == 0)
    {
      if ((tmp->data = sbrk(0)) == (void*) - 1)
	return (NULL);
      if (sbrk(size) == (void*) - 1)
	return (NULL);
      tmp->size = size;
    }
  data = tmp->data;
  tmp->data += s_size;
  tmp->size -= s_size;
  return (data);
}

void		*allocation_mem(size_t size)
{
  void		*data;

  if ((data = sbrk(0)) == (void*) - 1)
    return (NULL);
  if (sbrk(size) == (void*) - 1)
    return (NULL);
  return (data);
}
