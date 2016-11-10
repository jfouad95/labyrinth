#include <curses.h>

void initialize() {
	initscr();
	raw();
	noecho();
	nonl();
	intrflush( stdscr, FALSE );
	keypad( stdscr, TRUE );
}

void finalize() { 
	endwin();
}
void delscreen(SCREEN *screen);

int x = 10, y= 20;
bool a = true;

int main() {
	int ch;
	initialize();

	while (a) {
		
		curs_set(0);
		wclear( stdscr );
		wmove( stdscr, x, y );
		waddch( stdscr, ACS_DIAMOND );

		wrefresh( stdscr );

		ch = wgetch( stdscr);
		switch (ch) {
			case KEY_UP: 
//				wrefresh( stdscr );
//				mvaddch( y, x-1, ACS_DIAMOND );
				x -= 1;
				break;
			case KEY_DOWN:
//				wrefresh( stdscr );
//				mvaddch( y, x+1, ACS_DIAMOND );
				x += 1;
				break;
			case KEY_LEFT:
//				wrefresh( stdscr );
//				mvaddch( y-1, x, ACS_DIAMOND );
				y -= 1;
				break;			
			case KEY_RIGHT:
//				wrefresh( stdscr );
//				mvaddch( y+1, x, ACS_DIAMOND );
				y += 1;
				break;
			case KEY_BACKSPACE:
				a = false;
				wrefresh( stdscr );
				finalize();
				break;
			default:
				break;
				
		}
		if(!a) {
			endwin();
			break;
		}
	}
	
	finalize();
	return 0;
}


