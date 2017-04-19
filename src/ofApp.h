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
		
		void Parse();
		
		void SwordAcquired();
};
