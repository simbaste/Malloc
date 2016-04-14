/*
** mutex.c for  in /home/simomb_s/semestre4/rendu_4/tmp/PSU_2015_malloc
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Tue Feb  9 16:29:20 2016 stephanedarcy simomba
** Last update Tue Feb  9 16:31:55 2016 stephanedarcy simomba
*/

#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include "malloc.h"

static pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	lock()
{
  if (pthread_mutex_lock(&g_mutex) != 0)
    raise(errno);
}

void	unlock()
{
  if (pthread_mutex_unlock(&g_mutex) != 0)
    raise(errno);
}
