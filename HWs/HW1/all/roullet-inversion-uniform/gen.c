#include <stdio.h>
#include <stdlib.h>
#include "select.c"
#include "xover.c"

int roulette(IPTR pop, double sumFitness, int popsize);
//void crossover(POPULATION *p, IPTR p1, IPTR p2, IPTR c1, IPTR c2);
//double eval(POPULATION *p, IPTR pj);


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


int generation(POPULATION *p)
{

  int i, p1, p2, c;

  IPTR pi, piPlus1, om1, om2;

  for(i = 0; i < p->popSize; i += 2){

    p1 = roulette(p->op, p->sumFitness, p->popSize);
    p2 = roulette(p->op, p->sumFitness, p->popSize);

    pi = &(p->np[i]);
    piPlus1 = &(p->np[i+1]);
    om1 = &(p->op[p1]);
    om2 = &(p->op[p2]);

    crossover_Uniform(p, om1, om2, pi, piPlus1);

    pi->fitness = eval(p, pi); 
    pi->parent1 = p1;
    pi->parent2 = p2;

    
    piPlus1->fitness = eval(p, piPlus1); 
    piPlus1->parent1 = p2;
    piPlus1->parent2 = p1;

  }

}

