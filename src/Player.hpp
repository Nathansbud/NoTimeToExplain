//
//  Player.hpp
//  NoTimeToExplain
//
//  Created by Zack Amiton on 4/18/17.
//
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "ofMain.h"

class Player
{
  public:
	Player();
	~Player();
	int GetFlags() {return iFlags;}
	
	enum Items
	{
	  Sword = 1,
	  Shield = 2,
	  Bow = 4,
	  Staff = 8,
	  Potion = 16,
	  Bomb = 32
	};
	
	void SetFlags(Items item);

//	void Update();
	
  private:
	int iFlags;
};

#endif /* Player_hpp */
