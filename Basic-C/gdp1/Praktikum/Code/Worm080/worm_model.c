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
enum ResCodes initializeWorm(struct worm* aworm, int len_max, int len_cur, 
                             struct pos headpos, enum WormHeading dir, 
                             enum ColorPairs color) {
      
     // Local Variables
    
    int i;

    // Initialize last usable index
    aworm->maxindex = len_max - 1;
    // Current last usable index in array 
    aworm->cur_lastindex = len_cur - 1;

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

void growWorm(struct worm* aworm, enum Boni growth){
    // Play it save and inhibit surpassing the bound 
    if (aworm->cur_lastindex + growth <= aworm->maxindex) {
        aworm->cur_lastindex += growth;
    } else {
        aworm->cur_lastindex = aworm->maxindex;
    }
}


// Show the worms's elements on the display
// Simple version
void showWorm(struct board* aboard, struct worm* aworm) {
    //struct pos headpos = aworm->wormpos[aworm->headindex];
    int tailindex = (aworm->headindex + 1) % getWormLength(aworm);
    int i = aworm->headindex;
    
    while (aworm->wormpos[tailindex].x == UNUSED_POS_ELEM)
    {
     tailindex = (tailindex +1) % getWormLength(aworm);
    }
   
    do {
            placeItem(
                aboard,
                aworm->wormpos[i].y,
                aworm->wormpos[i].x,
                BC_USED_BY_WORM,
                SYMBOL_WORM_INNER_ELEMENT,
                aworm->wcolor
                );

    i = (i + aworm->cur_lastindex) % (aworm->cur_lastindex + 1); 
    } while ( i != aworm->headindex && aworm->wormpos[i].y != UNUSED_POS_ELEM );

    
            placeItem(
                aboard,
                aworm->wormpos[aworm->headindex].y,
                aworm->wormpos[aworm->headindex].x,
                BC_USED_BY_WORM,
                SYMBOL_WORM_HEAD_ELEMENT,
                aworm->wcolor
                );
    
            placeItem(
                aboard,
                aworm->wormpos[tailindex].y,
                aworm->wormpos[tailindex].x,
                BC_USED_BY_WORM,
                SYMBOL_WORM_TAIL_ELEMENT,
                aworm->wcolor
                );
    
}



         /*   placeItem(
                aboard,
                aworm->wormpos[aworm->headindex].y,
                aworm->wormpos[aworm->headindex].x,
                BC_USED_BY_WORM,
                SYMBOL_WORM_HEAD_ELEMENT,
                aworm->wcolor
                );
            
            placeItem(
                aboard,
                aworm->wormpos[tailindex].y,
                aworm->wormpos[tailindex].x,
                BC_USED_BY_WORM,
                SYMBOL_WORM_TAIL_ELEMENT,
                aworm->wcolor
                ); */
    
	        
    
        
   /* 
   placeItem(
            aboard,
            aworm->wormpos[aworm->headindex].y,
            aworm->wormpos[aworm->headindex].x,
            BC_USED_BY_WORM,
            SYMBOL_WORM_HEAD_ELEMENT,
	    aworm->wcolor
	    );*/

    /*
    do {
    // Compare the position of the current worm element with the new_headpos
    placeItem(
            aboard,
            aworm->wormpos[i].y,
            aworm->wormpos[i].x,
            BC_USED_BY_WORM,
            SYMBOL_WORM_INNER_ELEMENT,
	    aworm->wcolor
	    );  
    i = (i + aworm->cur_lastindex) % (aworm->cu_index + 1); 
    } while ( i != aworm->headindex && aworm->wormpos[i].y != UNUSED_POS_ELEM );*/
    
 

// Pos BLACK_BLACK ELEMENT in ARR
void cleanWormTail( struct board* aboard, struct worm* aworm) {
    int tailindex = (aworm->headindex + 1) % (aworm->cur_lastindex + 1);
    
    if(aworm->wormpos[tailindex].y != UNUSED_POS_ELEM) {
      placeItem(
         aboard,
         aworm->wormpos[tailindex].y,
         aworm->wormpos[tailindex].x, 
         BC_FREE_CELL,
         SYMBOL_FREE_CELL,
         COLP_FREE_CELL
         );
  }
}
void moveWorm(struct board* aboard, struct worm* aworm, enum GameStates *agame_state) {
    // Compute and store new head position according to current heading.
  struct pos headpos = aworm->wormpos[aworm->headindex];
  headpos.y += aworm->dy;
  headpos.x += aworm->dx;

    // Check if we would leave the display if we move the worm's head according
    // to worm's last direction.
    // We are not allowed to leave the display's window.
    if (headpos.x < 0) {
        *agame_state = WORM_OUT_OF_BOUNDS;
    } else if (headpos.x > getLastColOnBoard(aboard) ) { 
        *agame_state = WORM_OUT_OF_BOUNDS; 
    } else if (headpos.y < 0) {  
        *agame_state = WORM_OUT_OF_BOUNDS; // @011
	} else if (headpos.y > getLastRowOnBoard(aboard) ) {
        *agame_state = WORM_OUT_OF_BOUNDS; //@011
    } else {
       // We will stay within bounds.
    }
// Check if the worms head hits any items at the new position on the board.
    // Hitting food is good, hitting barriers on worm elements is bad.
    switch ( getContentAt(aboard,headpos) ){
        case BC_FOOD_1:
            *agame_state = WORM_GAME_ONGOING;
            // Grow worm according to food item digested
            growWorm(aworm, BONUS_1);
            decrementNumberOfFoodItems(aboard);
            break;
        case BC_FOOD_2:
            *agame_state = WORM_GAME_ONGOING;
            growWorm(aworm, BONUS_2);
            decrementNumberOfFoodItems(aboard);
            break;
        case BC_FOOD_3:
            *agame_state = WORM_GAME_ONGOING;
            growWorm(aworm, BONUS_3);
            decrementNumberOfFoodItems(aboard);
            break;
        case BC_BARRIER:
            // That's bad: stop game
            *agame_state = WORM_CRASH;
            break;
        case BC_USED_BY_WORM:
            // That's bad: stop game
            *agame_state = WORM_CROSSING;
            break;
        default:
            // Without default case we get a warning message
        {;} // Do nothing. C syntax dicates some statement, here.
    }
    // Check the status of  *agame_state
    // Go on if nothing bad happened
   if (*agame_state == WORM_GAME_ONGOING)  {
     // So all is well: We did not hit anything
     // Window --> Update the worm structure.
     // Increment headindex
     // Go round if end of worm is reached (ring buffer)
     aworm->headindex++;
     if (aworm->headindex > aworm->cur_lastindex) {
         aworm->headindex = 0;
     }
     // Store new coordinates of head element in worm structure
     aworm->wormpos[aworm->headindex] = headpos;
    } 

}

// Getters
struct pos getWormHeadPos (struct worm* aworm){
    return aworm->wormpos[aworm->headindex];
}

int getWormLength(struct worm* aworm){
    return aworm->cur_lastindex + 1;
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


