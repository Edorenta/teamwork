#include <time.h>
#include <stdlib.h>
#include <stdio.h>

static unsigned long int next = 1; 

int rnd(void) // RAND_MAX assumed to be 32767 
{ 
    next = next * 1103515245 + 12345; 
    return (unsigned int)(next/65536) % 32768; 
} 

void srnd(unsigned int seed) 
{ 
    next = seed; 
}

int main()
{
  int a;
  tsrand(time(NULL));
  for(int i = 0; i < 2000000; i++)
  {
    a = (1 + (rand() / (RAND_MAX / 10)));
    printf("%d\n", a);
  }
  return 0;
}
