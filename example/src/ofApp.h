#pragma once

#include "ofMain.h"
#include "ofxFrame.h"

class MyFrame : public ofxFrame {
public:
  MyFrame(const ofRectangle &rect, int no) : ofxFrame(rect, ofVec2f(1000,1000)) {
    this->no = no;
  }
  virtual void drawImpl() {
    ofSetColor(255);
    ofSetLineWidth(1);
    ofNoFill();
    for(int x=0;x<contentSize.x;x+=100) {
      for(int y=0;y<contentSize.y;y+=100) {
        ofRect(x,y,100,100);
      }
    }
  }
  virtual void mouseMovedImpl(int x, int y) {
    ofLogNotice() << "[" << no << "]" << "mouseMoved:" << x << ","<< y;
  }
  virtual void mouseDraggedImpl(int x, int y, int button) {
    ofLogNotice() << "[" << no << "]" << "mouseDraggd(" << button << "):" << x << ","<< y;
  }
  virtual void mousePressedImpl(int x, int y, int button) {
    ofLogNotice() << "[" << no << "]" << "mousePressed(" << button << "):" << x << ","<< y;
  }
  virtual void mouseReleasedImpl(int x, int y, int button) {
    ofLogNotice() << "[" << no << "]" << "mouseReleased(" << button << "):" << x << ","<< y;
  }
  virtual void mouseScrolledImpl(int mx, int my, int sx, int sy) {
    ofLogNotice() << "[" << no << "]" << "mouseScrolled:" << mx << ","<< my << ":" << sx << "," << sy;
  }
private:
  int no;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
    void mouseScrolled(double x, double y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
  
  ofPtr<MyFrame> frame1;
  ofPtr<MyFrame> frame2;
		
};
