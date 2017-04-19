#include "ofApp.h"
#include <fstream>

string mentor = "[o_o]>";
string player = "[*-*]";
string pedo = "-v-";
string shopkeeper = "OwO"; //"
string dialog[] = {"There's no time to explain", "It's dangerous out there right now. Take this" /*Sword*/, "It will serve you well. Try not to cut yourself on it...it's sharp!", "I hear them coming, but I'm not finished yet.", "You'll need one of these, too" /* Shield */, "They near. I'll hold them off. Go, run, get out of here...unless...did you get all that?"};

string shield = "[-]";
string sword = "-|=>";
string swordMentor = "[o_o]> -|=>";
string shieldMentor = "[o_o]> [-]";

string bowWieldMentor = "<(-<[o_o]";

ifstream ntte;

vector<string> storyline;

string pressSpace = "Press Space to Continue";

string text;

string *mentorSprite = &mentor;

static int position;

static int currentLine;


bool swordAnim;

void ofApp::setup()
{
  string line;
  ntte.open("/Users/zachamiton/GitHub/NoTimeToExplain/bin/data/NoTimeToExplain.txt");
  if (!ntte) {
    cout << "Unable to open file datafile.txt" << endl;
  }
  
  while(getline(ntte, line))
  {
	storyline.push_back(line);
  }
}

void ofApp::update()
{
 p->Inventory();
}

void ofApp::draw()
{
  cout << currentLine << endl;
  ofBackground(0);
  ofFill();
  ofSetColor(255);
  
  CheckFlagEvents();
  
  ofDrawBitmapString(*mentorSprite, ofGetWidth()/2 - 100, ofGetHeight()/1.5);
  
  if(text.length() == 0)
  {
	text.push_back('[');
  }

  if(position < storyline.at(currentLine).length())
  {
	text.push_back(storyline.at(currentLine)[position]);
	position++;
  }
  if(position == storyline.at(currentLine).length())
  {
	text.push_back(']');
	position++;
  }
	
  ofDrawBitmapString(text, ofGetWidth()/2, ofGetHeight()/2);
  
  ofDrawBitmapString(pressSpace, ofGetWidth()/2, ofGetHeight() - 100);
}

void ofApp::keyPressed(int key)
{
  switch(key)
  {
	case ' ':
	  if(currentLine < storyline.size() && currentLine != 7)
	  {
		if(position < storyline.at(currentLine).length())
		{
		  text = '[' + storyline.at(currentLine);
		  position = storyline.at(currentLine).length();
		  break;
		} else
		{
		  currentLine++;
		  text.clear();
		  position = 0;
		}
	  }
	  break;
	case OF_KEY_TAB:
	  {
		text.clear();
		currentLine = 0;
		position = 0;
	  }
	  break;
  case 'N':
  case 'n':
	if(currentLine == 7)
	{
	  currentLine = 0;
	  text.clear();
	  position = 0;
	}
	break;
  case 'Y':
  case 'y':
	if(currentLine == 7)
	{
	  currentLine++;
	  text.clear();
	  position = 0;
	}
	break;
	
  
  
  
  }
}

void ofApp::keyReleased(int key)
{
  
}

void ofApp::CheckFlagEvents()
{
  mentorSprite = &mentor;
  //Set Flags
  switch(currentLine)
  {
	case 1:
	  p->SetFlags(Player::Sword);
	  break;
	case 4:
	  p->SetFlags(Player::Shield);
	  break;
  }
  
  if(p->GetFlags() & Player::Sword && (currentLine == 1 || currentLine == 2)) //Change Mentor Sprite
  {
	mentorSprite = &swordMentor;
  }
  //Give Sword "Animation"
  if(p->GetFlags() & Player::Shield && currentLine == 4) //Change Mentor Sprite to Shield
  {
	mentorSprite = &shieldMentor;
  }
  
  if(currentLine >= 5 && currentLine <= 7)
  {
	mentorSprite = &bowWieldMentor;
  }
}

//void ofApp::Parse()
//{
//  
//}

