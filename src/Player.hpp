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
	
	enum Items //ul = unsigned long
	{
	  Sword = 1 << 0,
	  Shield = 1 << 1,
	  Bow = 1 << 2,
	  Staff = 1 << 3,
	  Potion = 1 << 4,
	  Bomb = 1 << 5, 
	  Spell = 1 << 6,
	  Food = 1 << 7,
	  Knife = 1 << 8
	};
	
	void SetFlags(Items item);
	void RemoveFlags(Items item);
	bool CheckFlags(Items item);
	
	void Inventory();

//	void Update();
	
  private:
	int iFlags;
};

#endif /* Player_hpp */
