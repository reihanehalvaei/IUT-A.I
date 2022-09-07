#include <stdio.h>
#include <stdlib.h>



void rawStat(FILE *fp, POPULATION *p, IPTR pop);
//void rawStat();

void report(int gen, POPULATION *p, IPTR  pop)
{ /* report generations stats */
  FILE *fp;

  if( (fp = fopen(p->ofile, "a")) == NULL){
	 printf("error in opening file %s \n", p->ofile);
	 exit(1);
  }else{
	 rawStat(fp, p, pop);
	 fclose(fp);
  }
  rawStat(stdout, p, pop);


}

void rawStat(FILE *fp, POPULATION *p, IPTR pop)
{
	
  fprintf(fp," gen : %3d max = %10.2lf ", p->gen, p->max);
  
  fprintf(fp," hG : %3d hF : %10.2lf hIDX : %3d  hCHR : ", p->highestEverGen,  p->highestEverFitness, //more explain
	  p->highestEverIndex);
	  
  for(int i = 0;i < p->lchrom;i++)
	fprintf(fp," %d", p->max_fit[i]);

  fprintf(fp,"\n");
}

