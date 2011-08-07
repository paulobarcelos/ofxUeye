#ifndef _OFX_UEYE
#define _OFX_UEYE

#include <iostream>
#include <tchar.h>
#include <conio.h>
#include <windows.h>
#include "uEye.h"
#include "ofxUeyeEvents.h"

class ofxUeye{

	public:
		ofxUeye();
		~ofxUeye();

		// actions ---------------------------------------------------
		void 			setVerbose(bool bTalkToMe);
		void 			listDevices();
		bool			init(int id = 0);	//	   0: The first available camera will be initialized.
											// 1-254: The camera with the specified camera ID will be initialized.
		void			close();
		void			update();

		// Flags ------------------------------------------------------
		bool			isReady();
		bool			isFrameNew();

		// Pixels -----------------------------------------------------
		unsigned char*	getPixels();

		// Sensor Dimensions ------------------------------------------
		int				getSensorHeight();
		int				getSensorWidth();
		int				getHeight();
		int				getWidth();
		
		// Bandwidth -------------------------------------------------
		inline int		getBandwidth(){return is_GetUsedBandwidth(m_hCam);};
		
		// Live ----------------------------------------------------
		void			setLive(bool value = true){if (value) enableLive(); else disableLive();};
		bool			isLive(){return bLive;};
		void			enableLive();
		void			disableLive();

		// Binnig, subsampling ans scaler ------------------------
		int				setBinning(int mode);
		int				setSubSampling(int mode);
		int				setScaler(double factor);

		// AOI -----------------------------------------------------
		int				setAOI(ofRectangle aoi);
		ofRectangle		getAOI();
		int				setAOINormalized(ofRectangle aoi);
		ofRectangle		getAOINormalized();
		ofRectangle		getAOIMax();

				
		// Pixel Clock -------------------------------------------
		int				setPixelClock(int clock);
		int				getPixelClock();
		int				getPixelClockMin();
		int				getPixelClockMax();
		int				getPixelClockStep();

		// FPS ---------------------------------------------------
		int				setFPS(double fps);
		double			getFPS();
		double			getFPSMin();
		double			getFPSMax();
		double			getFPSStep();
		
		// Optimal Camera timing --------------------------------
		void			setOptimalCameraTiming(bool value = true);

		// Bad Pixel Correction ---------------------------------
		void			setBadPixelsCorrection(bool value = true){if (value) enableBadPixelsCorrection(); else disableBadPixelsCorrection();};
		bool			isBadPixelsCorrection(){return _badPixelCorrection;};
		int				enableBadPixelsCorrection();
		int				disableBadPixelsCorrection();

		// Exposure -----------------------------------------------
		void			setAutoExposureTime(bool value = true){if (value) enableAutoExposureTime(); else disableAutoExposureTime();};
		inline bool		isExposureTimeAuto(){double e ; is_SetAutoParameter (m_hCam, IS_GET_ENABLE_AUTO_SHUTTER, &e, 0); return (e == 1.0)?true:false;};
		inline int		enableAutoExposureTime(){double e = 1; return is_SetAutoParameter (m_hCam, IS_SET_ENABLE_AUTO_SHUTTER, &e, 0);};
		inline int		disableAutoExposureTime(){double e = 0; return is_SetAutoParameter (m_hCam, IS_SET_ENABLE_AUTO_SHUTTER, &e, 0);};

		inline int		setExposureTime(double exposure){return is_Exposure (m_hCam, IS_EXPOSURE_CMD_SET_EXPOSURE, (void*)&exposure, sizeof(exposure));};
		inline double	getExposureTime(){double exposure; is_Exposure (m_hCam, IS_EXPOSURE_CMD_GET_EXPOSURE, (void*)&exposure, sizeof(exposure)); return exposure;};
		inline double 	getExposureTimeMin(){double min; is_Exposure (m_hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MIN, (void*)&min, sizeof(min)); return min;};
		inline double 	getExposureTimeMax(){double max; is_Exposure (m_hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MAX, (void*)&max, sizeof(max)); return max;};
		inline double 	getExposureTimeStep(){double step; is_Exposure (m_hCam, IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_INC, (void*)&step, sizeof(step)); return step;};

		// White Balance -----------------------------------------
		void			setAutoWhiteBalance(bool value = true){if (value) enableAutoWhiteBalance(); else disableAutoWhiteBalance();};
		int				enableAutoWhiteBalance(){double e = WB_MODE_AUTO; return is_SetAutoParameter (m_hCam, IS_SET_ENABLE_AUTO_SENSOR_WHITEBALANCE, &e, 0);};
		int				disableAutoWhiteBalance(){double e = WB_MODE_DISABLE; return is_SetAutoParameter (m_hCam, IS_SET_ENABLE_AUTO_SENSOR_WHITEBALANCE, &e, 0);};
	
		// Gain -------------------------------------------
		void			setAutoGain(bool value = true){if (value) enableAutoGain(); else disableAutoGain();};
		inline bool		isGainAuto(){double e ; is_SetAutoParameter (m_hCam, IS_GET_ENABLE_AUTO_GAIN, &e, 0); return (e == 1.0)?true:false;};
		inline int		enableAutoGain(){double e = 1; return is_SetAutoParameter (m_hCam, IS_SET_ENABLE_AUTO_GAIN, &e, 0);};
		inline int		disableAutoGain(){double e = 0; return is_SetAutoParameter (m_hCam, IS_SET_ENABLE_AUTO_GAIN, &e, 0);};
		
		inline int		setGainMaster(int gain){return is_SetHardwareGain(m_hCam, gain, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER);};
		inline int		getGainMaster(){return is_SetHardwareGain (m_hCam, IS_GET_MASTER_GAIN, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER);};
		inline int		getGainMasterMin(){return 0;};
		inline int		getGainMasterMax(){return 100;};
		inline int		getGainMasterStep(){return 1;};
		
		inline int		setGainRed(int gain){return is_SetHardwareGain (m_hCam, IS_IGNORE_PARAMETER, gain, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER);};
		inline int		getGainRed(){return is_SetHardwareGain (m_hCam, IS_GET_RED_GAIN, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER);};
		inline int		getGainRedMin(){return 0;};
		inline int		getGainRedMax(){return 100;};
		inline int		getGainRedStep(){return 1;};

		inline int		setGainGreen(int gain){return is_SetHardwareGain (m_hCam, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER, gain, IS_IGNORE_PARAMETER);};
		inline int		getGainGreen(){return is_SetHardwareGain (m_hCam, IS_GET_GREEN_GAIN, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER);};
		inline int		getGainGreenMin(){return 0;};
		inline int		getGainGreenMax(){return 100;};
		inline int		getGainGreenStep(){return 1;};

		inline int		setGainBlue(int gain){return is_SetHardwareGain (m_hCam, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER, gain);};
		inline int		getGainBlue(){return is_SetHardwareGain (m_hCam, IS_GET_BLUE_GAIN, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER, IS_IGNORE_PARAMETER);};
		inline int		getGainBlueMin(){return 0;};
		inline int		getGainBlueMax(){return 100;};
		inline int		getGainBlueStep(){return 1;};

		// Color Saturation ---------------------------------
		inline int		setColorSaturation(int saturation){return is_SetSaturation (m_hCam, saturation,saturation);};
		inline int		getColorSaturation(){return is_SetSaturation(m_hCam, IS_GET_SATURATION_U,IS_GET_SATURATION_V);};
		inline int		getColorSaturationMin(){return 0;};
		inline int		getColorSaturationMax(){return 200;};
		inline int		getColorSaturationStep(){return 1;};

		// Color Corection ---------------------------------
		int				setColorCorrection(double factor);
		inline double	getColorCorrection(){return _colorCorrection;};
		inline double	getColorCorrectionMin(){return 0;};
		inline double	getColorCorrectionMax(){return 1.0;};
		inline double	getColorCorrectionStep(){return 0.1;};
												
		// events
		ofxUeyeEvents	events;

	private:
		// instance reference
		static ofxUeye*	instanceRef;

		// private flags
		bool			bVerbose;
		bool			bReady;
		bool			bLive;
		bool 			bIsFrameNew;
		bool 			bIsWaitingNewFrame;

		// internal info
		int				_binning;
		int				_subSampling;
		double			_scaler;
		ofRectangle		_AOINormalized;
		ofRectangle		_AOI;
		ofRectangle		_AOIMax;
		int				_sensorWidth;
		int				_sensorHeight;
		int				_width;
		int				_height;
		unsigned char*	_pixels;
		unsigned char*	_fullPixels;
		int				_channels;
		int				_bitsPerPixel;
		int				_bytesPerPixel;
		double			_colorCorrection;
		bool			_badPixelCorrection;

		// helpers
		void			calculateMaxAOI();
		void			updateDimensions();
		void			preprocessPixels(unsigned char * rawPixels);

		// pre events handlers
		void			preOnFrame();
		void			preOnDeviceRemoved();
		void			preOnDeviceReconected();






				
		// stuff ported straight from IDS SDK examples ---------------------------------------------------
		CAMINFO         m_ci;
		SENSORINFO      m_si;
		HCAM            m_hCam;
		int             m_nSizeX, m_nSizeY;
		char*           m_pcImageMemory;
		int             m_nMemoryId;
		int             m_nColorMode;
		int             m_nBitsPerPixel;
		HWND            m_hwndDisp;
		ATOM            m_atom;
		BOOL CreateDisplayWindow();
		BOOL DeleteDisplayWindow();
		INT InitCamera (HIDS *m_hCam, HWND hWnd);
		BOOL OpenCamera(int id);
		BOOL CloseCamera();
		void GetMaxImageSize(INT *pnSizeX, INT *pnSizeY);
		int InitDisplayMode();
		static BOOL ProcessuEyeMessages(UINT msg, WPARAM wParam, LPARAM lParam);
		static LRESULT WINAPI ConsoleDispWndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);		
};

#endif
