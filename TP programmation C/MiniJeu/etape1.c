#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>


/* Fonction d initialisation de ncurses -------------------------------- */
void init_curses()
{
  initscr();
  start_color();
  init_pair(1,COLOR_WHITE,COLOR_BLUE);   //definition des couleurs
  init_pair(2,COLOR_GREEN,COLOR_WHITE);  //definition des couleurs
  init_pair(3,COLOR_RED,COLOR_WHITE);    //definition des couleurs
  curs_set(0);                         // 0 : le curseur n'apparait plus
  noecho();
  keypad(stdscr,TRUE);
  nodelay(stdscr, TRUE);
} 

// une chaine de caractère traverse le terminal

int main(void)
{
	int i;
	init_curses();     
  	bkgd(COLOR_PAIR(1));       // choix des couleurs 
  	
  	
  	for (i=0 ; i<24 ; i++)           // 24: nombres de lignes du terminal par defaut
  	{
		clear();                     // nettoie la fenetre  
		move(i,20);                  // on deplace le curseur 
		
		printw("Je suis une chaine de caracteres qui tombe !");
			
		usleep(200000);        		 // pour ralentir l'affichage
		refresh();
	}
	
	sleep(3);              // pause de 3s avant de quitter le programme 
	endwin();   
  return 0;
	
}

