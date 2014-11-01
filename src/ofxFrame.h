//
//  ofxFrame.h
//  scroll
//
//  Created by hiz on 2014/11/01.
//
//

#ifndef __scroll__ofxFrame__
#define __scroll__ofxFrame__


#include "ofMain.h"

class MouseScrollArgs : public ofEventArgs {
public:
  float mx, my; // mouse position
  float sx, sy; // scroll 
};

extern ofEvent<MouseScrollArgs> mouseScrolledEvent;

class ofxFrame {
public:
  ofxFrame(const ofRectangle &rect, const ofVec2f &size);
  void update();
	void draw();
  void mouseMoved(ofMouseEventArgs &args);
	void mouseDragged(ofMouseEventArgs &args);
	void mousePressed(ofMouseEventArgs &args);
	void mouseReleased(ofMouseEventArgs &args);
  void mouseScrolled(MouseScrollArgs &args);
  void setRect(ofRectangle rect);
  void setContentSize(ofVec2f size);
  const ofRectangle &getRect();
  const ofVec2f     &getContentSize();
  
  virtual void updateImpl();
  virtual void drawImpl();
  virtual void mouseMovedImpl(int x, int y);
  virtual void mouseDraggedImpl(int x, int y, int button);
  virtual void mousePressedImpl(int x, int y, int button);
  virtual void mouseReleasedImpl(int x, int y, int button);
  virtual void mouseScrolledImpl(int mx, int my, int sx, int sy);
protected:
  ofCamera camera;
  ofVec2f camPos;
  ofRectangle frameRect;
  ofVec2f contentSize;
};

#endif /* defined(__scroll__ofxFrame__) */
