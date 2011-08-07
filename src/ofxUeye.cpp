#include "ofxUeye.h"

ofxUeye* ofxUeye::instanceRef = {NULL};
//////////////////////////////////////////////////////////////////////////////////
// constructor -------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
ofxUeye::ofxUeye(){
	// Display an error if more than one instance is created.
	if(!instanceRef)
	{
		// store the pointer to this instance (used by windows static event system)
		instanceRef = this;

		// set common flags
		bVerbose = false;
		
		// null pointers for safety
		_pixels = NULL;
		_fullPixels = NULL;
		m_pcImageMemory = NULL;

		// close (to set all flags to the default values)
		close();
	}
	else
	{
		ofLog(OF_LOG_ERROR, "ofxUeye - Only one instance ofxUeye is allowed, please delete this object.");
	}
}
//////////////////////////////////////////////////////////////////////////////////
// destructor --------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
ofxUeye::~ofxUeye(){
	if(instanceRef){
		instanceRef = NULL;
		close();
	}
}
//////////////////////////////////////////////////////////////////////////////////
// setVerbose --------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::setVerbose(bool bTalkToMe){
	bVerbose = bTalkToMe;
}
//////////////////////////////////////////////////////////////////////////////////
// listDevices -------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::listDevices(){
	// At least one camera must be available
	INT nNumCam;
	if( is_GetNumberOfCameras( &nNumCam ) == IS_SUCCESS)
	{
		if( nNumCam >= 1 )
		{
			// Create new list with suitable size
			UEYE_CAMERA_LIST* pucl;
			pucl = (UEYE_CAMERA_LIST*) new char [sizeof (DWORD)
			+ nNumCam
			* sizeof (UEYE_CAMERA_INFO)];
			pucl->dwCount = nNumCam;
 
			//Retrieve camera info
			if (is_GetCameraList(pucl) == IS_SUCCESS)
			{
				int iCamera;
				printf("---------------------------------\n");
				printf("ofxUeye - listDevices:\n");
				for (iCamera = 0; iCamera < (int)pucl->dwCount; iCamera++)
				{
					printf("    Camera %i Id: %d\n", iCamera, pucl->uci[iCamera].dwCameraID);
				}
				printf("---------------------------------\n");
			}
			delete [] pucl;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////
// init --------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
bool ofxUeye::init(int id){
	bool success = false;

	// close any open camera
	close();
	
	// try to create windows bullshit
	if(CreateDisplayWindow())
	{
		// try to open the camera
		if(OpenCamera(id))
		{
			// store sensor size
			_sensorWidth = m_nSizeX;
			_sensorHeight = m_nSizeY;

			success = true;
		} 
		else ofLog(OF_LOG_WARNING, "ofxUeye - init - Couldn't open camera.");
	}
	else ofLog(OF_LOG_WARNING, "ofxUeye - init - Couldn't create Windows handlers.");
	
	return success;
}

//////////////////////////////////////////////////////////////////////////////////
// close -------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::close()
{
	bReady = false;
	bLive = false;
	bIsFrameNew = false;
	bIsWaitingNewFrame = true;
	_binning = IS_BINNING_DISABLE;
	_subSampling = IS_BINNING_DISABLE;
	_scaler = 1.0;
	_AOI = ofRectangle(0,0,0,0);
	_AOINormalized = ofRectangle(0,0,0,0);
	_AOIMax = ofRectangle(0,0,0,0);
	_sensorWidth = 0;
	_sensorHeight = 0;
	_width = 0;
	_height = 0;
	if(_pixels != NULL) delete _pixels;
	_pixels = NULL;
	_channels = 0;
	_bitsPerPixel = 0;
	_bytesPerPixel = 0;
	_colorCorrection = 0;

	CloseCamera();
}
//////////////////////////////////////////////////////////////////////////////////
// update ------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::update()
{
	if(!bIsWaitingNewFrame && bIsFrameNew)
		bIsWaitingNewFrame = true;
	else
		bIsFrameNew = false;
}

//*************************************************************************************************************************
//*************************************************************************************************************************
// GETTERS ****************************************************************************************************************
//*************************************************************************************************************************
//*************************************************************************************************************************


//////////////////////////////////////////////////////////////////////////////////
// isReady -----------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
bool ofxUeye::isReady()
{
	return bReady;
}
//////////////////////////////////////////////////////////////////////////////////
// isFrameNew --------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
bool ofxUeye::isFrameNew()
{
	return bIsFrameNew;	
}
//////////////////////////////////////////////////////////////////////////////////
// getSensorWidth ----------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::getSensorWidth()
{
	return _sensorWidth;
}
//////////////////////////////////////////////////////////////////////////////////
// getSensorHeight --------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::getSensorHeight()
{
	return _sensorHeight;
}
//////////////////////////////////////////////////////////////////////////////////
// getWidth ----------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::getWidth()
{
	return _width;
}
//////////////////////////////////////////////////////////////////////////////////
// getHeight ---------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::getHeight()
{
	return _height;
}
//////////////////////////////////////////////////////////////////////////////////
// getAOINormalized --------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
ofRectangle ofxUeye::getAOINormalized()
{
	return _AOINormalized;
}
//////////////////////////////////////////////////////////////////////////////////
// getAOI ------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
ofRectangle ofxUeye::getAOI()
{
	return _AOI;
}
//////////////////////////////////////////////////////////////////////////////////
// getAOIMax ---------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
ofRectangle ofxUeye::getAOIMax()
{
	return _AOIMax;
}
//////////////////////////////////////////////////////////////////////////////////
// getPixels ---------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
unsigned char* ofxUeye::getPixels()
{
	return _pixels;
}
//////////////////////////////////////////////////////////////////////////////////
// getPixelClock -----------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::getPixelClock()
{
	return is_SetPixelClock (m_hCam, IS_GET_PIXEL_CLOCK);
}
//////////////////////////////////////////////////////////////////////////////////
// getPixelClockMin --------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::getPixelClockMin()
{
	int min, max;
	is_GetPixelClockRange  (m_hCam, &min, &max);
	return min;
}
//////////////////////////////////////////////////////////////////////////////////
// getPixelClockMax --------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::getPixelClockMax()
{
	int min, max;
	is_GetPixelClockRange  (m_hCam, &min, &max);
	return max;
}
//////////////////////////////////////////////////////////////////////////////////
// getPixelClockStep -------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::getPixelClockStep()
{
	return is_SetPixelClock (m_hCam, IS_GET_PIXEL_CLOCK_INC);
}
//////////////////////////////////////////////////////////////////////////////////
// getFPS ------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
double ofxUeye::getFPS()
{
	double fps;
	is_GetFramesPerSecond (m_hCam, &fps);
	return fps;
}
//////////////////////////////////////////////////////////////////////////////////
// getFPSMin ---------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
double ofxUeye::getFPSMin()
{
	double min, max, step;
	is_GetFrameTimeRange  (m_hCam, &min, &max, &step);
	return (1.0 / max);
}
//////////////////////////////////////////////////////////////////////////////////
// getFPSMax ---------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
double ofxUeye::getFPSMax()
{
	double min, max, step;
	is_GetFrameTimeRange  (m_hCam, &min, &max, &step);
	return (1.0 / min);
}
//////////////////////////////////////////////////////////////////////////////////
// getFPSStep --------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
double ofxUeye::getFPSStep()
{
	double min, max, step;
	is_GetFrameTimeRange  (m_hCam, &min, &max, &step);
	return step;
}


//*************************************************************************************************************************
//*************************************************************************************************************************
// SETTERS ****************************************************************************************************************
//*************************************************************************************************************************
//*************************************************************************************************************************


//////////////////////////////////////////////////////////////////////////////////
// enableLive --------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::enableLive()
{
    if(m_hCam != NULL)
    {
		bLive = true;
		is_CaptureVideo(m_hCam, IS_DONT_WAIT);
    }
}
//////////////////////////////////////////////////////////////////////////////////
// disableLive -------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::disableLive()
{
    if(m_hCam != NULL)
    {
		bLive = false;
		is_StopLiveVideo(m_hCam, IS_WAIT);
    }
}
//////////////////////////////////////////////////////////////////////////////////
// setBinning --------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::setBinning(INT mode)
{
	bool wasLive = bLive;
	if (wasLive) disableLive();

	// As the binning change will make the camera irresponsive for a while, we need to flag as NOT ready for thread safety
	bReady = false;

	int result;
	result = is_SetBinning (m_hCam, mode);
	if(result == IS_SUCCESS){
		_binning = mode;
		updateDimensions();
		ofLog(OF_LOG_WARNING, "ofxUeye - setBinning - (%i) Success.", mode);
	}
	else {
		if(bVerbose)
			ofLog(OF_LOG_WARNING, "ofxUeye - setBinning - Couldn't apply %i value.", mode);
	}
	if (wasLive) enableLive();
	return result;
}
//////////////////////////////////////////////////////////////////////////////////
// setSubSampling ----------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::setSubSampling(INT mode)
{
	bool wasLive = bLive;
	if (wasLive) disableLive();

	// As the subsampling change will make the camera irresponsive for a while, we need to flag as NOT ready for thread safety
	bReady = false;

	int result;
	result = is_SetSubSampling (m_hCam, mode);
	if(result == IS_SUCCESS){
		_subSampling = mode;
		updateDimensions();
		ofLog(OF_LOG_WARNING, "ofxUeye - setSubSampling - (%i) Success.", mode);
	}
	else {
		if(bVerbose)
			ofLog(OF_LOG_WARNING, "ofxUeye - setSubSampling - Couldn't apply %i value.", mode);
	}
	if (wasLive) enableLive();
	return result;
}
//////////////////////////////////////////////////////////////////////////////////
// setScaler ---------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::setScaler(double factor)
{
	bool wasLive = bLive;
	if (wasLive) disableLive();

	// As the scaler change will make the camera irresponsive for a while, we need to flag as NOT ready for thread safety
	bReady = false;

	int result;
	result = is_SetSensorScaler  (m_hCam, IS_ENABLE_SENSOR_SCALER | IS_ENABLE_ANTI_ALIASING, factor);
	if(result == IS_SUCCESS){
		_scaler = factor;
		updateDimensions();
		ofLog(OF_LOG_WARNING, "ofxUeye - setScaler - (%f) Success.", (float)factor);
	}
	else {
		if(bVerbose)
			ofLog(OF_LOG_WARNING, "ofxUeye - setScaler - Couldn't apply %f value.", (float)factor);
	}
	return result;
}
//////////////////////////////////////////////////////////////////////////////////
// setAOINormalized --------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::setAOINormalized(ofRectangle aoi)
{
	bool wasLive = bLive;
	if (wasLive) disableLive();
	// Update the curent max AOI
	calculateMaxAOI();

	// Convert normalized values
	IS_RECT newAOI;
	newAOI.s32X = aoi.x * _AOIMax.width;
	newAOI.s32Y = aoi.y * _AOIMax.height;
	newAOI.s32Width = aoi.width * _AOIMax.width;
	newAOI.s32Height = aoi.height * _AOIMax.height;

	return setAOI(ofRectangle(newAOI.s32X, newAOI.s32Y, newAOI.s32Width, newAOI.s32Height));
}
//////////////////////////////////////////////////////////////////////////////////
// setAOI ------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::setAOI(ofRectangle aoi)
{
	bool wasLive = bLive;
	if (wasLive) disableLive();
	// We need to request a native aoi, otherwise it will fail, it requeire a couple of steps to get it right...

	// Update the curent max AOI
	calculateMaxAOI();
	
	// Clamp the desired AOI to safe values;
	ofClamp(aoi.width, 0, _AOIMax.width);
	ofClamp(aoi.height, 0, _AOIMax.height);
	ofClamp(aoi.x,	0, (_AOIMax.width - aoi.width));
	ofClamp(aoi.y, 0, (_AOIMax.height - aoi.height));

	IS_RECT newAOI;
	newAOI.s32X = aoi.x;
	newAOI.s32Y = aoi.y;
	newAOI.s32Width = aoi.width;
	newAOI.s32Height = aoi.height;

	// Round the size value to a valid increment
	IS_SIZE_2D sizeInc; 
	is_AOI(m_hCam, IS_AOI_IMAGE_GET_SIZE_INC, (void*)&sizeInc, sizeof(sizeInc));

	newAOI.s32Width = (newAOI.s32Width / sizeInc.s32Width) * sizeInc.s32Width;
	newAOI.s32Height = (newAOI.s32Height / sizeInc.s32Height) * sizeInc.s32Height;

	// Clamp size to min and max accepted by the sensor
	IS_SIZE_2D minSize; 
	is_AOI(m_hCam, IS_AOI_IMAGE_GET_SIZE_MIN, (void*)&minSize, sizeof(minSize));
	IS_SIZE_2D maxSize; 
	is_AOI(m_hCam, IS_AOI_IMAGE_GET_SIZE_MAX, (void*)&maxSize, sizeof(maxSize));

	ofClamp(newAOI.s32Width, minSize.s32Width, maxSize.s32Height);
	ofClamp(newAOI.s32Height, minSize.s32Height, maxSize.s32Height);

	// Now we are sure the size is valid, so we apply it in order to be abble get the max and min values for the position
	IS_RECT newAOISize;
	newAOISize.s32X = 0;
	newAOISize.s32Y = 0;
	newAOISize.s32Width = newAOI.s32Width;
	newAOISize.s32Height = newAOI.s32Height;
	is_AOI( m_hCam, IS_AOI_IMAGE_SET_AOI, (void*)&newAOISize, sizeof(newAOISize));

	// Round the position value to a valid increment
	IS_SIZE_2D posInc; 
	is_AOI(m_hCam, IS_AOI_IMAGE_GET_POS_INC, (void*)&posInc, sizeof(posInc));

	newAOI.s32X = (newAOI.s32X / posInc.s32Width) * posInc.s32Width;
	newAOI.s32Y = (newAOI.s32Y / posInc.s32Height) * posInc.s32Height;

	// Clamp position to min and max accepted by the sensor
	IS_POINT_2D minPos; 
	is_AOI(m_hCam, IS_AOI_IMAGE_GET_POS_MIN, (void*)&minPos, sizeof(minPos));
	IS_POINT_2D maxPos; 
	is_AOI(m_hCam, IS_AOI_IMAGE_GET_POS_MAX, (void*)&maxPos, sizeof(maxPos));
	ofClamp(newAOI.s32X, minPos.s32X, maxPos.s32X);
	ofClamp(newAOI.s32Y, minPos.s32Y, maxPos.s32Y);

	// As the AOI change will make the camera irresponsive for a while, we need to flag as NOT ready for thread safety
	bReady = false;

	// Apply the AOI
	int result;
	result = is_AOI( m_hCam, IS_AOI_IMAGE_SET_AOI, (void*)&newAOI, sizeof(newAOI));
	if(result == IS_SUCCESS) {
		updateDimensions();
		ofLog(OF_LOG_WARNING, "ofxUeye - setAOI - (%f, %f, %f, %f) Success.", _AOI.x, _AOI.y, _AOI.width, _AOI.height);
	}
	else {
		if(bVerbose)
			ofLog(OF_LOG_WARNING, "ofxUeye - setAOI - Couldn't apply (%i, %i, %i, %i) value.", newAOI.s32X, newAOI.s32Y, newAOI.s32Width, newAOI.s32Height);
	}
	if (wasLive) enableLive();

	return result;
}
//////////////////////////////////////////////////////////////////////////////////
// setPixelClock -----------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::setPixelClock(int clock)
{
	int result;
	result = is_SetPixelClock (m_hCam, clock);
	if(result == IS_SUCCESS)
		ofLog(OF_LOG_WARNING, "ofxUeye - setPixelClock - (%i) Success.", clock);
	else
		ofLog(OF_LOG_WARNING, "ofxUeye - setPixelClock - Couldn't apply (%i).", clock);
	return result;
}
//////////////////////////////////////////////////////////////////////////////////
// setFPS ------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::setFPS(double fps)
{
	double newFPS;
	int result;
	result = is_SetFrameRate (m_hCam, fps, &newFPS);
	if(result == IS_SUCCESS)
		ofLog(OF_LOG_WARNING, "ofxUeye - setFPS - (%f) Success.", (float)newFPS);
	else
		ofLog(OF_LOG_WARNING, "ofxUeye - setFPS - Couldn't apply (%f).", (float)fps);
	return result;
}
//////////////////////////////////////////////////////////////////////////////////
// setOptimalCameraTiming --------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::setOptimalCameraTiming()
{
	int pixelClock;
	double fps;
	int result = is_SetOptimalCameraTiming (m_hCam, IS_BEST_PCLK_RUN_ONCE, 10000, &pixelClock, &fps);
	is_SetPixelClock (m_hCam, pixelClock);
	is_SetFrameRate (m_hCam, fps, &fps);
}
//////////////////////////////////////////////////////////////////////////////////
// setOptimalCameraTiming --------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::setColorCorrection(double factor){
	_colorCorrection = factor; 
	if(_colorCorrection < getColorCorrectionMin()) _colorCorrection = getColorCorrectionMin();
	else if(_colorCorrection > getColorCorrectionMax()) _colorCorrection = getColorCorrectionMax();
	if(_colorCorrection==0)
		return is_SetColorCorrection(m_hCam, IS_CCOR_DISABLE, &_colorCorrection);
	else
		return is_SetColorCorrection(m_hCam, IS_CCOR_ENABLE_NORMAL, &_colorCorrection);
}
//////////////////////////////////////////////////////////////////////////////////
// enableBadPixelsCorrection -----------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::enableBadPixelsCorrection()
{
    INT nRet;
	nRet = is_HotPixel(m_hCam, IS_HOTPIXEL_ENABLE_SENSOR_CORRECTION, NULL, NULL);
	if (nRet == IS_SUCCESS) return nRet;
	else nRet = is_HotPixel(m_hCam, IS_HOTPIXEL_ENABLE_CAMERA_CORRECTION, NULL, NULL);
	if (nRet == IS_SUCCESS) return nRet;
	else nRet = is_HotPixel(m_hCam, IS_HOTPIXEL_ENABLE_SOFTWARE_USER_CORRECTION, NULL, NULL);
	return nRet;
}
//////////////////////////////////////////////////////////////////////////////////
// disableBadPixelsCorrection ----------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::disableBadPixelsCorrection()
{
    INT nRet = is_HotPixel(m_hCam, IS_HOTPIXEL_DISABLE_CORRECTION, NULL, NULL);
	return nRet;
}




//*************************************************************************************************************************
//*************************************************************************************************************************
// HELPERS ****************************************************************************************************************
//*************************************************************************************************************************
//*************************************************************************************************************************


//////////////////////////////////////////////////////////////////////////////////
// calculateMaxAOI ---------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::calculateMaxAOI()
{
	bool wasLive = bLive;
	if (wasLive) disableLive();
	// Maximize AOI
	int curBinning = _binning;
	int curSubSampling = _subSampling;
	double curScaler = _scaler;
	is_SetBinning (m_hCam, IS_BINNING_DISABLE);
	is_SetSubSampling (m_hCam, IS_SUBSAMPLING_DISABLE);
	is_SetSensorScaler (m_hCam, IS_ENABLE_SENSOR_SCALER | IS_ENABLE_ANTI_ALIASING, 1.0);
	IS_RECT fullAOI;
	fullAOI.s32X = 0;
	fullAOI.s32Y = 0;
	fullAOI.s32Width = _sensorWidth;
	fullAOI.s32Height = _sensorHeight;
	is_AOI(m_hCam, IS_AOI_IMAGE_SET_AOI, (void*)&fullAOI, sizeof(fullAOI));
	is_SetBinning (m_hCam, curBinning);
	is_SetSubSampling (m_hCam, curSubSampling);
	is_SetSensorScaler (m_hCam, IS_ENABLE_SENSOR_SCALER | IS_ENABLE_ANTI_ALIASING, curScaler);

	// Get the maximum AOI in the current binning, sub sampling and scaler
	IS_SIZE_2D maxAOI;
	is_AOI(m_hCam, IS_AOI_IMAGE_GET_SIZE_MAX, (void*)&maxAOI, sizeof(maxAOI));
	_AOIMax.x = 0;
	_AOIMax.y = 0;
	_AOIMax.width = (float)maxAOI.s32Width;
	_AOIMax.height = (float)maxAOI.s32Height;
	if (wasLive) enableLive();
}
//////////////////////////////////////////////////////////////////////////////////
// updateDimensions --------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::updateDimensions()
{
	bool wasLive = bLive;
	if (wasLive) disableLive();
	
	// Get current and maximum AOI
	IS_RECT  curAOI; 
	is_AOI(m_hCam, IS_AOI_IMAGE_GET_AOI, (void*)&curAOI, sizeof(curAOI));
	calculateMaxAOI();

	// Update dimensions that might have changed
	_AOI.x = curAOI.s32X;
	_AOI.y = curAOI.s32Y;
	_AOI.height = curAOI.s32Height;
	_AOI.width = curAOI.s32Width;

	_AOINormalized.x = _AOI.x / _AOIMax.width;
	_AOINormalized.y = _AOI.y / _AOIMax.height;
	_AOINormalized.width = _AOI.width / _AOIMax.width;
	_AOINormalized.height = _AOI.height / _AOIMax.height;

	_width = curAOI.s32Width;
	_height = curAOI.s32Height;

	// reallocate our pixels for the new size
	if(_pixels != NULL) delete _pixels;
	_pixels = new unsigned char [_width*_height*_channels];
	if (wasLive) enableLive();
		
	// Notify that the dimensions has changed
	ofNotifyEvent(events.dimensionChanged, events.voidEventArgs);
}
//////////////////////////////////////////////////////////////////////////////////
// preprocessPixels --------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::preprocessPixels(unsigned char * rawPixels)
{
	// Crop (logic copied from openCV's crop)
	for(int i = 0; i < _height; i++ ) {
		memcpy(	_pixels		+ (i*_width*_channels),
                rawPixels	+ (i*_sensorWidth*_channels),
                (_width*_channels));
	}

	// Swap RGB (logic copied from ofImage's swapRGB())
	if (_channels == 3){
		int totalPixels		= _width * _height;
		int cnt				= 0;
		unsigned char temp;

		while (cnt < totalPixels){
			temp							= _pixels[cnt*_bytesPerPixel];
			_pixels[cnt*_bytesPerPixel]		= _pixels[cnt*_bytesPerPixel+2];
			_pixels[cnt*_bytesPerPixel+2]	= temp;
			cnt++;
		}
	}
}


//*************************************************************************************************************************
//*************************************************************************************************************************
// PRE EVENT HANDLERS *****************************************************************************************************
//*************************************************************************************************************************
//*************************************************************************************************************************


//////////////////////////////////////////////////////////////////////////////////
// preOnFrame --------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::preOnFrame(){
	memcpy(_fullPixels,(unsigned char *)m_pcImageMemory, _sensorWidth*_sensorHeight*_channels);
	if(bIsWaitingNewFrame){
		bIsFrameNew = true;
		bIsWaitingNewFrame = false;
		preprocessPixels(_fullPixels);

		if(!bReady){
			bReady = true;
			//ofNotifyEvent(events.ready, events.voidEventArgs);
		}
	}
	ofNotifyEvent(events.newFrame, events.voidEventArgs);
}
//////////////////////////////////////////////////////////////////////////////////
// preOnDeviceRemoved ------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::preOnDeviceRemoved(){
	bReady = false;
	ofNotifyEvent(events.deviceRemoved, events.voidEventArgs);
}
//////////////////////////////////////////////////////////////////////////////////
// preOnDeviceReconected ---------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::preOnDeviceReconected(){
	ofNotifyEvent(events.deviceReconnected, events.voidEventArgs);
}









//*************************************************************************************************************************
//*************************************************************************************************************************
// IDS SAMPLE CODE ********************************************************************************************************
//*************************************************************************************************************************
//*************************************************************************************************************************



/*________________________________________________________________________________

	The following methods were almost just directly copied from the ugly sample
	source provided by IDS as an example. TODO: Optimize an clean up.
________________________________________________________________________________*/



//////////////////////////////////////////////////////////////////////////////////
// CreateDisplayWindow -----------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
BOOL ofxUeye::CreateDisplayWindow()
{
    WNDCLASSEX wcx; 
    HMODULE hInstance = GetModuleHandle(NULL);
    if (GetClassInfoEx (hInstance, (LPCWSTR)"ConsoleDispClass", &wcx) == 0)    {
        // Fill in the window class structure with parameters that describe the main window. 
        wcx.cbSize        = sizeof(wcx);				// size of structure 
        wcx.style         = NULL;
        wcx.lpfnWndProc   = &ofxUeye::ConsoleDispWndProc;   // points to window procedure 
        wcx.cbClsExtra    = 0;							// no extra class memory 
        wcx.cbWndExtra    = 0;							// no extra window memory 
        wcx.hInstance     = hInstance;					// handle to instance 
        wcx.hIcon         = NULL;						// no icon
        wcx.hCursor       = NULL;						// no cursor
        wcx.lpszMenuName  = NULL;						// name of menu resource 
        wcx.lpszClassName = (LPCWSTR)"ConsoleDispClass";  // name of window class 
        wcx.hIconSm       = NULL;						// small class icon 
        wcx.hbrBackground = NULL;

        // Register the window class. 
        m_atom = RegisterClassEx(&wcx);

        if(m_atom != NULL)
        {
            // create our display window
            m_hwndDisp = CreateWindow((LPCWSTR)"ConsoleDispClass",NULL,NULL,NULL,NULL,NULL,NULL,(HWND) NULL,(HMENU) NULL,hInstance,(LPVOID) NULL);
            if (!m_hwndDisp)
            {
                ::UnregisterClass ((LPCWSTR)"ConsoleDispClass", hInstance);
                m_atom = NULL;
            }   // end if (!m_hwndDisp)
        }   // end if(m_atom != NULL)
    }   // end if (GetClassInfoEx (hinstance, 

    return (m_atom != NULL);
}
//////////////////////////////////////////////////////////////////////////////////
// DeleteDisplayWindow -----------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
BOOL ofxUeye::DeleteDisplayWindow()
{
    BOOL boRet = FALSE;

    if(m_atom != NULL)
    {
        HMODULE hInstance = GetModuleHandle(NULL);

        SendMessage(m_hwndDisp, WM_CLOSE, 0, 0);
        SendMessage(m_hwndDisp, WM_DESTROY, 0, 0);

        UnregisterClass ((LPCWSTR)"ConsoleDispClass", hInstance);

        m_atom = NULL;
        m_hwndDisp = NULL;
    }

    return boRet;
}
//////////////////////////////////////////////////////////////////////////////////
// InitCamera --------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
INT ofxUeye::InitCamera (HIDS *m_hCam, HWND hWnd)
{
    INT nRet = is_InitCamera (m_hCam, hWnd);	
    /************************************************************************************************/
    /*                                                                                              */
    /*  If the camera returns with "IS_STARTER_FW_UPLOAD_NEEDED", an upload of a new firmware       */
    /*  is necessary. This upload can take several seconds. We recommend to check the required      */
    /*  time with the function is_GetDuration().                                                    */
    /*                                                                                              */
    /*  In this case, the camera can only be opened if the flag "IS_ALLOW_STARTER_FW_UPLOAD"        */ 
    /*  is "OR"-ed to m_hCam. This flag allows an automatic upload of the firmware.                 */
    /*                                                                                              */                        
    /************************************************************************************************/
    if (nRet == IS_STARTER_FW_UPLOAD_NEEDED)
    {
        // Time for the firmware upload = 25 seconds by default
        INT nUploadTime = 25000;
        is_GetDuration (*m_hCam, IS_STARTER_FW_UPLOAD, &nUploadTime);

        // Try again to open the camera. This time we allow the automatic upload of the firmware by
        // specifying "IS_ALLOW_STARTER_FIRMWARE_UPLOAD"
        *m_hCam = (HIDS) (((INT)*m_hCam) | IS_ALLOW_STARTER_FW_UPLOAD); 
        nRet = is_InitCamera (m_hCam, hWnd);   
    }

    return nRet;
}
//////////////////////////////////////////////////////////////////////////////////
// OpenCamera --------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
BOOL ofxUeye::OpenCamera(int id){
	int nRet;

    m_hCam = (HCAM)id; 
    nRet = InitCamera (&m_hCam, m_hwndDisp);    // init camera
    if( nRet == IS_SUCCESS )
    {
        is_GetCameraInfo( m_hCam, &m_ci);

        // retrieve original image size
        is_GetSensorInfo( m_hCam, &m_si);

        GetMaxImageSize(&m_nSizeX, &m_nSizeY);

        // setup the bitmap or directdraw display mode
        nRet = InitDisplayMode();

        if(nRet == IS_SUCCESS)
        {
            // Enable Messages
            nRet = is_EnableMessage( m_hCam, IS_DEVICE_REMOVED, m_hwndDisp );
            nRet = is_EnableMessage( m_hCam, IS_DEVICE_RECONNECTED, m_hwndDisp );
            nRet = is_EnableMessage( m_hCam, IS_FRAME, m_hwndDisp );
        }   // end if( nRet == IS_SUCCESS )
    }   // end if( nRet == IS_SUCCESS )

    return (nRet == IS_SUCCESS);
}
//////////////////////////////////////////////////////////////////////////////////
// CloseCamera -------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
BOOL ofxUeye::CloseCamera(){
	BOOL boRet = FALSE;

    if( m_hCam != 0 )
    {
        is_EnableMessage( m_hCam, IS_FRAME, NULL );
        is_StopLiveVideo( m_hCam, IS_WAIT );
        if( m_pcImageMemory != NULL )
            is_FreeImageMem( m_hCam, m_pcImageMemory, m_nMemoryId );
        m_pcImageMemory = NULL;
        is_ExitCamera( m_hCam );
        m_hCam = NULL;
        boRet = TRUE;
    }

    return boRet;
}
//////////////////////////////////////////////////////////////////////////////////
// GetMaxImageSize ---------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
void ofxUeye::GetMaxImageSize(INT *pnSizeX, INT *pnSizeY)
{
    // Check if the camera supports an arbitrary AOI
    INT nAOISupported = 0;
    BOOL bAOISupported = TRUE;
    if (is_ImageFormat(m_hCam,
        IMGFRMT_CMD_GET_ARBITRARY_AOI_SUPPORTED, 
        (void*)&nAOISupported, 
        sizeof(nAOISupported)) == IS_SUCCESS)
    {
        bAOISupported = (nAOISupported != 0);
    }

    if (bAOISupported)
    {
        // Get maximum image size
        SENSORINFO sInfo;
        is_GetSensorInfo (m_hCam, &sInfo);
        *pnSizeX = sInfo.nMaxWidth;
        *pnSizeY = sInfo.nMaxHeight;
    }
    else
    {
        // Get image size of the current format
        *pnSizeX = is_SetImageSize(m_hCam, IS_GET_IMAGE_SIZE_X, 0);
        *pnSizeY = is_SetImageSize(m_hCam, IS_GET_IMAGE_SIZE_Y, 0);
    }
}
//////////////////////////////////////////////////////////////////////////////////
// GetMaxImageSize ---------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
int ofxUeye::InitDisplayMode()
{
    int nRet = IS_NO_SUCCESS;

    if (m_hCam == NULL)
        return IS_NO_SUCCESS;

    // if some image memory exist already then free it
    if (m_pcImageMemory != NULL)
        nRet = is_FreeImageMem (m_hCam, m_pcImageMemory, m_nMemoryId);

    m_pcImageMemory = NULL;

	nRet = is_SetDisplayMode( m_hCam, IS_SET_DM_DIB);
    if(nRet == IS_SUCCESS)
    {
        if( m_si.nColorMode == IS_COLORMODE_BAYER )
        {
           // for color camera models use RGB24 mode
            m_nColorMode = IS_SET_CM_RGB24;
            m_nBitsPerPixel = 24;
			_channels = 3;
			_bitsPerPixel = 24;
        }
        else if( m_si.nColorMode == IS_COLORMODE_CBYCRY )
        {
            // for CBYCRY camera models use RGB32 mode
            m_nColorMode = IS_SET_CM_RGB32;
            m_nBitsPerPixel = 32;
			_channels = 4;
			_bitsPerPixel = 32;
        }
        else
        {
            // for monochrome camera models use Y8 mode
            m_nColorMode = IS_SET_CM_Y8;
            m_nBitsPerPixel = 8;
			_channels = 1;
			_bitsPerPixel = 8;
        }

		_bytesPerPixel = _bitsPerPixel / 8;


        // allocate an image memory.
        nRet = is_AllocImageMem(m_hCam,
            m_nSizeX,
            m_nSizeY,
            m_nBitsPerPixel,
            &m_pcImageMemory,
            &m_nMemoryId );

		_fullPixels = (unsigned char*) malloc(sizeof(unsigned char)*m_nSizeX*m_nSizeY*_channels);
    }


    if(nRet == IS_SUCCESS)
    {
        // set the image memory only for the bitmap mode when allocated
        if(m_pcImageMemory != NULL)
            nRet = is_SetImageMem( m_hCam, m_pcImageMemory, m_nMemoryId );

        // set the desired color mode
        nRet = is_SetColorMode( m_hCam, m_nColorMode );
        // set the image size to capture
		// nRet = is_SetImageSize( m_hCam, m_nSizeX, m_nSizeY );
    }   // end if(nRet == IS_SUCCESS)

    return nRet;
}
//////////////////////////////////////////////////////////////////////////////////
// ProcessuEyeMessages ------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
BOOL ofxUeye:: ProcessuEyeMessages(UINT msg, WPARAM wParam, LPARAM lParam){
	BOOL boRet = FALSE;
    switch(msg)
    {
    case IS_UEYE_MESSAGE:
        switch(wParam)
        {
        case IS_FRAME:
			if(instanceRef)instanceRef->preOnFrame();
            break;

        case IS_TRANSFER_FAILED:
            break;

        case IS_DEVICE_RECONNECTED:
			if(instanceRef)instanceRef->preOnDeviceReconected();
            break;

        case IS_MEMORY_MODE_FINISH:
            break;

        case IS_DEVICE_REMOVED:
			if(instanceRef)instanceRef->preOnDeviceRemoved();
            break;

        case IS_DEVICE_REMOVAL:
            break;

        case IS_NEW_DEVICE:
            break;

        }   // end switch(pmsg->wParam)

        // tell that this message has been processed
        boRet = TRUE;
        break;  // end case IS_UEYE_MESSAGE:
    }   // end switch(msg)

    return boRet;
}
//////////////////////////////////////////////////////////////////////////////////
// ConsoleDispWndProc ------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////
LRESULT WINAPI ofxUeye::ConsoleDispWndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch ( msg )
    {
    case IS_UEYE_MESSAGE:
        ProcessuEyeMessages(msg, wParam, lParam);
        return 0;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam); 
    }
    return 0;
}
