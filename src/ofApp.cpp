#include "ofApp.h"
using namespace std;

string mentor = "[o_o]>";
string player = "[*-*]";
string pedo = "-v-";
string shopkeeper = "OwO"; //"
string dialog[] = {"There's no time to explain", "It's dangerous out there right now. Take this."};
string sword = "-|->";
string swordMentor = "[o_o]> -|->";

string pressSpace = "Press Space to Continue";

string text;

static int currentLine;
static int position;

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
  
  ofDrawBitmapString(mentor, ofGetWidth()/2 - 100, ofGetHeight()/1.5);
  
  if(text.length() == 0)
  {
	text.push_back('[');
  }

  if(position < dialog[currentLine].length())
  {
	text.push_back(dialog[currentLine][position]);
	position++;
  } else if(position == dialog[currentLine].length())
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
	  if(currentLine < 1)
	  {
		currentLine++;
		text.clear();
		position = 0;
	  }
	  
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
