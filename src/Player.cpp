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
