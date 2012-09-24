#include "Lists.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppNative.h"
#include "cinder/Text.h"
#include "cinder/Utilities.h"
#include "cinder/ImageIo.h"
#include "Resources.h"




using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
  public:
    Lists* circList;
	void setup();
	void keyDown( KeyEvent event );
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	

	
	private:
	static const int kAppWidth = 800;
	static const int kAppHeight = 600;
	static const int textureSize = 1024;
	static const bool PREMULT = false;
	int cnt;
	list<Vec2f>		mPoints;
	bool help;
		
};

	

	void HW02App::prepareSettings(Settings* settings){
	(*settings).setWindowSize(kAppWidth,kAppHeight);
	(*settings).setResizable(false);

	}

	void HW02App::setup() {
	circList = new Lists;
    circList->circ_sentinel = new Circle;
    circList->circ_sentinel->next = circList->circ_sentinel;
    circList->circ_sentinel->previous = circList->circ_sentinel;
	circList->circ_sentinel->radius = 30;
	circList->circ_sentinel->pos_X=200;
	circList->circ_sentinel->pos_Y=0;
    Circle* next;
	next=circList->insertAfter(circList->circ_sentinel, 400, 50);
	next=circList->insertAfter(next,100  , 250);
	for(int i=1; i<7; i++) {
	 next= circList->insertAfter(next, (circList->circ_sentinel->pos_X) ,  (circList->circ_sentinel->pos_X)+50*i);
	}
	for(int i=1; i<7; i++) {
	 next= circList->insertAfter(next, (circList->circ_sentinel->pos_X)+400 ,  (circList->circ_sentinel->pos_X)+50*i);
	}
	next=circList->insertAfter(next, 700, 250);

	cnt=0;
}
void HW02App::keyDown(cinder::app::KeyEvent event )
	{
	if(event.isShiftDown())
	circList->reverse();

	}

void HW02App::mouseDown( MouseEvent event )
{
	if(event.isRightDown())
	circList->reverse();
	Circle* current = circList->circ_sentinel->next;
	while(current!= circList->circ_sentinel) {
	if(circList->isInside(event.getX(), event.getY(),current)) {
		circList->moveToFront(current);
		current=circList->circ_sentinel;
	}
	else {
		current = current->next;
	}
	}
	
	

}


void HW02App::update()
	
{
	
	
}
void HW02App::draw()
{
	
	
	
    Circle* current = circList->circ_sentinel->next;
	
    while(current!= circList->circ_sentinel){
		gl::color(current->color);
		gl::drawSolidCircle(Vec2f(current->pos_X, current->pos_Y), current->radius,0);
		current = current->next;
    }    
	
}



CINDER_APP_BASIC( HW02App, RendererGl )


