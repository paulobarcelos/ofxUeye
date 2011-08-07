#ifndef _OFX_UEYE_EVENTS
#define _OFX_UEYE_EVENTS

#include "ofMain.h"

class ofxUeyeEventArgs{};

class ofxUeyeEvents{	
public:
	ofxUeyeEventArgs			voidEventArgs;

	ofEvent<ofxUeyeEventArgs>	onReady;
	ofEvent<ofxUeyeEventArgs>	onFrame;
	ofEvent<ofxUeyeEventArgs>	onDeviceRemoved;
	ofEvent<ofxUeyeEventArgs>	onDeviceReconnected;
};

#endif
