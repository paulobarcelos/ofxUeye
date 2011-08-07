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
// setup --------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
void ofxUeyeSettings::setup(ofxUeye* ueye, int accessKey, string label)
{	
	this->ueye = ueye;
	settings.setup(accessKey, label);

	settings.addMonitor(ueye, &ofxUeye::getBandwidth, "Bandwidth");
	settings.addMonitor(ueye, &ofxUeye::getSensorWidth, "Sensor_Width");
	settings.addMonitor(ueye, &ofxUeye::getSensorHeight, "Sensor_Height");
	settings.addMonitor(ueye, &ofxUeye::getWidth, "AOI_Width");
	settings.addMonitor(ueye, &ofxUeye::getHeight, "AOI_Height");

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

	settings.addProperty(ueye, &ofxUeye::isExposureTimeAuto,
						 ueye, &ofxUeye::setAutoExposureTime,
						 "Auto_Exposure",
						 false);

	settings.addProperty(ueye, &ofxUeye::getExposureTime,
						 ueye, &ofxUeye::setExposureTime,
						 "Exposure",
						 ueye, &ofxUeye::getExposureTimeMin,
						 ueye, &ofxUeye::getExposureTimeMax,
						 ueye, &ofxUeye::getExposureTimeStep,
						 ueye->getFPSMax());

	/*settings.addProperty(ueye, &ofxUeye::isWhiteBalanceAuto,
						 ueye, &ofxUeye::setAutoWhiteBalance,
						 "Auto_WB",
						 false);*/

	settings.addProperty(ueye, &ofxUeye::isGainAuto,
						 ueye, &ofxUeye::setAutoGain,
						 "Auto_Gain",
						 false);

	settings.addProperty(ueye, &ofxUeye::getGainMaster,
						 ueye, &ofxUeye::setGainMaster,
						 "Master_Gain",
						 ueye, &ofxUeye::getGainMasterMin,
						 ueye, &ofxUeye::getGainMasterMax,
						 ueye, &ofxUeye::getGainMasterStep,
						 ueye->getGainMasterMax());

	settings.addProperty(ueye, &ofxUeye::getGainRed,
						 ueye, &ofxUeye::setGainRed,
						 "Red_Gain",
						 ueye, &ofxUeye::getGainRedMin,
						 ueye, &ofxUeye::getGainRedMax,
						 ueye, &ofxUeye::getGainRedStep,
						 ueye->getGainRedMax());

	settings.addProperty(ueye, &ofxUeye::getGainGreen,
						 ueye, &ofxUeye::setGainGreen,
						 "Green_Gain",
						 ueye, &ofxUeye::getGainGreenMin,
						 ueye, &ofxUeye::getGainGreenMax,
						 ueye, &ofxUeye::getGainGreenStep,
						 ueye->getGainGreenMax());

	settings.addProperty(ueye, &ofxUeye::getGainBlue,
						 ueye, &ofxUeye::setGainBlue,
						 "Blue_Gain",
						 ueye, &ofxUeye::getGainBlueMin,
						 ueye, &ofxUeye::getGainBlueMax,
						 ueye, &ofxUeye::getGainBlueStep,
						 ueye->getGainBlueMax());

	settings.addProperty(ueye, &ofxUeye::getColorSaturation,
						 ueye, &ofxUeye::setColorSaturation,
						 "Color_Saturation",
						 ueye, &ofxUeye::getColorSaturationMin,
						 ueye, &ofxUeye::getColorSaturationMax,
						 ueye, &ofxUeye::getColorSaturationStep,
						 ueye->getColorSaturationMax());

	settings.addProperty(ueye, &ofxUeye::getColorCorrection,
						 ueye, &ofxUeye::setColorCorrection,
						 "Color_Correction",
						 ueye, &ofxUeye::getColorCorrectionMin,
						 ueye, &ofxUeye::getColorCorrectionMax,
						 ueye, &ofxUeye::getColorCorrectionStep,
						 ueye->getColorCorrectionMax());

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