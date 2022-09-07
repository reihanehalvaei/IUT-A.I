/* randgen.c => contains random number generator and related utilities
   including advance_random, warmup_random, random, randomize
*/


#define RANCONST 1.0E-9
#include <stdio.h>
#include <time.h>


double f_random()
{
	double random1 = (double)(rand()%1001)/1000;
	double random2 = (double)(rand()%1001)/1000;
	// printf("r : %f   %f\n",random, random2);
	return rand()%2 ? random1 : 1 - random1;
}

void randomize(POPULATION *p)  /* Get seed number for random and start it up */
{

  printf("Enter seed random number (0.0..1.0) > "); 
  scanf("%lf",&p->randomseed);
  while ( p->randomseed < 0.0 || p->randomseed > 1.0){
    printf("ERROR: Enter seed random number again (0.0..1.0) > ");
    scanf("%lf\n",&p->randomseed);
  }

	
}


int flip(double prob)
{/* Flip a biased coin...true if heads */

if (prob == 1.0) 
  return 1;
else 
  return (f_random() <= prob);

}

int rnd(int low, int high)
{ /* pick a random int between low and high */
  double fr;
  int i;
  fr = f_random();
  
  if(low >= high) {
    i = low;
  } else {
    i = ((int)(fr * (double)(high - low + 1)) + low);
    if (i > high) i = high;
  }
  return i;
}

int selfrnd(int lc)
{ /* pick a random int between low and high */
  int i = rand()%lc;
  return i;
}


