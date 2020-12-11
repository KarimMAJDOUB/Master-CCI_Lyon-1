#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


#define RIEN -99999

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
  nodelay(stdscr, TRUE);  // pour que la fonction getch() ne soit pas bloquante
} 

int operationAleatoire(int difficulte, int *a, int *b, char *op)
{
	 int n;
	 char operateur[]={'+','-','*','/','%'};
	
	*b = rand()%difficulte;
	*a = *b + rand()%difficulte;
	 n = rand()%3 ; 
	 *op = operateur[n];
	 switch (n)
	 {
		 case 0 : return *a + *b;
		 case 1 : return *a - *b;
		 case 2 : return (*a) * (*b);
	     case 3 : return *a / *b;
	     case 4 : return *a % *b;
	 }			
}


int main(void)
{
	int i,a,b,res,key;
	char op;
	
	srand(time(NULL));
	init_curses();     
  	bkgd(COLOR_PAIR(1)); 
  	
  	res = operationAleatoire(10,&a, &b, &op);
  	
  	for (i=0 ; i<24 ; i++)
  	{
		clear();
		key=getch();     // key contient le code de la touche sur laquelle on a appuye 
		if (key!=ERR )   // ERR si on n'a pas appuye sur aucune touche 
		{
			move(0,0);
			printw("%d ",key-'0'); // on affiche en haut a gauche la val de la touche 
			refresh();
			
			if (res == (key-'0'))
			{
				move(i,20);
				printw("bravo");
				refresh();
				usleep(300000);
			}
		}
		
		move(i,20);
		printw("%d %c %d ",a,op,b);
		refresh();
		usleep(300000);
		refresh();
	}
	
	sleep(3);
	endwin();   
  return 0;
	
}

