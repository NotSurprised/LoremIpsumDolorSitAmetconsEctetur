#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>


char buf[80];

int main (int argc, char **argv)
{
  printf("I will echo what U gave, But not the secret.\n");
  unsigned int filler0 = 0x52696674;
  unsigned int filler1 = 0x52696674;
  unsigned int filler2 = 0x52696674;
  unsigned int filler3 = 0x52696674;
  unsigned int key     = 0x25783462;
  unsigned int filler4 = 0x52696674;
  unsigned int filler5 = 0x52696674;
  unsigned int filler6 = 0x52696674;

  unsigned int red = read(STDIN_FILENO,buf,80);
  buf[red] = '\x00';
  printf(buf);
}
