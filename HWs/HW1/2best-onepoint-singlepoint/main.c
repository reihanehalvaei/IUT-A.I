#include <math.h>
#include <stdio.h>
#include <conio.h>
#include "type.h"
#include "utils.c"
#include "init.c"
#include "gen.c"


int erfunc(char *s, int val);
void initialize(char *argv[], POPULATION *p);
void report(int gen, POPULATION *p, IPTR  pop);
void statistics(POPULATION *p, IPTR pop);

int isequal(int *max_fit, int* found, int lchrom){
	int flag = 1;
	for(int j=0;j<lchrom ;j++){
		  if(max_fit[j] != found[j]){
		  flag=0;break;}
		  
	  }
	  return flag;
	
}


int main(int argc, char *argv[])
{
  IPTR tmp, op, np;
  POPULATION population;
  POPULATION *p = &population;
  int i,j;

  p->gen = 0;
  
  srand(2);

  if(argc != 2) return erfunc("Usage: ga <inputfile name> ", argc);
  
  initialize(argv, p);
	
	
int count=0;
int found[1000][25];
while(count != 1000){
  while(p->highestEverFitness != 300){
    p->gen++;
	 generation_random(p);
	 statistics(p, p->np);
	 
    tmp = p->op;
    p->op = p->np;
    p->np = tmp;
  }
  
  int f=0;
  for(i=0;i<count && f==0 ;i++)
  {  
	  if(isequal(p->max_fit,found[i],p->lchrom))
		  f = 1;		  
  }
  
  if(f==0){
	  for(int j=0;j<25 && f==1;j++){
		  found[count][j] = p->max_fit[j];
	  }
	  count++;
	  printf("\n no %d : ", count);
	  for(int i = 0;i < p->lchrom;i++)
		printf(" %d", p->max_fit[i]);
	  
	  
  }
  
  p->highestEverFitness = 0.0;
  p->highestEverGen = 0;
  p->highestEverIndex = 0;
  for (int i = 0; i < p->popSize; i++){
	  IPTR pi;
	  pi = &(p->op[i]);
	    for (j = 0; j < p->lchrom; j++){
		  pi->chrom[j] = selfrnd(p->lchrom)+1;
	    }
	  }
  
  
}

}


