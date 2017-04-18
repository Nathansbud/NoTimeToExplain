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
  iFlags = iFlags | Sword;
}

Player::~Player()
{

}

void Player::SetFlags(Items item)
{
  iFlags = iFlags | item;
}
