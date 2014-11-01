//
//  ofxFrame.cpp
//  scroll
//
//  Created by hiz on 2014/11/01.
//
//

#include "ofxFrame.h"

ofEvent<MouseScrollArgs> mouseScrolledEvent;

ofxFrame::ofxFrame(const ofRectangle &rect, const ofVec2f &size) {
  ofRegisterMouseEvents(this);
  ofAddListener(mouseScrolledEvent, this, &ofxFrame::mouseScrolled);
  
  camera.enableOrtho();
  camera.setVFlip(true);
  camPos = ofVec2f(0,0);
  camera.setPosition(camPos.x, camPos.y, 10);
  
  frameRect = ofRectangle(rect);
  contentSize = ofVec2f(size);

}

void ofxFrame::update() {
  camera.setPosition(camPos.x, camPos.y, 10);
  
  updateImpl();
}
void ofxFrame::draw() {
  ofViewport(frameRect.x,frameRect.y,frameRect.width,frameRect.height);
  camera.begin();
  
  drawImpl();
  
  camera.end();
  
  ofViewport();
  
  // frame
  ofSetColor(122);
  ofSetLineWidth(1);
  ofNoFill();
  ofRect(frameRect);
  
  // scroll bar
  ofSetColor(122);
  ofSetLineWidth(4);
  ofLine(frameRect.x + frameRect.width, frameRect.y + (camPos.y / contentSize.y) * frameRect.height,
         frameRect.x + frameRect.width, frameRect.y + ((camPos.y + frameRect.height) / contentSize.y) * frameRect.height);
  ofLine(frameRect.x + (camPos.x / contentSize.x) * frameRect.height, frameRect.y + frameRect.height,
         frameRect.x + ((camPos.x + frameRect.width) / contentSize.x) * frameRect.width, frameRect.y + frameRect.height);
  

}

void ofxFrame::mouseMoved(ofMouseEventArgs &args) {
  int x = args.x, y = args.y;
  if(!frameRect.inside(x, y))return;
  x += camPos.x - frameRect.x;
  y += camPos.y - frameRect.y;
  
  mouseMovedImpl(x, y);
}
void ofxFrame::mouseDragged(ofMouseEventArgs &args) {
  int x = args.x, y = args.y, button = args.button;
  if(!frameRect.inside(x, y))return;
  x += camPos.x - frameRect.x;
  y += camPos.y - frameRect.y;
  
  mouseDraggedImpl(x, y, button);
}
void ofxFrame::mousePressed(ofMouseEventArgs &args) {
  int x = args.x, y = args.y, button = args.button;
  if(!frameRect.inside(x, y))return;
  x += camPos.x - frameRect.x;
  y += camPos.y - frameRect.y;
  
  mousePressedImpl(x, y, button);
}
void ofxFrame::mouseReleased(ofMouseEventArgs &args) {
  int x = args.x, y = args.y, button = args.button;
  
  mouseReleasedImpl(x, y, button);
  
}
void ofxFrame::mouseScrolled(MouseScrollArgs &args) {
  if(!frameRect.inside(args.mx, args.my))return;
  camPos += ofVec2f(-args.sx,-args.sy);
  if(camPos.x < 0                                 )camPos.x = 0;
  if(camPos.x > (contentSize.x - frameRect.width) )camPos.x = contentSize.x - frameRect.width;
  if(camPos.y < 0                                 )camPos.y = 0;
  if(camPos.y > (contentSize.y - frameRect.height))camPos.y = contentSize.y - frameRect.height;
  
  mouseScrolledImpl(args.mx, args.my, args.sx, args.sy);
}

void  ofxFrame::setRect(ofRectangle rect) {
  this->frameRect = rect;
}
void  ofxFrame::setContentSize(ofVec2f size) {
  this->contentSize = size;
}
const ofRectangle &ofxFrame::getRect() {
  return frameRect;
}
const ofVec2f     &ofxFrame::getContentSize() {
  return contentSize;
}

void ofxFrame::updateImpl() {}

void ofxFrame::drawImpl() {}

void ofxFrame::mouseMovedImpl(int x, int y) {}
void ofxFrame::mouseDraggedImpl(int x, int y, int button) {}
void ofxFrame::mousePressedImpl(int x, int y, int button) {}
void ofxFrame::mouseReleasedImpl(int x, int y, int button) {}
void ofxFrame::mouseScrolledImpl(int mx, int my, int sx, int sy) {}
