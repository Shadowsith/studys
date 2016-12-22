// A simple variant of the game Snake
//
// Used for teaching in classes
//
// Author:
// Franz Regensburger
// Ingolstadt University of Applied Sciences
// (C) 2011
//
// The worm model
// Data defining the worm
#include <curses.h>
#include "worm.h"
#include "board_model.h"
#include "worm_model.h"
  
// START WORM_DETAIL
// The following functions all depend on the model of the worm

// Initialize the worm
enum ResCodes initializeWorm(struct worm* aworm, int len_max, struct pos headpos, enum WormHeading dir, enum ColorPairs color) {
      
     // Local Variables
    
    int i;

    // Initialize last usable index
    aworm->maxindex = len_max - 1;

    // initialize headindex: theworm_headindex
    aworm->headindex = 0;

    // Mark all elements as unused in the arrays of positions
    // theworm_wormpos_y[] and theworm_wormpos_x[]
    for(i = 1; i <= aworm->maxindex; i++) {
      aworm->wormpos[i].y = UNUSED_POS_ELEM;
      aworm->wormpos[i].x = UNUSED_POS_ELEM;
    }

    // Initialize position of worms head
    aworm->wormpos[aworm->headindex] = headpos;

    // Initialize the heading of the worm
    setWormHeading(aworm, dir);

    // Initialze color of the worm
    aworm->wcolor = color;

    return RES_OK;
}

// Show the worms's elements on the display
// Simple version
void showWorm(struct worm* aworm) {
    // Due to our encoding we just need to show the head element
    // All other elements are already displayed
    placeItem(
            aworm->wormpos[aworm->headindex],
            SYMBOL_WORM_INNER_ELEMENT,
	    aworm->wcolor
	    );
}

// Pos BLACK_BLACK ELEMENT in ARR
void cleanWormTail(struct worm* aworm) {
    int tailindex = (aworm->headindex + 1) % (aworm->maxindex + 1);
    
    if(aworm->wormpos[tailindex].y != UNUSED_POS_ELEM) {
      placeItem(
         aworm->wormpos[tailindex],
         SYMBOL_FREE_CELL,
         COLP_FREE_CELL
         );
  }
}
void moveWorm(struct worm* aworm, enum GameStates *agame_state) {
    // Compute and store new head position according to current heading.
  struct pos headpos = aworm->wormpos[aworm->headindex];
  headpos.y += aworm->dy;
  headpos.x += aworm->dx;

    // Check if we would leave the display if we move the worm's head according
    // to worm's last direction.
    // We are not allowed to leave the display's window.
    if (headpos.x < 0) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.x > getLastCol() ) { 
        *agame_state = WORM_OUT_OF_BOUNDS; 
    } else if (headpos.y < 0) {  
        *agame_state = WORM_OUT_OF_BOUNDS; // @011
	} else if (headpos.y > getLastRow() ) {
        *agame_state = WORM_OUT_OF_BOUNDS; //@011
    } else {
        if(isInUseByWorm(aworm, headpos)) {
          *agame_state = WORM_CROSSING;
    }
    
   if (*agame_state == WORM_GAME_ONGOING)  {
     // So all is well: We did not hit anything
     aworm->headindex = (aworm->headindex + 1) % (aworm->maxindex + 1);
     aworm->wormpos[aworm->headindex] = headpos;
  } 
}
}

// A simble collision detection
bool isInUseByWorm(struct worm* aworm, struct pos new_headpos) {
  int i;
  bool collision = false;
  i = aworm->headindex;
  do {
    // Compare the position of the current worm element with the new_headpos
    if (aworm->wormpos[i].y == new_headpos.y && 
        aworm->wormpos[i].x == new_headpos.x) {
      collision = true;
      break;
    }
    i = (i + aworm->maxindex) % (aworm->maxindex + 1);


  } while ( i != aworm->headindex && aworm->wormpos[i].y != UNUSED_POS_ELEM );
  
  return collision;

}

// Getters

struct pos getWormHeadPos (struct worm* aworm)
{
    return aworm->wormpos[aworm->headindex];

}
// Setters
void setWormHeading(struct worm* aworm, enum WormHeading dir) {
    switch(dir) {
        case WORM_UP :// User wants up
            aworm->dx=0;
            aworm->dy=-1;
            break;
        case WORM_DOWN :// User wants down
            aworm->dx =0;  
            aworm->dy =1;  
            break;
        case WORM_LEFT :// User wants left
            aworm->dx =-1;    
            aworm->dy =0;    
            break;
        case WORM_RIGHT :// User wants right
            aworm->dx =1;    
            aworm->dy =0;    
            break;
    }
} 

// END WORM_DETAIL
// ********************************************************************************************


