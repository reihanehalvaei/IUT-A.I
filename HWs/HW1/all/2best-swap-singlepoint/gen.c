#include <stdio.h>
#include <stdlib.h>
#include "select.c"
#include "xover.c"

int roulette(IPTR pop, double sumFitness, int popsize);

int comparator(const void* p, const void* q)
{
	if(((IPTR)p)->fitness <
                  ((IPTR)q)->fitness)
		return 1;
				  
	if (((IPTR)p)->fitness >
                  ((IPTR)q)->fitness)
		return -1;
		
    return 0;
}

int generation_random(POPULATION *p)
{

  int i, p1, p2, c;

  IPTR pi, piPlus1, om1, om2;
		  
  
  int rand1,rand2;
  
  qsort(p->op, p->popSize, sizeof(INDIVIDUAL), comparator);
  
  for(int i=0 ; i < p->popSize ; i+=2){
	  
	  rand1 = rand()% (p->popSize) %2;
	  rand2 = rand()% (p->popSize) %2;

	  om1 = &(p->op[rand1]);
	  om2 = &(p->op[rand2]);
	  pi = &(p->np[i]);
	  piPlus1 = &(p->np[i+1]);

	  crossover(p, om1, om2, pi, piPlus1);


	  pi->fitness = eval(p, pi); 
      pi->parent1 = p1;
      pi->parent2 = p2;

    
      piPlus1->fitness = eval(p, piPlus1); 
      piPlus1->parent1 = p2;
      piPlus1->parent2 = p1;
	  
  }

}
