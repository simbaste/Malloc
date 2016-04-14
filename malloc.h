/*
** malloc.h for malloc in /home/khenki_n/Rendu/PSU_2015_malloc
**
** Made by khenki_n
** Login   <khenki_n@epitech.net>
**
** Started on Wed Jan 27 16:45:01 2016 khenki_n
** Last update Wed Feb 10 22:34:50 2016 nicolas khenkittisak
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# define MAX_ALLOCATION 260000
# define PAGE getpagesize()

# define DOUBLE_FREE "*** Error in malloc: double free or corruption (fasttop): 0x000000000"
# define INVALID "*** Error in malloc: my_free(): invalid pointer 0x000000000"

# define MEM(x) ((PAGE / x) * x)

# include <stdio.h>

typedef enum	e_my_bool
  {
    FALSE,
    TRUE
  }		t_my_bool;

typedef enum	e_type
  {
    TREE,
    ELEM,
    LIST
  }		t_type;

typedef struct		s_malloc
{
  t_my_bool		free;
  size_t		size;
  void			*data;
  void			*end;
}			t_malloc;

typedef struct		s_list
{
  struct s_list		*end;
  struct s_list		*next;
  struct s_list		*prev;
  t_malloc		*mall;
}			t_list;

typedef struct	s_free
{
  t_malloc	*my_free;
  struct s_free	*left;
  struct s_free *right;
}		t_free;

typedef struct	s_page
{
  int		size;
  void		*data;
}		t_page;

extern t_malloc		*g_tab_malloc[MAX_ALLOCATION];
//extern t_page		my_page;
//extern int		g_ok;

int		add_node(t_free **tree, t_malloc *my_free);
void		print_tree(t_free *tree);
t_malloc	*search_node(t_free **tree, size_t size);
t_malloc	*search_list(t_list **list, size_t size);
void		my_put_end_in_list(t_list **list, t_malloc *mall);
int		my_strlen(char *str);
void		print_add(unsigned long nb, int fd);
void		my_put_nbr(int);
void		show_alloc_mem();
int		my_getnbr(char *str);
int		my_hash(void *ptr);
int		my_dehash(void *ptr);
void		lock();
void		unlock();
void		*alloc_container(t_type type, int s_size);
void		*allocation_mem(size_t size);
void		*allocation_tree();
void		*allocation_elem();
void		put_err(char *str, void *ptr);

#endif /* !MALLOC_H_ */
