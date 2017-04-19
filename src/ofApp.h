#pragma once

#include "ofMain.h"
#include "Player.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
		void Dialog();
		void ItemGet();
		void CheckFlagEvents();

		Player player = Player();
		
		Player *p = &player;

		void keyPressed(int key);
		void keyReleased(int key);
		
		enum Items
		{
		  Sword = 1,
		  Shield = 2,
		  Bow = 4,
		  Staff = 8,
		  Potion = 16,
		  Bomb = 32
		};
		
		void Parse();
};
