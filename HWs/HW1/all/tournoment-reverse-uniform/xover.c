int rnd(int low, int high);
int flip(double);
void muteX_reverse(POPULATION *p, int* pa);

void crossover_Uniform(POPULATION *p, IPTR p1, IPTR p2, IPTR c1, IPTR c2)
{
/* p1,p2,c1,c2,m1,m2,mc1,mc2 */
  int *pi1,*pi2,*ci1,*ci2;
  int xp, i;

  pi1 = p1->chrom;
  pi2 = p2->chrom;
  ci1 = c1->chrom;
  ci2 = c2->chrom;
  
  
	
	muteX_reverse(p, pi1);
	muteX_reverse(p, pi2);
	
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

void muteX_reverse(POPULATION *p, int* chr)
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
	
	for( int i = l ; i <= l+(h-l)/2 ;i++){
		int tmp = chr[i]; 
		chr[i] = chr[h-i];
		chr[h-i] = tmp;
	}

	}
}

