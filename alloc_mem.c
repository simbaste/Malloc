/*
** alloc_mem.c for  in /home/simomb_s/MyGithub/Malloc
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Thu Apr 14 12:59:09 2016 stephanedarcy simomba
** Last update Thu Apr 14 12:59:12 2016 stephanedarcy simomba
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
