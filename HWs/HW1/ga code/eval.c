#include <stdio.h>
#include <math.h>    /* for pow(x, y) */


double decode(IPTR pj, int index, int size);
double binToDec(int *chrom, int l);

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

double decode(IPTR pj, int index, int size)
{
  return ((double) binToDec(&(pj->chrom[0]), size));
}

double binToDec(int *chrom, int l)
{
  int i;
  double prod;

  prod = 0.0;

  for(i = 0; i < l; i++){
    prod += (chrom[i] == 0 ? 0.0 : pow((double)2.0, (double) i));
  }
  return prod;
}

void decToBin(int ad, int *barray, int size)
{
  int i, t;

  t = ad;
  for(i = 0; i < size; i++){
    barray[i] = t%2;
    t = t/2;
  }
}
