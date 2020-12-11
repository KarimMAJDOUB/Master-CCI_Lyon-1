#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* Fonction d initialisation de ncurses -------------------------------- */
void init_curses()
{
  initscr();
  start_color();
  init_pair(1,COLOR_WHITE,COLOR_BLUE);   
  init_pair(2,COLOR_GREEN,COLOR_WHITE);
  init_pair(3,COLOR_RED,COLOR_WHITE);
  curs_set(0);
  noecho();
  keypad(stdscr,TRUE);
  nodelay(stdscr, TRUE);
} 


int operationAleatoire(int difficulte, int *a, int *b, char *op)
{
	// a op b
	 int n;
	 char operateur[]={'+','-','*','/','%'};  
	
	*b = rand()%difficulte;
	*a = *b + rand()%(difficulte - *b); // pour n'avoir que des resultats positifs a>=b et a,b dans l intervalle [0 .. 9]
	 n = rand()%3 ;     // choix de l'opération parmi + - * 
	 *op = operateur[n];
	 switch (n)                  // renvoi du resultat de l'operation 
	 {
		 case 0 : return (*a) + (*b);
		 case 1 : return (*a) - (*b);
		 case 2 : return (*a) * (*b);
	     case 3 : return (*a) / (*b);
	     case 4 : return (*a) % (*b);
	 }			
}

// version sans l'instruction switch 

int operationAleatoire_V2(int difficulte, int *a, int *b, char *op)
{
	// a op b
	 int n;
	 char operateur[]={'+','-','*','/','%'};  
	
	*b = rand()%difficulte;
	*a = *b + rand()%(difficulte - *b); // pour n'avoir que des resultats positifs a>=b et a,b dans l intervalle [0 .. 9]
	 n = rand()%3 ;     // choix de l'opération parmi + - * 
	 *op = operateur[n];
	 
	 if (n==0)
		return (*a) + (*b);
	 else
		if (n==1)
			return (*a) - (*b);
		else
			if (n==2)
				return (*a) * (*b);			
				
}



int main(void)
{
	int i,a,b,res;
	char op;
	
	srand(time(NULL));
	init_curses();     
  	bkgd(COLOR_PAIR(1)); 
  	
  	res = operationAleatoire(10,&a, &b, &op);
  	for (i=0 ; i<24 ; i++)
  	{
		clear();
		move(i,20);
		printw("%d %c %d ",a,op,b);
		
		usleep(200000);
		refresh();
	}
	
	sleep(3);
	endwin();   
  return 0;
	
}

