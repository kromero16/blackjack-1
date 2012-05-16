//
//  main.h
//  blackjack
//
//  Created by pedro on 4/22/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef main_h
#define main_h

#include <iostream>
#include <limits>
#include <ctime>

#include "player.h"
#include "round.h"
#include "card.h"
#include "dealer.h"
#include "game.h"
#include "hand.h"
#include "house.h"
#include "ui.h"

#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#define cout "wcout"
#endif

using namespace std;

#endif
