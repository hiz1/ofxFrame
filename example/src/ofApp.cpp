#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  frame1 = ofPtr<MyFrame>(new MyFrame(ofRectangle(0             , 0, ofGetWidth()/2, ofGetHeight()), 1));
  frame2 = ofPtr<MyFrame>(new MyFrame(ofRectangle(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight()), 2));
}

//--------------------------------------------------------------
void ofApp::update(){
  frame1->update();
  frame2->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  frame1->draw();
  frame2->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseScrolled(double x, double y) {
  MouseScrollArgs args;
  args.mx = mouseX;
  args.my = mouseY;
  args.sx = x;
  args.sy = y;
  ofNotifyEvent(mouseScrolledEvent, args);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
