/*
** function.c for  in /home/simomb_s/semestre4/rendu_4/PSU_2015_malloc/tmp1
**
** Made by stephanedarcy simomba
** Login   <simomb_s@epitech.net>
**
** Started on  Tue Feb  2 08:08:25 2016 stephanedarcy simomba
** Last update Wed Feb 10 21:08:02 2016 stephanedarcy simomba
*/

#include <unistd.h>
#include <stdlib.h>
#include "malloc.h"

void		print_add(unsigned long nb, int fd)
{
  unsigned int	div;
  unsigned int	nbr;
  unsigned int	len;
  char		*base;

  div = 1;
  nbr = nb;
  base = "0123456789ABCDEF";
  len = 16;

  while (nbr > len)
    {
      nbr = nbr / len;
      div = div * len;
    }
  nbr = nb;
  while (div > 0)
    {
      nbr = nb / div;
      div = div / len;
      write(fd, &base[nbr % len], 1);
    }
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str && str[i] != 0)
    i++;
  return (i);
}

int		my_getnbr(char *str)
{
  int		nb;
  int		i;
  int		signe;

  signe = 1;
  i = 0;
  nb = 0;
  while (str && str[i] != 0 && (str[i] == '+' || str[i] == '-'))
    {
      if (str[i] == '-')
	signe *= -1;
      i++;
    }
  while (str && str[i] != 0 && str[i] >= '0' && str[i] <= '9')
    {
      nb = nb * 10 + str[i] - '0';
      if (nb < 0)
	return (0);
      i++;
    }
  return (nb * signe);
}

void	put_err(char *str, void *ptr)
{
  write(2, str, my_strlen(str));
  print_add((long)ptr, 2);
  write(2, " ***\n", my_strlen(" ***\n"));
  //  abort();
}

void		my_put_nbr(int nb)
{
  int		d;
  char		c;

  d = 1;
  if (nb < 0)
    {
      write(1, "-", 1);
      nb *= -1;
    }
  while((nb / d) >= 10)
    d *= 10;
  while (d > 0)
    {
      c = (nb / d) % 10 + '0';
      write(1, &c, 1);
      d /= 10;
    }
}
