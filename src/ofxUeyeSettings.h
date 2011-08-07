#ifndef _OFX_UEYE_SETTINGS
#define _OFX_UEYE_SETTINGS

#include "ofMain.h"
#include "ofxUeye.h"

// keyboard settings
#define EXPOSURE			'e'
#define GAIN_MASTER			'm'
#define GAIN_RED			'r'
#define GAIN_GREEN			'g'
#define GAIN_BLUE			'b'
#define SATURATION			's'
#define COLOR_CORRECTION	'c'

class ofxUeyeSettings{	
public:
	ofxUeyeSettings()	{ueye = NULL;};
	~ofxUeyeSettings()	{if(ueye != NULL) delete ueye;};

	void init(ofxUeye * ueyeRef){ueye = ueyeRef;};
	
	void processInput(int key){
		if(	key == EXPOSURE ||
			key == GAIN_MASTER ||
			key == GAIN_RED ||
			key == GAIN_GREEN ||
			key == GAIN_BLUE ||
			key == SATURATION ||
			key == COLOR_CORRECTION) curSetting = key;
	
		switch (curSetting)
		{
			case EXPOSURE:
				if(key == OF_KEY_UP)		ueye->setExposureTime(ueye->getExposureTime() + ueye->getExposureTimeStep());
				else if(key == OF_KEY_DOWN) ueye->setExposureTime(ueye->getExposureTime() - ueye->getExposureTimeStep());
				else if(key == '.')			(ueye->isExposureTimeAuto()) ? ueye->disableAutoExposureTime() :  ueye->enableAutoExposureTime();
				break;
			case GAIN_MASTER:
				if(key == OF_KEY_UP)		ueye->setGainMaster(ueye->getGainMaster() + ueye->getGainMasterStep());
				else if(key == OF_KEY_DOWN) ueye->setGainMaster(ueye->getGainMaster() - ueye->getGainMasterStep());
				else if(key == '.')			(ueye->isGainAuto()) ? ueye->disableAutoGain() :  ueye->enableAutoGain();
				break;
			case GAIN_RED:
				if(key == OF_KEY_UP)		ueye->setGainRed(ueye->getGainRed() + ueye->getGainRedStep());
				else if(key == OF_KEY_DOWN) ueye->setGainRed(ueye->getGainRed() - ueye->getGainRedStep());
				break;
			case GAIN_GREEN:
				if(key == OF_KEY_UP)		ueye->setGainGreen(ueye->getGainGreen() + ueye->getGainGreenStep());
				else if(key == OF_KEY_DOWN) ueye->setGainGreen(ueye->getGainGreen() - ueye->getGainGreenStep());
				break;
			case GAIN_BLUE:
				if(key == OF_KEY_UP)		ueye->setGainBlue(ueye->getGainBlue() + ueye->getGainBlueStep());
				else if(key == OF_KEY_DOWN) ueye->setGainBlue(ueye->getGainBlue() - ueye->getGainBlueStep());
				break;
			case SATURATION:
				if(key == OF_KEY_UP)		ueye->setColorSaturation(ueye->getColorSaturation() + ueye->getColorSaturationStep());
				else if(key == OF_KEY_DOWN) ueye->setColorSaturation(ueye->getColorSaturation() - ueye->getColorSaturationStep());
				break;
			case COLOR_CORRECTION:
				if(key == OF_KEY_UP)		ueye->setColorCorrection(ueye->getColorCorrection() + ueye->getColorCorrectionStep());
				else if(key == OF_KEY_DOWN) ueye->setColorCorrection(ueye->getColorCorrection() - ueye->getColorCorrectionStep());
				break;
		}
	};

	void draw(int x, int y){
		stringstream reportStream;
		reportStream	<<	"APP FPS: " << ofGetFrameRate() << endl;
		reportStream	<<	"Used Bandwidth: " << ueye->getBandwidth() << endl;
		reportStream	<<	"AOI: " << "(" << ueye->getAOI().x << ", " << ueye->getAOI().y << ", " << ueye->getAOI().width << ", " << ueye->getAOI().height << ")" << endl;
		reportStream	<<	"FPS: " << ueye->getFPS() << " (min: " << ueye->getFPSMin() << " | max: " << ueye->getFPSMax() << " | step: " << ueye->getFPSStep() << ")" << endl;
		reportStream	<<	"Pixel Clock: " << ueye->getPixelClock() << " (min: " << ueye->getPixelClockMin() << " | max: " << ueye->getPixelClockMax() << " | step: " << ueye->getPixelClockStep() << ")" << endl;
		reportStream	<<	((curSetting == EXPOSURE)?"*": "")		<< "(e) Exposure Time: " <<	((ueye->isExposureTimeAuto()) ?"(auto) ": "") << ueye->getExposureTime() << " (min: " << ueye->getExposureTimeMin() << " | max: " << ueye->getExposureTimeMax() << " | step: " << ueye->getExposureTimeStep() << ")" << endl;
		reportStream	<<	((curSetting == GAIN_MASTER)?"*": "")	<<	"(m) Gain Master: " <<	((ueye->isGainAuto()) ?"(auto) ": "") << ueye->getGainMaster() << " (min: " << ueye->getGainMasterMin() << " | max: " << ueye->getGainMasterMax() << " | step: " << ueye->getGainMasterStep() << ")" << endl;
		reportStream	<<	((curSetting == GAIN_RED)?"*": "")		<<	"(r) Gain Red: " << ueye->getGainRed() << " (min: " << ueye->getGainRedMin() << " | max: " << ueye->getGainRedMax() << " | step: " << ueye->getGainRedStep() << ")" << endl;
		reportStream	<<	((curSetting == GAIN_GREEN)?"*": "")	<<	"(g) Gain Green: " << ueye->getGainGreen() << " (min: " << ueye->getGainGreenMin() << " | max: " << ueye->getGainGreenMax() << " | step: " << ueye->getGainGreenStep() << ")" << endl;
		reportStream	<<	((curSetting == GAIN_BLUE)?"*": "")		<<	"(b) Gain Blue: " << ueye->getGainBlue() << " (min: " << ueye->getGainBlueMin() << " | max: " << ueye->getGainBlueMax() << " | step: " << ueye->getGainBlueStep() << ")" << endl;
		reportStream	<<	((curSetting == SATURATION)?"*": "")	<<	"(s) Color Saturation: " << ueye->getColorSaturation() << " (min: " << ueye->getColorSaturationMin() << " | max: " << ueye->getColorSaturationMax() << " | step: " << ueye->getColorSaturationStep() << ")" << endl;
		reportStream	<<	((curSetting == COLOR_CORRECTION)?"*": "")<<"(c) Color Correction: " << ueye->getColorCorrection() << " (min: " << ueye->getColorCorrectionMin() << " | max: " << ueye->getColorCorrectionMax() << " | step: " << ueye->getColorCorrectionStep() << ")" << endl;

		ofSetColor(0);
		ofDrawBitmapString(reportStream.str(), x+1, y+1);
		ofSetColor(255);
		ofDrawBitmapString(reportStream.str(), x, y);
	};
private:
	ofxUeye *	ueye;
	int			curSetting;
};

#endif
