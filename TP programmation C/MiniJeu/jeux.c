#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ESCAPE 27
#define ESPACE 32
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
} 

int operationAleatoire(int difficulte, int *a, int *b, char *op)
{
	 //op=0,1,2,3  +,-,*,/
	 int n;
	
	*b = rand()%difficulte;
	*a = *b + rand()%difficulte;
	 n = rand()%3 ; 
	
	 if (n==0)
	 {
	 	*op='+';
	 	return *a + *b;
	 }
	 else
	 	if (n==1)
	 	{
	 		*op = '-';
	 		return *a - *b;
		}
	 	else
	 		if (n==2)
	 		{
	 			*op = '*';
	 			return *a * *b;
			}
	 		else
	 		{
	 		 	*op = '/';	
	 		 	return *a / *b;	
			}	 				
}

void initTab(int tabKey[],int n)
{
	int i;
	
	for (i=0 ; i<n ; i++)
		tabKey[i] = 0;
}

int key2int(int tabKey[], int n)
{
	int i,key=0,p=1;
	
	for (i=n-1 ; i>=0 ; i--)
	{
		key += p*(tabKey[i]-'0');
		p = 10*p;
	}
	return key;	
}

int  evalueKey(int key,int tab[], int *n)
{
	if (key==ESPACE)
	{
		initTab(tab,*n);
		*n=0;
		return RIEN;
	}
	
	tab[*n]=key;
	(*n)++;
	
	return key2int(tab,*n);
}

int main(void)
{
	int i,a,b,key,n,res,val=RIEN,tabKey[10];
	int colonne=20;
	int score = 0;
	char op;
	
	srand(time(NULL));
	init_curses();     
  	bkgd(COLOR_PAIR(1)); 
  	nodelay(stdscr, TRUE);
  	res = operationAleatoire(10,&a, &b, &op);
    
    initTab(tabKey,10);
	n=0;
  	for (i=0 ; i<24 ; i++)
  	{
		clear();
		
		key=getch();
		if (key!=ERR)
			val = evalueKey(key, tabKey, &n);
			
		move(0,0);
		if (val != RIEN)
		    printw("%d",val);
		
		if (key!=ERR && (val==res))
		{
			initTab(tabKey,n);
			n=0;
			move(i,colonne);
			printw("bravo");
			refresh();
			score++;
			
			colonne = 10 + rand()%70; 
			val = RIEN;
			
			usleep(500000);
			res = operationAleatoire(10,&a, &b, &op);
			i=0;
			clear();
			refresh();
		}
		move(23,70);
		printw("score : %d",score);refresh();
		refresh();
		move(i,colonne);
		printw("%d %c %d ",a,op,b);
		refresh();
		
		usleep(500000);
		refresh();
	}
	clear();
	
	move(10,40);
	printw("Game over !");
	move(11,40);
	printw("Votre score : %d",score);
	refresh();
	sleep(3);
	endwin();   
  return 0;
	
}
