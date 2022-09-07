double f_random();



int tournoment(IPTR pop, int popsize,int tour_size)
{ 
  double fitness = 0;
  int idx;
  for ( int j = 0 ; j<tour_size ; j++){
	  
	  int rnd = rand()%popsize;
	  if(pop[rnd].fitness > fitness )
	  {
		  fitness = pop[rnd].fitness;
		  idx = rnd;
	  }
	  
  }
  
  return idx;
}


