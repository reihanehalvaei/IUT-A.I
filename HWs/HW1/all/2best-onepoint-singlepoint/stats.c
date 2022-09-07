#include <stdio.h>
/*#include <math.h>*/



void statistics(POPULATION *p, IPTR pop)
{ /* calculate population stats */
  int size, i, j, s;
  IPTR pi;

  p->sumFitness = pop[0].fitness;
  p->max = p->sumFitness;
  p->maxi = 0;
  
  for(i = 1; i < p->popSize; i++){
    pi = &(pop[i]);
    p->sumFitness += pi->fitness; 
    if (p->max < pi->fitness) {
      p->max = pi->fitness;   p->maxi = i;
    }
  }
  if(p->highestEverFitness < p->max) {
    p->highestEverFitness = p->max; 
    p->highestEverGen = p->gen; 
    p->highestEverIndex = p->maxi;
	
    for (j = 0; j < p->lchrom; j++){
		p->max_fit[j] = (pop[p->maxi]).chrom[j];
	}

  }
}
