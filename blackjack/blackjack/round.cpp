#include "round.h"

Round::Round(vector<Player> vec_players){
    active_players = vec_players;
    current_player = active_players.begin();
}

bool Round::play(Player* player, int action){
    /*
     actions
     1. stand
     2. hit
     3. double
     */
    
    switch (action) {
        case 1:
            player->stand();
            break;
        case 2:
            player->hit();
            break;
        case 3:
            player->doub();
            break;
        default:
            return false;
            break;
    }
    
    return true;
}

Player* Round::getNextPlayer(){
	current_player += 1;
	return * active_players[current_player];
}
