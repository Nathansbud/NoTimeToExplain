//
//  Player.cpp
//  NoTimeToExplain
//
//  Created by Zack Amiton on 4/18/17.
//
//

#include "Player.hpp"

Player::Player()
{
  
}

Player::~Player()
{

}

//void Player::Update()
//{
//  
//}

void Player::SetFlags(Items item)
{
  iFlags = iFlags | item;
}

void Player::Inventory()
{
  for(int i = 0; i < 9; i++)
  {
	if((iFlags & (1 << i)) != 0)
	{
	  cout << "You have dis" << endl;
	} else
	{
	  cout << "You lack dis" << endl;
	}
  }
}

bool Player::CheckFlags(Items item)
{
  if((iFlags & item) != 0)
  {
	return true;
  }
}

void Player::RemoveFlags(Items item)
{
//  if(iFlags & item)
//  {
//	iFlags = iFlags ~ item;
//  }
}

//void Player::Inventory(Items item)
//{
// foreach(items in )
//}
