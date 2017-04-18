#include "ofApp.h"
using namespace std;

string mentor = "[o_o]>";
string player = "[*-*]";
string pedo = "-v-";
string shopkeeper = "OwO"; //"
string dialog[] = {"There's no time to explain", "It's dangerous out there right now. Take this" /*Sword*/, "It will serve you well. Try not to cut yourself on it...it's sharp!", "I hear them coming, but I'm not finished yet.", "You'll need one of these, too" /* Shield */, "They near. I'll hold them off. Go, run, get out of here...unless...did you get all that?"};

string shield = "[-]";
string sword = "-|=>";
string swordMentor = "[o_o]> -|=>";
string shieldMentor = "[o_o]> [-]";

string pressSpace = "Press Space to Continue";

string text;

string *mentorSprite = &mentor;

static int position;

static int currentLine;


bool swordAnim;

void ofApp::setup()
{

}

void ofApp::update()
{
 
}

void ofApp::draw()
{
  ofBackground(0);
  ofFill();
  ofSetColor(255);
  
  CheckFlagEvents();
  
  ofDrawBitmapString(*mentorSprite, ofGetWidth()/2 - 100, ofGetHeight()/1.5);
  
  if(text.length() == 0)
  {
	text.push_back('[');
  }

  if(position < dialog[currentLine].length())
  {
	text.push_back(dialog[currentLine][position]);
	position++;
  }
  if(position == dialog[currentLine].length())
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
	  if(position == dialog[currentLine].length())
	  {
		if(currentLine < 5)
		{
		  currentLine++;
		  text.clear();
		  position = 0;
		}
	  } else if (position < dialog[currentLine.length()))
	  break;
	case OF_KEY_TAB:
	  {
		text.clear();
		currentLine = 0;
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
  //Set Flags
  switch(currentLine)
  {
	case 1:
	  p->SetFlags(Player::Sword);
	  break;
	case 5:
	  p->SetFlags(Player::Shield);
	  break;
  }
  
  if(p->GetFlags() & Player::Sword && (currentLine == 1 || currentLine == 2)) //Change Mentor Sprite
  {
	  mentorSprite = &swordMentor;
  } else
  {
	mentorSprite = &mentor;
  }
  
 

  //Give Sword "Animation"
  if(p->GetFlags() & Player::Shield && currentLine == 5) //Change Mentor Sprite to Shield
  {
	mentorSprite = &shieldMentor;
  }
}

////void ofApp::mouseMoved(int x, int y ){
//
//}
//
////void ofApp::mouseDragged(int x, int y, int button){
//
//}
//
////void ofApp::mousePressed(int x, int y, int button){
//
//}
//
////void ofApp::mouseReleased(int x, int y, int button){
//
//}
//
////void ofApp::mouseEntered(int x, int y){
//
//}
//
////void ofApp::mouseExited(int x, int y){
//
//}
//
////void ofApp::windowResized(int w, int h){
//
//}
//
////void ofApp::gotMessage(ofMessage msg){
//
//}
//
////void ofApp::dragEvent(ofDragInfo dragInfo){ 
//
//}
//
//
//
//
//
