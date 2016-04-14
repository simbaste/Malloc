/*
** main.c for  in /home/simomb_s/semestre2/Btree
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Wed Mar 25 23:29:05 2015 stephanedarcy simomba
** Last update Wed Feb 10 22:50:51 2016 nicolas khenkittisak
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "malloc.h"

t_free		*create_elem(t_malloc *my_free)
{
  t_free	*elem;

  if ((elem = alloc_container(TREE, sizeof(t_free))) == NULL)
    return (NULL);
  elem->left = NULL;
  elem->right = NULL;
  elem->my_free = my_free;
  return (elem);
}

int		move(t_malloc *my_free,
		     t_free **tmp_node, t_free **tmp_tree)
{
  t_free	*elem;
  int		direction;

  direction = ((*tmp_node)->my_free->size < my_free->size ? 0 : 1);
  *tmp_tree = (direction == 0 ? (*tmp_tree)->right : (*tmp_node)->left);
  if (!(*tmp_tree))
    {
      if ((elem = create_elem(my_free)) == NULL)
	return (-1);
      direction == 0 ? ((*tmp_node)->right = elem) : ((*tmp_node)->left = elem);
    }
  return (0);
}

int		add_node(t_free **tree, t_malloc *my_free)
{
  t_free	*tmp_node;
  t_free	*tmp_tree;

  if (my_free == NULL)
    return (0);
  tmp_tree = *tree;
  if (tmp_tree != NULL)
    {
      while (tmp_tree != NULL)
	{
	  tmp_node = tmp_tree;
	  if (tmp_node->my_free == my_free)
	    {
	      my_free->free = TRUE;
	      break;
	    }
	  if (move(my_free, &tmp_node, &tmp_tree) == -1)
	    return (-1);
	}
    }
  else
    if ((*tree = create_elem(my_free)) == NULL)
      return (-1);
  return (0);
}
