/*
** main.c for  in /home/simomb_s/semestre2/Btree
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Mar 25 23:29:05 2015 stephanedarcy simomba
** Last update Wed Feb 10 20:49:54 2016 stephanedarcy simomba
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "malloc.h"

int		func_verif(t_free **offset2, size_t size)
{
  if (*offset2 && (*offset2)->my_free->size >= size &&
      (*offset2)->my_free->free == TRUE)
    {
      (*offset2)->my_free->free = FALSE;
      return (1);
    }
  return (0);
}

t_malloc	*func_search(t_free **tree, size_t size,
			     t_free **offset, t_free **offset2)
{
  t_free	*tmp;

  tmp = *tree;
  while (tmp != NULL)
    {
      *offset = tmp;
      if (tmp->my_free->size >= size && tmp->my_free->free == TRUE)
	{
	  tmp->my_free->free = FALSE;
	  return (tmp->my_free);
	}
      if (size > tmp->my_free->size)
	tmp = tmp->right;
      else
	{
	  if (func_verif(offset2, size) == 1)
	    return ((*offset2)->my_free);
	  *offset2 = tmp;
	  tmp = tmp->left;
	}
    }
  return (NULL);
}

t_malloc	*search_node(t_free **tree, size_t size)
{
  t_free	*offset;
  t_free	*offset2;
  t_malloc	*elem;

  offset = NULL;
  offset2 = NULL;
  if ((elem = func_search(tree, size, &offset, &offset2)) != NULL)
    return (elem);
  if (offset != NULL && offset->my_free->size >= size &&
      offset->my_free->free == TRUE)
    {
      offset->my_free->free = FALSE;
      return (offset->my_free);
    }
  if (offset2 != NULL && offset2->my_free->size >= size &&
      offset2->my_free->free == TRUE)
    {
      offset->my_free = FALSE;
      return (offset2->my_free);
    }
  return (NULL);
}
