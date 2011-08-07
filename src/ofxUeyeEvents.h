#ifndef _OFX_UEYE_EVENTS
#define _OFX_UEYE_EVENTS

#include "ofMain.h"

class ofxUeyeEventArgs{};

class ofxUeyeEvents{	
public:
	ofxUeyeEventArgs			voidEventArgs;

	ofEvent<ofxUeyeEventArgs>	ready;
	ofEvent<ofxUeyeEventArgs>	newFrame;
	ofEvent<ofxUeyeEventArgs>	dimensionChanged;
	//ofEvent<ofxUeyeEventArgs>	bandwithChanged;
	ofEvent<ofxUeyeEventArgs>	deviceRemoved;
	ofEvent<ofxUeyeEventArgs>	deviceReconnected;
};

#endif
