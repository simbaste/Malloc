/*
** tes.c for tet in /home/khenki_n
**
** Made by khenki_n
** Login   <khenki_n@epitech.net>
**
** Started on Wed Feb  3 14:41:40 2016 khenki_n
** Last update Fri Feb  5 03:34:16 2016 stephanedarcy simomba
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define MAX_ALLOCATION 250000

typedef struct	s_page
{
  int		size;
  void		*data;
}		t_page;

typedef struct	s_malloc
{
  size_t	size;
  void		*data;
  void		*end;
}		t_malloc;

t_malloc *g_tab[MAX_ALLOCATION];

void	*alloc_mem(size_t size, t_page *page)
{
  void	*data;
  int	 time;

  if (page->size == 0)
    {
      time = (size < (size_t)getpagesize()) ? 1 : (size / getpagesize() == 1) ? 2 : size / getpagesize();
      page->data = sbrk(0);
      sbrk(getpagesize() * time);
      page->size = getpagesize() * time;
    }
  if ((size_t)page->size < size)
    {
      time = (size < (size_t)getpagesize()) ? 1 : size / getpagesize();
      data = page->data;
      page->data = sbrk(0);
      sbrk(getpagesize() * time);
      page->data = data + size;
      page->size = (page->size + getpagesize() * time) - size;
      if (page->size < 0)
	{
	  page->size += getpagesize();
	  sbrk(getpagesize());
	}
      return (data);
    }
  data = page->data;
  page->data += size;
  page->size -= size;
  return (data);
}

void *my_malloc(size_t size)
{
  void	*elem;
  static t_page page;

  elem = alloc_mem(size, &page);
  return (elem);
}

int main()
{
  srandom(time(NULL));
  int i;
  printf("sbrk[%p]--[%ld]\n", sbrk(0), (long)sbrk(0));
  for (i = 0; i < 50000; i++)
    {
      int nb = random() % 50000 + 1;
      void *tmp = sbrk(0);
      char *ptr = my_malloc(nb);
      printf("%p ---%d- fin[%p]\n", ptr, nb,ptr + nb);
      printf("ancien sbrk %p\n", tmp);
      printf("sbrk fin %p ---[%ld]\n\n", sbrk(0), (long)sbrk(0));
      ptr[nb - 1] = 'A';

      printf("ptr[%d] = %c\n", nb - 1, ptr[nb - 1]);
    }
  return(0);
}
