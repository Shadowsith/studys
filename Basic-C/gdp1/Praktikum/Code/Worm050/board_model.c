// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//
// The board model
#include <curses.h>
#include "worm.h"
#include "board_model.h"

void placeItem(struct pos apos, chtype symbol, enum ColorPairs color_pair) {

    //  Store item on the display (symbol code)
    move(apos.y, apos.x);						// Move cursor to (y,x)
    attron(COLOR_PAIR(color_pair));				// Start writing in selected color
    addch(SYMBOL_WORM_INNER_ELEMENT);           // Store symbol on the virtual display
    attroff(COLOR_PAIR(color_pair));			// Stop writing in selected color
}

int getLastRow() {
    return LINES-1 - ROWS_RESERVED;
}

// Get the last usable column on the display
int getLastCol() {
    return COLS-1;
}
