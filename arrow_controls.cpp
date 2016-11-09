#include <curses.h>

void initialize() {
	initscr();
	(void) raw();
	noecho();
	nonl();
	intrflush( stdscr, FALSE );
	(void) keypad( stdscr, TRUE );
}

void finalize() { 
	endwin();
}

int main() {
	int ch;
	int x = 20, y= 20;

	initialize();
	while (1) {
		
		wclear( stdscr );
		wmove( stdscr, x, y );
		waddch( stdscr, ACS_BULLET );

//		wmove( stdscr, 6, 10);
//		wprintw( stdscr, (char*)"There are %d lines and %d columns.", LINES, COLS );
	
//		wmove( stdscr, 10, 0);
//		waddch( stdscr, '?' );

		wrefresh( stdscr );

		ch = wgetch( stdscr);
		switch (ch) {
			case KEY_UP: 
				wrefresh( stdscr );
				mvwaddch( x, y+1, ACS_BULLET );
			case KEY_DOWN:
				wrefresh( stdscr );
				mvwaddch( x, y-1, ACS_BULLET );
			case KEY_LEFT:
				wrefresh( stdscr );
				mvwaddch( x-1, y, ACS_BULLET );
			case KEY_RIGHT:
				wrefresh( stdscr );
				mvwaddch( x+1, y, ACS_BULLET );
			case KEY_ENTER:
				finalize();
				return(0);
				break;
		}
	}
	
	finalize();
	return 0;
}


