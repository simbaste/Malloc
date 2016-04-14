/*
** malloc.c for malloc in /home/khenki_n/Rendu/PSU_2015_malloc
**
** Made by khenki_n
** Login   <khenki_n@epitech.net>
**
** Started on Wed Jan 27 17:17:11 2016 khenki_n
** Last update Sat Apr  2 19:42:22 2016 stephanedarcy simomba
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include "malloc.h"

t_malloc		*g_tab_malloc[MAX_ALLOCATION];
//static t_list		*list = NULL;
static t_free		*tree_free = NULL;

int		split(t_malloc **tmp, int nb)
{
  t_malloc	*elem;
  int		indice;

  if ((elem = alloc_container(ELEM, sizeof(t_malloc))) == NULL)
    return (-1);
  elem->data = (*tmp)->end - nb;
  (*tmp)->size -= nb;
  if ((indice = my_hash(elem->data)) == -1)
    abort();
  elem->free = TRUE;
  elem->size = nb;
  elem->end = (*tmp)->end;
  (*tmp)->end = elem->data;
  g_tab_malloc[indice] = elem;
  if (add_node(&tree_free, g_tab_malloc[indice]) == -1)
    return (-1);
  return (0);
}

t_malloc	*func_malloc(size_t size)
{
  t_malloc	*elem;
  int		indice;
  int		page;

  if ((elem = alloc_container(ELEM, sizeof(t_malloc))) == NULL)
    return (NULL);
  page = (((size / PAGE) + 1) * PAGE);
  if ((elem->data = allocation_mem(page)) == NULL)
    return (NULL);
  if ((indice = my_hash(elem->data)) == -1)
    abort();
  elem->free = FALSE;
  elem->size = page;
  elem->end = sbrk(0);
  g_tab_malloc[indice] = elem;
  if (split(&elem, (elem->size - size)) == -1)
    return (NULL);
  return (elem);
}

void		*my_malloc(size_t size)
{
  t_malloc	*elem;
  t_malloc	*tmp;
  int		indice;

  if ((tmp = search_node(&tree_free, size)) == NULL)
    {
      if ((elem = func_malloc(size)) == NULL)
	return (NULL);
      return (elem->data);
    }
  if ((indice = tmp->size - size) > 1)
    if (split(&tmp, indice) == -1)
      return (NULL);
  tmp->free = FALSE;
  return (tmp->data);
}

void		*malloc(size_t size)
{
  lock();
  void * ptr = my_malloc(size);
  unlock();
  return ptr;
}

void		my_free(void *ptr)
{
  int		indice;

  if (ptr == NULL)
    return;
  //lock();
  if ((indice = my_dehash(ptr)) == -1 || g_tab_malloc[indice] == NULL)
    put_err(INVALID, ptr);
  else if (g_tab_malloc[indice]->free == TRUE)
    put_err(DOUBLE_FREE, ptr);
  g_tab_malloc[indice]->free = TRUE;
  memset(g_tab_malloc[indice]->data, 0, g_tab_malloc[indice]->size);
  if (add_node(&tree_free, g_tab_malloc[indice]) == -1)
    {
      //unlock();
      return;
    }
  //unlock();
}

void		free(void *ptr)
{
  lock();
  my_free(ptr);
  unlock();
}

void	*calloc(size_t nmemb, size_t size)
{
  void	*ptr;

  ptr = NULL;
  if (nmemb > 0 && size != 0)
    {
      ptr = malloc(nmemb * size);
      lock();
      memset(ptr, 0, (nmemb * size));
      unlock();
    }
  return (ptr);
}

void		*func_realloc(void *ptr, size_t size)
{
  if (ptr == NULL && size > 0)
    return (ptr = malloc(size));
  if (size <= 0)
    {
      free(ptr);
      return (ptr);
    }
  return ((void*) - 1);
}

void		*realloc(void *ptr, size_t size)
{
  t_malloc	*tmp;
  void		*temp;
  int		indice;
  int		nb;

  if ((temp = func_realloc(ptr, size)) != (void *) - 1)
    return (temp);
  lock();
  if ((indice = my_dehash(ptr)) == -1 || (tmp = g_tab_malloc[indice]) == NULL)
    put_err(INVALID, ptr);
  if (tmp->free == TRUE)
    {
      unlock();
      return (ptr);
    }
  unlock();
  if ((nb = tmp->size - size) > 1)
    {
      lock();
      split(&tmp, nb);
      unlock();
      return (tmp->data);
    }
  temp = malloc(size);
  lock();
  memcpy(temp, ptr, g_tab_malloc[indice]->size);
  unlock();
  free(ptr);
  return (temp);
}

/*void		*realloc(void *ptr, size_t size)
  {
  void		*newptr;

  lock();
  newptr = my_realloc(ptr, size);
  unlock();
  return (newptr);
  }*/
