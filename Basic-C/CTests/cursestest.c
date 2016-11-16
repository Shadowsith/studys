#include <curses.h>
#include <stdlib.h> //noetig fuer atexit()
#include <string.h>

void initializeCursesApplication() {
    initscr();
    noecho();
    cbreak();
    nonl();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
}

void cleanupCursesApp(void)
{
    standend();
    refresh();
    curs_set(1);
    endwin();
}


void quit()
{
  endwin();
  }

  int main(void)
  {
    int x, y, l, c;
    initializeCursesApplication(1);
    //atexit(quit);
    curs_set(0);
    mvprintw(3, 5, "LINES: %d", LINES);
    mvprintw(4, 5, "COLS:  %d", COLS);
    getyx(stdscr, y, x);
    mvprintw(5, 5, "Momentane Cursorposition:  [%d, %d]", y, x);
    getbegyx(stdscr, y, x);
    mvprintw(6, 5, "Koordinatenursprung:       [%d, %d]", y, x);
    getmaxyx(stdscr, y, x);
    mvprintw(7, 5, "Fenstergrösse:              [%d, %d]", y, x);
    l = LINES-1;
    c = COLS-1;
    mvaddch( 0, 0, 'A');
    mvaddch( 0, c, 'B');
    mvaddch( l, 0, 'C');
    mvaddch( l, c, 'D');
    mvaddstr(11, 2, "Taste drücken -> Ende");
    refresh();
    nodelay(stdscr, FALSE);
    getch();

    cleanupCursesApp();
    return(0);

 }
