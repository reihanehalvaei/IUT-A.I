int rnd(int low, int high);
int flip(double);
void muteX_swap(POPULATION *p, int* chr);

void crossover(POPULATION *p, IPTR p1, IPTR p2, IPTR c1, IPTR c2)
{
/* p1,p2,c1,c2,m1,m2,mc1,mc2 */
  int *pi1,*pi2,*ci1,*ci2;
  int xp, i;

  pi1 = p1->chrom;
  pi2 = p2->chrom;
  ci1 = c1->chrom;
  ci2 = c2->chrom;
  
  if(flip(p->pCross)){

    xp = rnd(0, p->lchrom - 1);
	
	
	muteX_swap(p, pi1);
	muteX_swap(p, pi2);
	
    for(i = 0; i < xp; i++){
      ci1[i] = pi1[i];
      ci2[i] = pi2[i];
    }
    for(i = xp; i < p->lchrom; i++){
      ci1[i] = pi2[i];
      ci2[i] = pi1[i];
    }
  } 
  else {
    for(i = 0; i < p->lchrom; i++){
      ci1[i] = pi1[i];
      ci2[i] = pi2[i];
    }
  }
}

void muteX_swap(POPULATION *p, int* chr)
{
  if(flip(p->pMut)){
	int l , h ,tmp;
	
	l = rand()%(p->popSize);
	do
	  h = rand()%(p->popSize);
	while(h == l);
		
	if(l>h)
	{
		tmp = h;
		h = l;
		l = tmp;
	}
	
	int temp = chr[l]; 
	chr[l] = chr[h];
	chr[h] = temp;
	
	}
}




