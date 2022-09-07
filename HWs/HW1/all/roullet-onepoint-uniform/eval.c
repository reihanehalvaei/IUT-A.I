#include <stdio.h>
#include <math.h>    /* for pow(x, y) */



double eval(POPULATION *p, IPTR pj) 
     /* Called from gen.c and init.c */
{
  double val = p->lchrom;
  double fitness = val*(val-1)/2;
  
  for (int i = 0; i < p->lchrom; i++){
	  for (int j = i+1; j < p->lchrom; j++){
		  if((pj->chrom[i]==pj->chrom[j]) || (i - pj->chrom[i] == j - pj->chrom[j]) 
			  || (i+ pj->chrom[i] == j + pj->chrom[j]))
			fitness--;
	  }
	}

  return fitness;
}


