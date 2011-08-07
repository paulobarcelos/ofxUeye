/*
 *  ofxUeyeSettings.cpp
 *  ofxUeye
 *
 *  Created by Paulo Barcelos on 7/26/11.
 *  Copyright 2011 paulobarcelos.com. All rights reserved.
 *
 */

#include "ofxUeyeSettings.h"

///////////////////////////////////////////////////////////////////////////////////
// Constructor --------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
ofxUeyeSettings::ofxUeyeSettings()
{
	ueye = NULL;
}
///////////////////////////////////////////////////////////////////////////////////
// Destructor --------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
ofxUeyeSettings::~ofxUeyeSettings()
{	
	if(ueye != NULL) delete ueye;
}
///////////////////////////////////////////////////////////////////////////////////
// setup --------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
void ofxUeyeSettings::setup(ofxUeye* ueye, int accessKey, string label)
{	
	this->ueye = ueye;
	settings.setup(accessKey, label);

	/*settings.addMonitor(ueye, &ofxUeye::getBandwidth, "Bandwidth");
	settings.addMonitor(ueye, &ofxUeye::getSensorWidth, "Sensor_Width");
	settings.addMonitor(ueye, &ofxUeye::getSensorHeight, "Sensor_Height");
	settings.addMonitor(ueye, &ofxUeye::getWidth, "AOI_Width");
	settings.addMonitor(ueye, &ofxUeye::getHeight, "AOI_Height");*/

	settings.addProperty(ueye, &ofxUeye::isLive,
						 ueye, &ofxUeye::setLive,
						 "Is_Live",
						 true);

	settings.addProperty(ueye, &ofxUeye::getPixelClock,
						 ueye, &ofxUeye::setPixelClock,
						 "Pixel_Clock",
						 ueye, &ofxUeye::getPixelClockMin,
						 ueye, &ofxUeye::getPixelClockMax,
						 ueye, &ofxUeye::getPixelClockStep,
						 ueye->getPixelClockMax());

	settings.addProperty(ueye, &ofxUeye::getFPS,
						 ueye, &ofxUeye::setFPS,
						 "FPS",
						 ueye, &ofxUeye::getFPSMin,
						 ueye, &ofxUeye::getFPSMax,
						 ueye, &ofxUeye::getFPSStep,
						 ueye->getFPSMax());

	settings.addProperty(ueye, &ofxUeye::isBadPixelsCorrection,
						 ueye, &ofxUeye::setBadPixelsCorrection,
						 "Bad_pixels_correction",
						 true);
	
	/*settings.addProperty(cm, &ColorsOfMovement::getNumStoredFrames,
						 cm, &ColorsOfMovement::setNumStoredFrames,
						 "Number_of_stored_frames",
						 cm, &ColorsOfMovement::getNumStoredFramesMin,
						 cm, &ColorsOfMovement::getNumStoredFramesMax,
						 cm, &ColorsOfMovement::getNumStoredFramesStep,
						 CM_DEFAULT_NUM_STORED_FRAMES);
	
	settings.addProperty(cm, &ColorsOfMovement::getMode,
						 cm, &ColorsOfMovement::setMode,
						 "Mode",
						 cm, &ColorsOfMovement::getModeMin,
						 cm, &ColorsOfMovement::getModeMax,
						 cm, &ColorsOfMovement::getModeStep,
						 (int)CM_DEFAULT_MODE);*/
}
///////////////////////////////////////////////////////////////////////////////////
// keyPressed ---------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
void ofxUeyeSettings::keyPressed(int key)
{
	settings.keyPressed(key);
}
///////////////////////////////////////////////////////////////////////////////////
// draw ---------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
void ofxUeyeSettings::draw(float x, float y)
{
	settings.draw(x, y);
}