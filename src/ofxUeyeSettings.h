/*
 *  ofxUeyeSettings.h
 *  ofxUeye
 *
 *  Created by Paulo Barcelos on 7/26/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#ifndef _OFX_UEYE_SETTINGS
#define _OFX_UEYE_SETTINGS

#include "ofMain.h"
#include "ofxUeye.h"
#include "ofxKeyboardSettings.h"


////////////////////////////////////////////////////////////
// CLASS DEFINITION ----------------------------------------
////////////////////////////////////////////////////////////
class ofxUeyeSettings {
	
public:
	ofxUeyeSettings();
	void		setup(ofxUeye* ueye, int accessKey = 'u', string label = "uEye");
	void		keyPressed(int key);	
	void		draw(float x, float y);
	
private:
	
	ofxUeye*			ueye;
	ofxKeyboardSettings	settings;	
};
#endif