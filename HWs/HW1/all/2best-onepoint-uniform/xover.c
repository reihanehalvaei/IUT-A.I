

int rnd(int low, int high);
int flip(double);
void muteX(POPULATION *p, int* chr);

void crossover_Uniform(POPULATION *p, IPTR p1, IPTR p2, IPTR c1, IPTR c2)
{
/* p1,p2,c1,c2,m1,m2,mc1,mc2 */
  int *pi1,*pi2,*ci1,*ci2;
  int xp, i;

  pi1 = p1->chrom;
  pi2 = p2->chrom;
  ci1 = c1->chrom;
  ci2 = c2->chrom;
  
  

	muteX(p, pi1);
	muteX(p, pi2);
	
    for(i = 0; i < p->lchrom; i++){
		if(flip(p->pCross)){
		  ci1[i] = pi2[i];
		  ci2[i] = pi1[i];
		}
		else{
			ci1[i] = pi1[i];
			ci2[i] = pi2[i];
		}
    
  } 
}

void muteX(POPULATION *p, int* chr)
{
  if(flip(p->pMut))
		chr[rand()%(p->lchrom)+1] = (rand()%(p->lchrom)+1);
}
