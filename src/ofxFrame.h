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

enum Resize {
  SIZE=1, POS=2, X=4, Y=8
};

extern ofEvent<MouseScrollArgs> mouseScrolledEvent;
extern const int RESIZE_SIZE;
extern const int RESIZE_POS;
extern const int RESIZE_X;
extern const int RESIZE_Y;
extern const int RESIZE_ALL;

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
  void windowResized(ofResizeEventArgs &args);
  void setRect(ofRectangle rect);
  void setContentSize(ofVec2f size);
  void setResizeFlag(int resizeFlag);
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
  ofRectangle frameRect;
  ofVec2f contentSize;
private:
  ofVec2f windowSize;
  ofVec2f camPos;
  ofCamera camera;
  int  resizeFlag;
};

#endif /* defined(__scroll__ofxFrame__) */
