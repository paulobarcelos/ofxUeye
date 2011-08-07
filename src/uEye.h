/*****************************************************************************/
/*! \file    ueye.h
*   \author  (c) 2004-2011 by Imaging Development Systems GmbH
*   \date    Date: 2011/05/03
*   \version PRODUCTVERSION: 3.82
*
*   \brief   Library interface for IDS uEye - camera family.
*            definition of exported API functions and constants
*//***************************************************************************/

#ifndef __IDS_HEADER__ 
#define __IDS_HEADER__

#pragma pack(push, 8)

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/* make sure __LINUX__ is defined */
#if defined __linux__
#   if !defined __LINUX__
#       define __LINUX__
#   endif /* ! __LINUX__ */
#endif /* __linux__ */

// ----------------------------------------------------------------------------
// Version definition
// ----------------------------------------------------------------------------
#ifndef UEYE_VERSION
#   define UEYE_VERSION(major, minor, build)    (((major)<<24) + ((minor)<<16) + (build))
#endif

#ifndef UEYE_VERSION_CODE
#   define UEYE_VERSION_CODE   UEYE_VERSION(3, 82, 0)
#endif

// ----------------------------------------------------------------------------
// Driver name
// ----------------------------------------------------------------------------

#if defined(__linux__) || defined(__LINUX__)
#   define DRIVER_DLL_NAME                  "libueye_api.so"
#elif defined (_WIN64)
#   define DRIVER_DLL_NAME                  "ueye_api_64.dll"
#else
#   define DRIVER_DLL_NAME                  "ueye_api.dll"
#endif


// ----------------------------------------------------------------------------
// Color modes
// ----------------------------------------------------------------------------
#define IS_COLORMODE_INVALID                0
#define IS_COLORMODE_MONOCHROME             1
#define IS_COLORMODE_BAYER                  2
#define IS_COLORMODE_CBYCRY                 4


// ----------------------------------------------------------------------------
//  Sensor Types
// ----------------------------------------------------------------------------
#define IS_SENSOR_INVALID           0x0000

// CMOS Sensors
#define IS_SENSOR_UI141X_M          0x0001      // VGA rolling shutter, monochrome
#define IS_SENSOR_UI141X_C          0x0002      // VGA rolling shutter, color
#define IS_SENSOR_UI144X_M          0x0003      // SXGA rolling shutter, monochrome
#define IS_SENSOR_UI144X_C          0x0004      // SXGA rolling shutter, SXGA color

#define IS_SENSOR_UI154X_M          0x0030      // SXGA rolling shutter, monochrome
#define IS_SENSOR_UI154X_C          0x0031      // SXGA rolling shutter, color
#define IS_SENSOR_UI145X_C          0x0008      // UXGA rolling shutter, color

#define IS_SENSOR_UI146X_C          0x000a      // QXGA rolling shutter, color
#define IS_SENSOR_UI148X_M          0x000b      // 5MP rolling shutter, monochrome
#define IS_SENSOR_UI148X_C          0x000c      // 5MP rolling shutter, color

#define IS_SENSOR_UI121X_M          0x0010      // VGA global shutter, monochrome
#define IS_SENSOR_UI121X_C          0x0011      // VGA global shutter, VGA color
#define IS_SENSOR_UI122X_M          0x0012      // WVGA global shutter, monochrome
#define IS_SENSOR_UI122X_C          0x0013      // WVGA global shutter, color

#define IS_SENSOR_UI164X_C          0x0015      // SXGA rolling shutter, color

#define IS_SENSOR_UI155X_C          0x0017      // UXGA rolling shutter, color

#define IS_SENSOR_UI1223_M          0x0018      // WVGA global shutter, monochrome
#define IS_SENSOR_UI1223_C          0x0019      // WVGA global shutter, color

#define IS_SENSOR_UI149X_M          0x003E      // 10MP rolling shutter, monochrome
#define IS_SENSOR_UI149X_C          0x003F      // 10MP rolling shutter, color

// LE models with xxx5
#define IS_SENSOR_UI1225_M          0x0022      // WVGA global shutter, monochrome, LE model
#define IS_SENSOR_UI1225_C          0x0023      // WVGA global shutter, color, LE model

#define IS_SENSOR_UI1645_C          0x0025      // SXGA rolling shutter, color, LE model
#define IS_SENSOR_UI1555_C          0x0027      // UXGA rolling shutter, color, LE model
#define IS_SENSOR_UI1545_M          0x0028      // SXGA rolling shutter, monochrome, LE model
#define IS_SENSOR_UI1545_C          0x0029      // SXGA rolling shutter, color, LE model
#define IS_SENSOR_UI1455_C          0x002B      // UXGA rolling shutter, color, LE model
#define IS_SENSOR_UI1465_C          0x002D      // QXGA rolling shutter, color, LE model
#define IS_SENSOR_UI1485_M          0x002E      // 5MP rolling shutter, monochrome, LE model
#define IS_SENSOR_UI1485_C          0x002F      // 5MP rolling shutter, color, LE model
#define IS_SENSOR_UI1495_M          0x0040      // 10MP rolling shutter, monochrome, LE model
#define IS_SENSOR_UI1495_C          0x0041      // 10MP rolling shutter, color, LE model

#define IS_SENSOR_UI112X_M          0x004A      // 0768x576, HDR sensor, monochrome
#define IS_SENSOR_UI112X_C          0x004B      // 0768x576, HDR sensor, color

#define IS_SENSOR_UI1008_M          0x004C
#define IS_SENSOR_UI1008_C          0x004D

#define IS_SENSOR_UI1240_M          0x0050      // SXGA global shutter, monochrome
#define IS_SENSOR_UI1240_C          0x0051      // SXGA global shutter, color

// custom board level designs
#define IS_SENSOR_UI1543_M          0x0032      // SXGA rolling shutter, monochrome, single board
#define IS_SENSOR_UI1543_C          0x0033      // SXGA rolling shutter, color, single board

#define IS_SENSOR_UI1544_M          0x003A      // SXGA rolling shutter, monochrome, single board
#define IS_SENSOR_UI1544_C          0x003B      // SXGA rolling shutter, color, single board
#define IS_SENSOR_UI1543_M_WO       0x003C      // SXGA rolling shutter, monochrome, single board
#define IS_SENSOR_UI1543_C_WO       0x003D      // SXGA rolling shutter, color, single board
#define IS_SENSOR_UI1453_C          0x0035      // UXGA rolling shutter, color, single board
#define IS_SENSOR_UI1463_C          0x0037      // QXGA rolling shutter, color, single board
#define IS_SENSOR_UI1483_M          0x0038      // QSXG rolling shutter, monochrome, single board
#define IS_SENSOR_UI1483_C          0x0039      // QSXG rolling shutter, color, single board
#define IS_SENSOR_UI1493_M          0x004E      // 10Mp rolling shutter, monochrome, single board
#define IS_SENSOR_UI1493_C          0x004F      // 10MP rolling shutter, color, single board

#define IS_SENSOR_UI1463_M_WO       0x0044      // QXGA rolling shutter, monochrome, single board
#define IS_SENSOR_UI1463_C_WO       0x0045      // QXGA rolling shutter, color, single board

#define IS_SENSOR_UI1553_C_WN       0x0047      // UXGA rolling shutter, color, single board
#define IS_SENSOR_UI1483_M_WO       0x0048      // QSXGA rolling shutter, monochrome, single board
#define IS_SENSOR_UI1483_C_WO       0x0049      // QSXGA rolling shutter, color, single board

// CCD Sensors
#define IS_SENSOR_UI223X_M          0x0080      // Sony CCD sensor - XGA monochrome
#define IS_SENSOR_UI223X_C          0x0081      // Sony CCD sensor - XGA color

#define IS_SENSOR_UI241X_M          0x0082      // Sony CCD sensor - VGA monochrome
#define IS_SENSOR_UI241X_C          0x0083      // Sony CCD sensor - VGA color

#define IS_SENSOR_UI234X_M          0x0084      // Sony CCD sensor - SXGA monochrome
#define IS_SENSOR_UI234X_C          0x0085      // Sony CCD sensor - SXGA color

#define IS_SENSOR_UI221X_M          0x0088      // Sony CCD sensor - VGA monochrome
#define IS_SENSOR_UI221X_C          0x0089      // Sony CCD sensor - VGA color

#define IS_SENSOR_UI231X_M          0x0090      // Sony CCD sensor - VGA monochrome
#define IS_SENSOR_UI231X_C          0x0091      // Sony CCD sensor - VGA color

#define IS_SENSOR_UI222X_M          0x0092      // Sony CCD sensor - CCIR / PAL monochrome
#define IS_SENSOR_UI222X_C          0x0093      // Sony CCD sensor - CCIR / PAL color

#define IS_SENSOR_UI224X_M          0x0096      // Sony CCD sensor - SXGA monochrome
#define IS_SENSOR_UI224X_C          0x0097      // Sony CCD sensor - SXGA color

#define IS_SENSOR_UI225X_M          0x0098      // Sony CCD sensor - UXGA monochrome
#define IS_SENSOR_UI225X_C          0x0099      // Sony CCD sensor - UXGA color

#define IS_SENSOR_UI214X_M          0x009A      // Sony CCD sensor - SXGA monochrome
#define IS_SENSOR_UI214X_C          0x009B      // Sony CCD sensor - SXGA color

#define IS_SENSOR_UI228X_M          0x009C      // Sony CCD sensor - QXGA monochrome
#define IS_SENSOR_UI228X_C          0x009D      // Sony CCD sensor - QXGA color

// ----------------------------------------------------------------------------
// error codes
// ----------------------------------------------------------------------------
#define IS_NO_SUCCESS                        -1   // function call failed
#define IS_SUCCESS                            0   // function call succeeded
#define IS_INVALID_CAMERA_HANDLE              1   // camera handle is not valid or zero
#define IS_INVALID_HANDLE                     1   // a handle other than the camera handle is invalid

#define IS_IO_REQUEST_FAILED                  2   // an io request to the driver failed
#define IS_CANT_OPEN_DEVICE                   3   // returned by is_InitCamera
#define IS_CANT_CLOSE_DEVICE                  4
#define IS_CANT_SETUP_MEMORY                  5
#define IS_NO_HWND_FOR_ERROR_REPORT           6
#define IS_ERROR_MESSAGE_NOT_CREATED          7
#define IS_ERROR_STRING_NOT_FOUND             8
#define IS_HOOK_NOT_CREATED                   9
#define IS_TIMER_NOT_CREATED                 10
#define IS_CANT_OPEN_REGISTRY                11
#define IS_CANT_READ_REGISTRY                12
#define IS_CANT_VALIDATE_BOARD               13
#define IS_CANT_GIVE_BOARD_ACCESS            14
#define IS_NO_IMAGE_MEM_ALLOCATED            15
#define IS_CANT_CLEANUP_MEMORY               16
#define IS_CANT_COMMUNICATE_WITH_DRIVER      17
#define IS_FUNCTION_NOT_SUPPORTED_YET        18
#define IS_OPERATING_SYSTEM_NOT_SUPPORTED    19

#define IS_INVALID_VIDEO_IN                  20
#define IS_INVALID_IMG_SIZE                  21
#define IS_INVALID_ADDRESS                   22
#define IS_INVALID_VIDEO_MODE                23
#define IS_INVALID_AGC_MODE                  24
#define IS_INVALID_GAMMA_MODE                25
#define IS_INVALID_SYNC_LEVEL                26
#define IS_INVALID_CBARS_MODE                27
#define IS_INVALID_COLOR_MODE                28
#define IS_INVALID_SCALE_FACTOR              29
#define IS_INVALID_IMAGE_SIZE                30
#define IS_INVALID_IMAGE_POS                 31
#define IS_INVALID_CAPTURE_MODE              32
#define IS_INVALID_RISC_PROGRAM              33
#define IS_INVALID_BRIGHTNESS                34
#define IS_INVALID_CONTRAST                  35
#define IS_INVALID_SATURATION_U              36
#define IS_INVALID_SATURATION_V              37
#define IS_INVALID_HUE                       38
#define IS_INVALID_HOR_FILTER_STEP           39
#define IS_INVALID_VERT_FILTER_STEP          40
#define IS_INVALID_EEPROM_READ_ADDRESS       41
#define IS_INVALID_EEPROM_WRITE_ADDRESS      42
#define IS_INVALID_EEPROM_READ_LENGTH        43
#define IS_INVALID_EEPROM_WRITE_LENGTH       44
#define IS_INVALID_BOARD_INFO_POINTER        45
#define IS_INVALID_DISPLAY_MODE              46
#define IS_INVALID_ERR_REP_MODE              47
#define IS_INVALID_BITS_PIXEL                48
#define IS_INVALID_MEMORY_POINTER            49

#define IS_FILE_WRITE_OPEN_ERROR             50
#define IS_FILE_READ_OPEN_ERROR              51
#define IS_FILE_READ_INVALID_BMP_ID          52
#define IS_FILE_READ_INVALID_BMP_SIZE        53
#define IS_FILE_READ_INVALID_BIT_COUNT       54
#define IS_WRONG_KERNEL_VERSION              55

#define IS_RISC_INVALID_XLENGTH              60
#define IS_RISC_INVALID_YLENGTH              61
#define IS_RISC_EXCEED_IMG_SIZE              62

// DirectDraw Mode errors
#define IS_DD_MAIN_FAILED                    70
#define IS_DD_PRIMSURFACE_FAILED             71
#define IS_DD_SCRN_SIZE_NOT_SUPPORTED        72
#define IS_DD_CLIPPER_FAILED                 73
#define IS_DD_CLIPPER_HWND_FAILED            74
#define IS_DD_CLIPPER_CONNECT_FAILED         75
#define IS_DD_BACKSURFACE_FAILED             76
#define IS_DD_BACKSURFACE_IN_SYSMEM          77
#define IS_DD_MDL_MALLOC_ERR                 78
#define IS_DD_MDL_SIZE_ERR                   79
#define IS_DD_CLIP_NO_CHANGE                 80
#define IS_DD_PRIMMEM_NULL                   81
#define IS_DD_BACKMEM_NULL                   82
#define IS_DD_BACKOVLMEM_NULL                83
#define IS_DD_OVERLAYSURFACE_FAILED          84
#define IS_DD_OVERLAYSURFACE_IN_SYSMEM       85
#define IS_DD_OVERLAY_NOT_ALLOWED            86
#define IS_DD_OVERLAY_COLKEY_ERR             87
#define IS_DD_OVERLAY_NOT_ENABLED            88
#define IS_DD_GET_DC_ERROR                   89
#define IS_DD_DDRAW_DLL_NOT_LOADED           90
#define IS_DD_THREAD_NOT_CREATED             91
#define IS_DD_CANT_GET_CAPS                  92
#define IS_DD_NO_OVERLAYSURFACE              93
#define IS_DD_NO_OVERLAYSTRETCH              94
#define IS_DD_CANT_CREATE_OVERLAYSURFACE     95
#define IS_DD_CANT_UPDATE_OVERLAYSURFACE     96
#define IS_DD_INVALID_STRETCH                97

#define IS_EV_INVALID_EVENT_NUMBER          100
#define IS_INVALID_MODE                     101
#define IS_CANT_FIND_FALCHOOK               102
#define IS_CANT_FIND_HOOK                   102
#define IS_CANT_GET_HOOK_PROC_ADDR          103
#define IS_CANT_CHAIN_HOOK_PROC             104
#define IS_CANT_SETUP_WND_PROC              105
#define IS_HWND_NULL                        106
#define IS_INVALID_UPDATE_MODE              107
#define IS_NO_ACTIVE_IMG_MEM                108
#define IS_CANT_INIT_EVENT                  109
#define IS_FUNC_NOT_AVAIL_IN_OS             110
#define IS_CAMERA_NOT_CONNECTED             111
#define IS_SEQUENCE_LIST_EMPTY              112
#define IS_CANT_ADD_TO_SEQUENCE             113
#define IS_LOW_OF_SEQUENCE_RISC_MEM         114
#define IS_IMGMEM2FREE_USED_IN_SEQ          115
#define IS_IMGMEM_NOT_IN_SEQUENCE_LIST      116
#define IS_SEQUENCE_BUF_ALREADY_LOCKED      117
#define IS_INVALID_DEVICE_ID                118
#define IS_INVALID_BOARD_ID                 119
#define IS_ALL_DEVICES_BUSY                 120
#define IS_HOOK_BUSY                        121
#define IS_TIMED_OUT                        122
#define IS_NULL_POINTER                     123
#define IS_WRONG_HOOK_VERSION               124
#define IS_INVALID_PARAMETER                125   // a parameter specified was invalid
#define IS_NOT_ALLOWED                      126
#define IS_OUT_OF_MEMORY                    127
#define IS_INVALID_WHILE_LIVE               128
#define IS_ACCESS_VIOLATION                 129   // an internal exception occurred
#define IS_UNKNOWN_ROP_EFFECT               130
#define IS_INVALID_RENDER_MODE              131
#define IS_INVALID_THREAD_CONTEXT           132
#define IS_NO_HARDWARE_INSTALLED            133
#define IS_INVALID_WATCHDOG_TIME            134
#define IS_INVALID_WATCHDOG_MODE            135
#define IS_INVALID_PASSTHROUGH_IN           136
#define IS_ERROR_SETTING_PASSTHROUGH_IN     137
#define IS_FAILURE_ON_SETTING_WATCHDOG      138
#define IS_NO_USB20                         139   // the usb port doesnt support usb 2.0
#define IS_CAPTURE_RUNNING                  140   // there is already a capture running

#define IS_MEMORY_BOARD_ACTIVATED           141   // operation could not execute while mboard is enabled
#define IS_MEMORY_BOARD_DEACTIVATED         142   // operation could not execute while mboard is disabled
#define IS_NO_MEMORY_BOARD_CONNECTED        143   // no memory board connected
#define IS_TOO_LESS_MEMORY                  144   // image size is above memory capacity
#define IS_IMAGE_NOT_PRESENT                145   // requested image is no longer present in the camera
#define IS_MEMORY_MODE_RUNNING              146
#define IS_MEMORYBOARD_DISABLED             147

#define IS_TRIGGER_ACTIVATED                148   // operation could not execute while trigger is enabled
#define IS_WRONG_KEY                        150
#define IS_CRC_ERROR                        151
#define IS_NOT_YET_RELEASED                 152   // this feature is not available yet
#define IS_NOT_CALIBRATED                   153   // the camera is not calibrated
#define IS_WAITING_FOR_KERNEL               154   // a request to the kernel exceeded
#define IS_NOT_SUPPORTED                    155   // operation mode is not supported
#define IS_TRIGGER_NOT_ACTIVATED            156   // operation could not execute while trigger is disabled
#define IS_OPERATION_ABORTED                157
#define IS_BAD_STRUCTURE_SIZE               158
#define IS_INVALID_BUFFER_SIZE              159
#define IS_INVALID_PIXEL_CLOCK              160
#define IS_INVALID_EXPOSURE_TIME            161
#define IS_AUTO_EXPOSURE_RUNNING            162
#define IS_CANNOT_CREATE_BB_SURF            163   // error creating backbuffer surface  
#define IS_CANNOT_CREATE_BB_MIX             164   // backbuffer mixer surfaces can not be created
#define IS_BB_OVLMEM_NULL                   165   // backbuffer overlay mem could not be locked  
#define IS_CANNOT_CREATE_BB_OVL             166   // backbuffer overlay mem could not be created  
#define IS_NOT_SUPP_IN_OVL_SURF_MODE        167   // function not supported in overlay surface mode  
#define IS_INVALID_SURFACE                  168   // surface invalid
#define IS_SURFACE_LOST                     169   // surface has been lost  
#define IS_RELEASE_BB_OVL_DC                170   // error releasing backbuffer overlay DC  
#define IS_BB_TIMER_NOT_CREATED             171   // backbuffer timer could not be created  
#define IS_BB_OVL_NOT_EN                    172   // backbuffer overlay has not been enabled  
#define IS_ONLY_IN_BB_MODE                  173   // only possible in backbuffer mode 
#define IS_INVALID_COLOR_FORMAT             174   // invalid color format
#define IS_INVALID_WB_BINNING_MODE          175   // invalid binning mode for AWB 
#define IS_INVALID_I2C_DEVICE_ADDRESS       176   // invalid I2C device address
#define IS_COULD_NOT_CONVERT                177   // current image couldn't be converted
#define IS_TRANSFER_ERROR                   178   // transfer failed
#define IS_PARAMETER_SET_NOT_PRESENT        179   // the parameter set is not present
#define IS_INVALID_CAMERA_TYPE              180   // the camera type in the ini file doesn't match
#define IS_INVALID_HOST_IP_HIBYTE           181   // HIBYTE of host address is invalid
#define IS_CM_NOT_SUPP_IN_CURR_DISPLAYMODE  182   // color mode is not supported in the current display mode
#define IS_NO_IR_FILTER                     183
#define IS_STARTER_FW_UPLOAD_NEEDED         184   // device starter firmware is not compatible    

#define IS_DR_LIBRARY_NOT_FOUND                     185   // the DirectRender library could not be found
#define IS_DR_DEVICE_OUT_OF_MEMORY                  186   // insufficient graphics adapter video memory
#define IS_DR_CANNOT_CREATE_SURFACE                 187   // the image or overlay surface could not be created
#define IS_DR_CANNOT_CREATE_VERTEX_BUFFER           188   // the vertex buffer could not be created
#define IS_DR_CANNOT_CREATE_TEXTURE                 189   // the texture could not be created  
#define IS_DR_CANNOT_LOCK_OVERLAY_SURFACE           190   // the overlay surface could not be locked
#define IS_DR_CANNOT_UNLOCK_OVERLAY_SURFACE         191   // the overlay surface could not be unlocked
#define IS_DR_CANNOT_GET_OVERLAY_DC                 192   // cannot get the overlay surface DC 
#define IS_DR_CANNOT_RELEASE_OVERLAY_DC             193   // cannot release the overlay surface DC
#define IS_DR_DEVICE_CAPS_INSUFFICIENT              194   // insufficient graphics adapter capabilities
#define IS_INCOMPATIBLE_SETTING                     195   // Operation is not possible because of another incompatible setting
#define IS_DR_NOT_ALLOWED_WHILE_DC_IS_ACTIVE        196   // user App still has DC handle.
#define IS_DEVICE_ALREADY_PAIRED                    197   // The device is already paired
#define IS_SUBNETMASK_MISMATCH                      198   // The subnetmasks of the device and the adapter differ
#define IS_SUBNET_MISMATCH                          199   // The subnets of the device and the adapter differ
#define IS_INVALID_IP_CONFIGURATION                 200   // The IP configuation of the device is invalid
#define IS_DEVICE_NOT_COMPATIBLE                    201   // The device is incompatible to the driver
#define IS_NETWORK_FRAME_SIZE_INCOMPATIBLE          202   // The frame size settings of the device and the network adapter are incompatible
#define IS_NETWORK_CONFIGURATION_INVALID            203   // The network adapter configuration is invalid
#define IS_ERROR_CPU_IDLE_STATES_CONFIGURATION      204   // The setting of the CPU idle state configuration failed
// ----------------------------------------------------------------------------
// common definitions
// ----------------------------------------------------------------------------
#define IS_OFF                              0
#define IS_ON                               1
#define IS_IGNORE_PARAMETER                 -1


// ----------------------------------------------------------------------------
//  device enumeration
// ----------------------------------------------------------------------------
#define IS_USE_DEVICE_ID                    0x8000L
#define IS_ALLOW_STARTER_FW_UPLOAD          0x10000L

// ----------------------------------------------------------------------------
// AutoExit enable/disable
// ----------------------------------------------------------------------------
#define IS_GET_AUTO_EXIT_ENABLED            0x8000
#define IS_DISABLE_AUTO_EXIT                0
#define IS_ENABLE_AUTO_EXIT                 1


// ----------------------------------------------------------------------------
// live/freeze parameters
// ----------------------------------------------------------------------------
#define IS_GET_LIVE                         0x8000

#define IS_WAIT                             0x0001
#define IS_DONT_WAIT                        0x0000
#define IS_FORCE_VIDEO_STOP                 0x4000
#define IS_FORCE_VIDEO_START                0x4000
#define IS_USE_NEXT_MEM                     0x8000


// ----------------------------------------------------------------------------
// video finish constants
// ----------------------------------------------------------------------------
#define IS_VIDEO_NOT_FINISH                 0
#define IS_VIDEO_FINISH                     1


// ----------------------------------------------------------------------------
// bitmap render modes
// ----------------------------------------------------------------------------
#define IS_GET_RENDER_MODE                  0x8000

#define IS_RENDER_DISABLED                  0
#define IS_RENDER_NORMAL                    1
#define IS_RENDER_FIT_TO_WINDOW             2
#define IS_RENDER_DOWNSCALE_1_2             4
#define IS_RENDER_MIRROR_UPDOWN             16
#define IS_RENDER_DOUBLE_HEIGHT             32
#define IS_RENDER_HALF_HEIGHT               64

#define IS_USE_AS_DC_STRUCTURE     0x4000
#define IS_USE_AS_DC_HANDLE        0x8000


// ----------------------------------------------------------------------------
// external trigger modes
// ----------------------------------------------------------------------------
#define IS_GET_EXTERNALTRIGGER              0x8000
#define IS_GET_TRIGGER_STATUS               0x8001
#define IS_GET_TRIGGER_MASK                 0x8002
#define IS_GET_TRIGGER_INPUTS               0x8003
#define IS_GET_SUPPORTED_TRIGGER_MODE       0x8004
#define IS_GET_TRIGGER_COUNTER              0x8000

// old defines for compatibility 
#define IS_SET_TRIG_OFF                     0x0000
#define IS_SET_TRIG_HI_LO                   0x0001
#define IS_SET_TRIG_LO_HI                   0x0002
#define IS_SET_TRIG_SOFTWARE                0x0008
#define IS_SET_TRIG_HI_LO_SYNC              0x0010
#define IS_SET_TRIG_LO_HI_SYNC              0x0020

#define IS_SET_TRIG_MASK                    0x0100

#define IS_SET_TRIGGER_CONTINUOUS           0x1000
#define IS_SET_TRIGGER_OFF                  IS_SET_TRIG_OFF
#define IS_SET_TRIGGER_HI_LO                (IS_SET_TRIGGER_CONTINUOUS | IS_SET_TRIG_HI_LO) 
#define IS_SET_TRIGGER_LO_HI                (IS_SET_TRIGGER_CONTINUOUS | IS_SET_TRIG_LO_HI) 
#define IS_SET_TRIGGER_SOFTWARE             (IS_SET_TRIGGER_CONTINUOUS | IS_SET_TRIG_SOFTWARE) 
#define IS_SET_TRIGGER_HI_LO_SYNC           IS_SET_TRIG_HI_LO_SYNC
#define IS_SET_TRIGGER_LO_HI_SYNC           IS_SET_TRIG_LO_HI_SYNC


#define IS_GET_TRIGGER_DELAY                0x8000
#define IS_GET_MIN_TRIGGER_DELAY            0x8001
#define IS_GET_MAX_TRIGGER_DELAY            0x8002
#define IS_GET_TRIGGER_DELAY_GRANULARITY    0x8003


// ----------------------------------------------------------------------------
// Timing
// ----------------------------------------------------------------------------
// pixelclock
#define IS_GET_PIXEL_CLOCK                  0x8000
#define IS_GET_DEFAULT_PIXEL_CLK            0x8001
#define IS_GET_PIXEL_CLOCK_INC              0x8005

// frame rate
#define IS_GET_FRAMERATE                    0x8000
#define IS_GET_DEFAULT_FRAMERATE            0x8001

// exposure
#define IS_GET_EXPOSURE_TIME                        0x8000
#define IS_GET_DEFAULT_EXPOSURE                     0x8001
#define IS_GET_EXPOSURE_MIN_VALUE                   0x8002
#define IS_GET_EXPOSURE_MAX_VALUE                   0x8003
#define IS_GET_EXPOSURE_INCREMENT                   0x8004
#define IS_GET_EXPOSURE_FINE_INCREMENT              0x8005

// ----------------------------------------------------------------------------
// Gain definitions
// ----------------------------------------------------------------------------
#define IS_GET_MASTER_GAIN                  0x8000
#define IS_GET_RED_GAIN                     0x8001
#define IS_GET_GREEN_GAIN                   0x8002
#define IS_GET_BLUE_GAIN                    0x8003
#define IS_GET_DEFAULT_MASTER               0x8004
#define IS_GET_DEFAULT_RED                  0x8005
#define IS_GET_DEFAULT_GREEN                0x8006
#define IS_GET_DEFAULT_BLUE                 0x8007
#define IS_GET_GAINBOOST                    0x8008
#define IS_SET_GAINBOOST_ON                 0x0001
#define IS_SET_GAINBOOST_OFF                0x0000
#define IS_GET_SUPPORTED_GAINBOOST          0x0002
#define IS_MIN_GAIN                         0
#define IS_MAX_GAIN                         100


// ----------------------------------------------------------------------------
// Gain factor definitions
// ----------------------------------------------------------------------------
#define IS_GET_MASTER_GAIN_FACTOR           0x8000
#define IS_GET_RED_GAIN_FACTOR              0x8001
#define IS_GET_GREEN_GAIN_FACTOR            0x8002
#define IS_GET_BLUE_GAIN_FACTOR             0x8003
#define IS_SET_MASTER_GAIN_FACTOR           0x8004
#define IS_SET_RED_GAIN_FACTOR              0x8005
#define IS_SET_GREEN_GAIN_FACTOR            0x8006
#define IS_SET_BLUE_GAIN_FACTOR             0x8007
#define IS_GET_DEFAULT_MASTER_GAIN_FACTOR   0x8008
#define IS_GET_DEFAULT_RED_GAIN_FACTOR      0x8009
#define IS_GET_DEFAULT_GREEN_GAIN_FACTOR    0x800a
#define IS_GET_DEFAULT_BLUE_GAIN_FACTOR     0x800b
#define IS_INQUIRE_MASTER_GAIN_FACTOR       0x800c
#define IS_INQUIRE_RED_GAIN_FACTOR          0x800d
#define IS_INQUIRE_GREEN_GAIN_FACTOR        0x800e
#define IS_INQUIRE_BLUE_GAIN_FACTOR         0x800f


// ----------------------------------------------------------------------------
// Global Shutter definitions
// ----------------------------------------------------------------------------
#define IS_SET_GLOBAL_SHUTTER_ON            0x0001
#define IS_SET_GLOBAL_SHUTTER_OFF           0x0000
#define IS_GET_GLOBAL_SHUTTER               0x0010
#define IS_GET_SUPPORTED_GLOBAL_SHUTTER     0x0020


// ----------------------------------------------------------------------------
// Black level definitions
// ----------------------------------------------------------------------------
#define IS_GET_BL_COMPENSATION              0x8000
#define IS_GET_BL_OFFSET                    0x8001
#define IS_GET_BL_DEFAULT_MODE              0x8002
#define IS_GET_BL_DEFAULT_OFFSET            0x8003
#define IS_GET_BL_SUPPORTED_MODE            0x8004

#define IS_BL_COMPENSATION_DISABLE          0
#define IS_BL_COMPENSATION_ENABLE           1
#define IS_BL_COMPENSATION_OFFSET           32

#define IS_MIN_BL_OFFSET                    0
#define IS_MAX_BL_OFFSET                    255

// ----------------------------------------------------------------------------
// hardware gamma definitions
// ----------------------------------------------------------------------------
#define IS_GET_HW_GAMMA                     0x8000
#define IS_GET_HW_SUPPORTED_GAMMA           0x8001

#define IS_SET_HW_GAMMA_OFF                 0x0000
#define IS_SET_HW_GAMMA_ON                  0x0001

// ----------------------------------------------------------------------------
// camera LUT
// ----------------------------------------------------------------------------
#define IS_ENABLE_CAMERA_LUT                    0x0001
#define IS_SET_CAMERA_LUT_VALUES                0x0002
#define IS_ENABLE_RGB_GRAYSCALE                 0x0004
#define IS_GET_CAMERA_LUT_USER                  0x0008
#define IS_GET_CAMERA_LUT_COMPLETE              0x0010
#define IS_GET_CAMERA_LUT_SUPPORTED_CHANNELS    0x0020

// ----------------------------------------------------------------------------
// camera LUT presets
// ----------------------------------------------------------------------------
#define IS_CAMERA_LUT_IDENTITY              0x00000100
#define IS_CAMERA_LUT_NEGATIV               0x00000200
#define IS_CAMERA_LUT_GLOW1                 0x00000400
#define IS_CAMERA_LUT_GLOW2                 0x00000800
#define IS_CAMERA_LUT_ASTRO1                0x00001000
#define IS_CAMERA_LUT_RAINBOW1              0x00002000
#define IS_CAMERA_LUT_MAP1                  0x00004000
#define IS_CAMERA_LUT_COLD_HOT              0x00008000
#define IS_CAMERA_LUT_SEPIC                 0x00010000
#define IS_CAMERA_LUT_ONLY_RED              0x00020000
#define IS_CAMERA_LUT_ONLY_GREEN            0x00040000
#define IS_CAMERA_LUT_ONLY_BLUE             0x00080000

#define IS_CAMERA_LUT_64                    64
#define IS_CAMERA_LUT_128                   128


// ----------------------------------------------------------------------------
// image parameters
// ----------------------------------------------------------------------------
// brightness
#define IS_GET_BRIGHTNESS                   0x8000
#define IS_MIN_BRIGHTNESS                   0
#define IS_MAX_BRIGHTNESS                   255
#define IS_DEFAULT_BRIGHTNESS               -1
// contrast
#define IS_GET_CONTRAST                     0x8000
#define IS_MIN_CONTRAST                     0
#define IS_MAX_CONTRAST                     511
#define IS_DEFAULT_CONTRAST                 -1
// gamma
#define IS_GET_GAMMA                        0x8000
#define IS_MIN_GAMMA                        1
#define IS_MAX_GAMMA                        1000
#define IS_DEFAULT_GAMMA                    -1
// saturation   (Falcon)
#define IS_GET_SATURATION_U                 0x8000
#define IS_MIN_SATURATION_U                 0
#define IS_MAX_SATURATION_U                 200
#define IS_DEFAULT_SATURATION_U             100
#define IS_GET_SATURATION_V                 0x8001
#define IS_MIN_SATURATION_V                 0
#define IS_MAX_SATURATION_V                 200
#define IS_DEFAULT_SATURATION_V             100
// hue  (Falcon)
#define IS_GET_HUE                          0x8000
#define IS_MIN_HUE                          0
#define IS_MAX_HUE                          255
#define IS_DEFAULT_HUE                      128


// ----------------------------------------------------------------------------
// Image position and size
// ----------------------------------------------------------------------------

// deprecated defines
#define IS_GET_IMAGE_SIZE_X                 0x8000
#define IS_GET_IMAGE_SIZE_Y                 0x8001
#define IS_GET_IMAGE_SIZE_X_INC             0x8002
#define IS_GET_IMAGE_SIZE_Y_INC             0x8003
#define IS_GET_IMAGE_SIZE_X_MIN             0x8004
#define IS_GET_IMAGE_SIZE_Y_MIN             0x8005
#define IS_GET_IMAGE_SIZE_X_MAX             0x8006
#define IS_GET_IMAGE_SIZE_Y_MAX             0x8007

#define IS_GET_IMAGE_POS_X                  0x8001
#define IS_GET_IMAGE_POS_Y                  0x8002
#define IS_GET_IMAGE_POS_X_ABS              0xC001
#define IS_GET_IMAGE_POS_Y_ABS              0xC002
#define IS_GET_IMAGE_POS_X_INC              0xC003
#define IS_GET_IMAGE_POS_Y_INC              0xC004
#define IS_GET_IMAGE_POS_X_MIN              0xC005
#define IS_GET_IMAGE_POS_Y_MIN              0xC006
#define IS_GET_IMAGE_POS_X_MAX              0xC007
#define IS_GET_IMAGE_POS_Y_MAX              0xC008

#define IS_SET_IMAGEPOS_X_ABS               0x8000
#define IS_SET_IMAGEPOS_Y_ABS               0x8000
#define IS_SET_IMAGE_POS_X_ABS              0x00010000
#define IS_SET_IMAGE_POS_Y_ABS              0x00010000

// Valid defines

/* Image */
#define IS_AOI_IMAGE_SET_AOI                0x0001
#define IS_AOI_IMAGE_GET_AOI                0x0002
#define IS_AOI_IMAGE_SET_POS                0x0003
#define IS_AOI_IMAGE_GET_POS                0x0004
#define IS_AOI_IMAGE_SET_SIZE               0x0005
#define IS_AOI_IMAGE_GET_SIZE               0x0006
#define IS_AOI_IMAGE_GET_POS_MIN            0x0007
#define IS_AOI_IMAGE_GET_SIZE_MIN           0x0008
#define IS_AOI_IMAGE_GET_POS_MAX            0x0009
#define IS_AOI_IMAGE_GET_SIZE_MAX           0x0010
#define IS_AOI_IMAGE_GET_POS_INC            0x0011
#define IS_AOI_IMAGE_GET_SIZE_INC           0x0012
#define IS_AOI_IMAGE_GET_POS_X_ABS          0x0013
#define IS_AOI_IMAGE_GET_POS_Y_ABS          0x0014
#define IS_AOI_IMAGE_GET_ORIGINAL_AOI       0x0015

#define IS_AOI_IMAGE_POS_ABSOLUTE           0x10000000
 
/* Fast move */
#define IS_AOI_IMAGE_SET_POS_FAST           0x0020
#define IS_AOI_IMAGE_SET_POS_FAST_SUPPORTED 0x0021

/* Auto features */
#define IS_AOI_AUTO_BRIGHTNESS_SET_AOI      0x0030
#define IS_AOI_AUTO_BRIGHTNESS_GET_AOI      0x0031
#define IS_AOI_AUTO_WHITEBALANCE_SET_AOI    0x0032
#define IS_AOI_AUTO_WHITEBALANCE_GET_AOI    0x0033

/* Multi AOI */
#define IS_AOI_MULTI_GET_SUPPORTED_MODES    0x0100
#define IS_AOI_MULTI_SET_AOI                0x0200
#define IS_AOI_MULTI_GET_AOI                0x0400
#define IS_AOI_MULTI_DISABLE_AOI            0x0800
#define IS_AOI_MULTI_MODE_AXES              0x0001


// ----------------------------------------------------------------------------
// ROP effect constants
// ----------------------------------------------------------------------------
#define IS_GET_ROP_EFFECT                   0x8000
#define IS_GET_SUPPORTED_ROP_EFFECT         0x8001

#define IS_SET_ROP_NONE                     0
#define IS_SET_ROP_MIRROR_UPDOWN            8
#define IS_SET_ROP_MIRROR_UPDOWN_ODD        16
#define IS_SET_ROP_MIRROR_UPDOWN_EVEN       32
#define IS_SET_ROP_MIRROR_LEFTRIGHT         64


// ----------------------------------------------------------------------------
// Subsampling
// ----------------------------------------------------------------------------
#define IS_GET_SUBSAMPLING                      0x8000
#define IS_GET_SUPPORTED_SUBSAMPLING            0x8001
#define IS_GET_SUBSAMPLING_TYPE                 0x8002
#define IS_GET_SUBSAMPLING_FACTOR_HORIZONTAL    0x8004
#define IS_GET_SUBSAMPLING_FACTOR_VERTICAL      0x8008

#define IS_SUBSAMPLING_DISABLE                  0x00

#define IS_SUBSAMPLING_2X_VERTICAL              0x0001
#define IS_SUBSAMPLING_2X_HORIZONTAL            0x0002
#define IS_SUBSAMPLING_4X_VERTICAL              0x0004
#define IS_SUBSAMPLING_4X_HORIZONTAL            0x0008
#define IS_SUBSAMPLING_3X_VERTICAL              0x0010
#define IS_SUBSAMPLING_3X_HORIZONTAL            0x0020
#define IS_SUBSAMPLING_5X_VERTICAL              0x0040
#define IS_SUBSAMPLING_5X_HORIZONTAL            0x0080
#define IS_SUBSAMPLING_6X_VERTICAL              0x0100
#define IS_SUBSAMPLING_6X_HORIZONTAL            0x0200
#define IS_SUBSAMPLING_8X_VERTICAL              0x0400
#define IS_SUBSAMPLING_8X_HORIZONTAL            0x0800
#define IS_SUBSAMPLING_16X_VERTICAL             0x1000
#define IS_SUBSAMPLING_16X_HORIZONTAL           0x2000

#define IS_SUBSAMPLING_COLOR                    0x01
#define IS_SUBSAMPLING_MONO                     0x02

#define IS_SUBSAMPLING_MASK_VERTICAL            (IS_SUBSAMPLING_2X_VERTICAL | IS_SUBSAMPLING_4X_VERTICAL | IS_SUBSAMPLING_3X_VERTICAL | IS_SUBSAMPLING_5X_VERTICAL | IS_SUBSAMPLING_6X_VERTICAL | IS_SUBSAMPLING_8X_VERTICAL | IS_SUBSAMPLING_16X_VERTICAL)
#define IS_SUBSAMPLING_MASK_HORIZONTAL          (IS_SUBSAMPLING_2X_HORIZONTAL | IS_SUBSAMPLING_4X_HORIZONTAL | IS_SUBSAMPLING_3X_HORIZONTAL | IS_SUBSAMPLING_5X_HORIZONTAL | IS_SUBSAMPLING_6X_HORIZONTAL | IS_SUBSAMPLING_8X_HORIZONTAL | IS_SUBSAMPLING_16X_HORIZONTAL)

// Compatibility
#define IS_SUBSAMPLING_VERT                     IS_SUBSAMPLING_2X_VERTICAL
#define IS_SUBSAMPLING_HOR                      IS_SUBSAMPLING_2X_HORIZONTAL


// ----------------------------------------------------------------------------
// Binning
// ----------------------------------------------------------------------------
#define IS_GET_BINNING                      0x8000
#define IS_GET_SUPPORTED_BINNING            0x8001
#define IS_GET_BINNING_TYPE                 0x8002
#define IS_GET_BINNING_FACTOR_HORIZONTAL    0x8004
#define IS_GET_BINNING_FACTOR_VERTICAL      0x8008

#define IS_BINNING_DISABLE                  0x00

#define IS_BINNING_2X_VERTICAL              0x0001
#define IS_BINNING_2X_HORIZONTAL            0x0002
#define IS_BINNING_4X_VERTICAL              0x0004
#define IS_BINNING_4X_HORIZONTAL            0x0008
#define IS_BINNING_3X_VERTICAL              0x0010
#define IS_BINNING_3X_HORIZONTAL            0x0020
#define IS_BINNING_5X_VERTICAL              0x0040
#define IS_BINNING_5X_HORIZONTAL            0x0080
#define IS_BINNING_6X_VERTICAL              0x0100
#define IS_BINNING_6X_HORIZONTAL            0x0200
#define IS_BINNING_8X_VERTICAL              0x0400
#define IS_BINNING_8X_HORIZONTAL            0x0800
#define IS_BINNING_16X_VERTICAL             0x1000
#define IS_BINNING_16X_HORIZONTAL           0x2000

#define IS_BINNING_COLOR                    0x01
#define IS_BINNING_MONO                     0x02

#define IS_BINNING_MASK_VERTICAL            (IS_BINNING_2X_VERTICAL | IS_BINNING_3X_VERTICAL | IS_BINNING_4X_VERTICAL | IS_BINNING_5X_VERTICAL | IS_BINNING_6X_VERTICAL | IS_BINNING_8X_VERTICAL | IS_BINNING_16X_VERTICAL)
#define IS_BINNING_MASK_HORIZONTAL          (IS_BINNING_2X_HORIZONTAL | IS_BINNING_3X_HORIZONTAL | IS_BINNING_4X_HORIZONTAL | IS_BINNING_5X_HORIZONTAL | IS_BINNING_6X_HORIZONTAL | IS_BINNING_8X_HORIZONTAL | IS_BINNING_16X_HORIZONTAL)

// Compatibility
#define IS_BINNING_VERT                     IS_BINNING_2X_VERTICAL
#define IS_BINNING_HOR                      IS_BINNING_2X_HORIZONTAL

// ----------------------------------------------------------------------------
// Auto Control Parameter
// ----------------------------------------------------------------------------
#define IS_SET_ENABLE_AUTO_GAIN                     0x8800
#define IS_GET_ENABLE_AUTO_GAIN                     0x8801
#define IS_SET_ENABLE_AUTO_SHUTTER                  0x8802
#define IS_GET_ENABLE_AUTO_SHUTTER                  0x8803
#define IS_SET_ENABLE_AUTO_WHITEBALANCE             0x8804
#define IS_GET_ENABLE_AUTO_WHITEBALANCE             0x8805
#define IS_SET_ENABLE_AUTO_FRAMERATE                0x8806
#define IS_GET_ENABLE_AUTO_FRAMERATE                0x8807
#define IS_SET_ENABLE_AUTO_SENSOR_GAIN              0x8808
#define IS_GET_ENABLE_AUTO_SENSOR_GAIN              0x8809
#define IS_SET_ENABLE_AUTO_SENSOR_SHUTTER           0x8810
#define IS_GET_ENABLE_AUTO_SENSOR_SHUTTER           0x8811
#define IS_SET_ENABLE_AUTO_SENSOR_GAIN_SHUTTER      0x8812
#define IS_GET_ENABLE_AUTO_SENSOR_GAIN_SHUTTER      0x8813
#define IS_SET_ENABLE_AUTO_SENSOR_FRAMERATE         0x8814
#define IS_GET_ENABLE_AUTO_SENSOR_FRAMERATE         0x8815
#define IS_SET_ENABLE_AUTO_SENSOR_WHITEBALANCE      0x8816
#define IS_GET_ENABLE_AUTO_SENSOR_WHITEBALANCE      0x8817


#define IS_SET_AUTO_REFERENCE                       0x8000
#define IS_GET_AUTO_REFERENCE                       0x8001
#define IS_SET_AUTO_GAIN_MAX                        0x8002
#define IS_GET_AUTO_GAIN_MAX                        0x8003
#define IS_SET_AUTO_SHUTTER_MAX                     0x8004
#define IS_GET_AUTO_SHUTTER_MAX                     0x8005
#define IS_SET_AUTO_SPEED                           0x8006
#define IS_GET_AUTO_SPEED                           0x8007
#define IS_SET_AUTO_WB_OFFSET                       0x8008
#define IS_GET_AUTO_WB_OFFSET                       0x8009
#define IS_SET_AUTO_WB_GAIN_RANGE                   0x800A
#define IS_GET_AUTO_WB_GAIN_RANGE                   0x800B
#define IS_SET_AUTO_WB_SPEED                        0x800C
#define IS_GET_AUTO_WB_SPEED                        0x800D
#define IS_SET_AUTO_WB_ONCE                         0x800E
#define IS_GET_AUTO_WB_ONCE                         0x800F
#define IS_SET_AUTO_BRIGHTNESS_ONCE                 0x8010
#define IS_GET_AUTO_BRIGHTNESS_ONCE                 0x8011
#define IS_SET_AUTO_HYSTERESIS                      0x8012
#define IS_GET_AUTO_HYSTERESIS                      0x8013
#define IS_GET_AUTO_HYSTERESIS_RANGE                0x8014
#define IS_SET_AUTO_WB_HYSTERESIS                   0x8015
#define IS_GET_AUTO_WB_HYSTERESIS                   0x8016
#define IS_GET_AUTO_WB_HYSTERESIS_RANGE             0x8017
#define IS_SET_AUTO_SKIPFRAMES                      0x8018
#define IS_GET_AUTO_SKIPFRAMES                      0x8019
#define IS_GET_AUTO_SKIPFRAMES_RANGE                0x801A
#define IS_SET_AUTO_WB_SKIPFRAMES                   0x801B
#define IS_GET_AUTO_WB_SKIPFRAMES                   0x801C
#define IS_GET_AUTO_WB_SKIPFRAMES_RANGE             0x801D
#define IS_SET_SENS_AUTO_SHUTTER_PHOTOM             0x801E
#define IS_SET_SENS_AUTO_GAIN_PHOTOM                0x801F
#define IS_GET_SENS_AUTO_SHUTTER_PHOTOM             0x8020
#define IS_GET_SENS_AUTO_GAIN_PHOTOM                0x8021
#define IS_GET_SENS_AUTO_SHUTTER_PHOTOM_DEF         0x8022
#define IS_GET_SENS_AUTO_GAIN_PHOTOM_DEF            0x8023
#define IS_SET_SENS_AUTO_CONTRAST_CORRECTION        0x8024
#define IS_GET_SENS_AUTO_CONTRAST_CORRECTION        0x8025
#define IS_GET_SENS_AUTO_CONTRAST_CORRECTION_RANGE  0x8026
#define IS_GET_SENS_AUTO_CONTRAST_CORRECTION_INC    0x8027
#define IS_GET_SENS_AUTO_CONTRAST_CORRECTION_DEF    0x8028
#define IS_SET_SENS_AUTO_CONTRAST_FDT_AOI_ENABLE    0x8029
#define IS_GET_SENS_AUTO_CONTRAST_FDT_AOI_ENABLE    0x8030
#define IS_SET_SENS_AUTO_BACKLIGHT_COMP             0x8031
#define IS_GET_SENS_AUTO_BACKLIGHT_COMP             0x8032
#define IS_GET_SENS_AUTO_BACKLIGHT_COMP_RANGE       0x8033
#define IS_GET_SENS_AUTO_BACKLIGHT_COMP_INC         0x8034
#define IS_GET_SENS_AUTO_BACKLIGHT_COMP_DEF         0x8035
#define IS_SET_ANTI_FLICKER_MODE                    0x8036
#define IS_GET_ANTI_FLICKER_MODE                    0x8037
#define IS_GET_ANTI_FLICKER_MODE_DEF                0x8038


// ----------------------------------------------------------------------------
// Auto Control definitions
// ----------------------------------------------------------------------------
#define IS_MIN_AUTO_BRIGHT_REFERENCE          0
#define IS_MAX_AUTO_BRIGHT_REFERENCE        255
#define IS_DEFAULT_AUTO_BRIGHT_REFERENCE    128
#define IS_MIN_AUTO_SPEED                     0
#define IS_MAX_AUTO_SPEED                   100
#define IS_DEFAULT_AUTO_SPEED                50

#define IS_DEFAULT_AUTO_WB_OFFSET             0
#define IS_MIN_AUTO_WB_OFFSET               -50
#define IS_MAX_AUTO_WB_OFFSET                50
#define IS_DEFAULT_AUTO_WB_SPEED             50
#define IS_MIN_AUTO_WB_SPEED                  0
#define IS_MAX_AUTO_WB_SPEED                100
#define IS_MIN_AUTO_WB_REFERENCE              0
#define IS_MAX_AUTO_WB_REFERENCE            255


// ----------------------------------------------------------------------------
// AOI types to set/get
// ----------------------------------------------------------------------------
#define IS_SET_AUTO_BRIGHT_AOI              0x8000
#define IS_GET_AUTO_BRIGHT_AOI              0x8001
#define IS_SET_IMAGE_AOI                    0x8002
#define IS_GET_IMAGE_AOI                    0x8003
#define IS_SET_AUTO_WB_AOI                  0x8004
#define IS_GET_AUTO_WB_AOI                  0x8005



// ----------------------------------------------------------------------------
// color modes
// ----------------------------------------------------------------------------
#define IS_GET_COLOR_MODE                   0x8000

#define IS_SET_CM_RGB32                     0
#define IS_SET_CM_RGB24                     1
#define IS_SET_CM_RGB16                     2
#define IS_SET_CM_RGB15                     3
#define IS_SET_CM_Y8                        6
#define IS_SET_CM_RGB8                      7
#define IS_SET_CM_BAYER                     11
#define IS_SET_CM_UYVY                      12
#define IS_SET_CM_UYVY_MONO                 13
#define IS_SET_CM_UYVY_BAYER                14
#define IS_SET_CM_CBYCRY                    23

#define IS_SET_CM_RGBY                      24
#define IS_SET_CM_RGB30                     25
#define IS_SET_CM_Y12                       26
#define IS_SET_CM_BAYER12                   27
#define IS_SET_CM_Y16                       28
#define IS_SET_CM_BAYER16                   29

#define IS_CM_MODE_MASK                     0x007F

// planar vs packed format
#define IS_CM_FORMAT_PACKED                 0x0000
#define IS_CM_FORMAT_PLANAR                 0x2000
#define IS_CM_FORMAT_MASK                   0x2000

// BGR vs. RGB order
#define IS_CM_ORDER_BGR                     0x0000
#define IS_CM_ORDER_RGB                     0x0080
#define IS_CM_ORDER_MASK                    0x0080 


// define compliant color format names
#define IS_CM_MONO8                 IS_SET_CM_Y8                                              // occupies 8 Bit
#define IS_CM_MONO12                IS_SET_CM_Y12                                             // occupies 16 Bit
#define IS_CM_MONO16                IS_SET_CM_Y16                                             // occupies 16 Bit

#define IS_CM_BAYER_RG8             IS_SET_CM_BAYER                                           // occupies 8 Bit
#define IS_CM_BAYER_RG12            IS_SET_CM_BAYER12                                         // occupies 16 Bit
#define IS_CM_BAYER_RG16            IS_SET_CM_BAYER16                                         // occupies 16 Bit

#define IS_CM_SENSOR_RAW8           IS_SET_CM_BAYER                                           // occupies 8 Bit
#define IS_CM_SENSOR_RAW12          IS_SET_CM_BAYER12                                         // occupies 16 Bit
#define IS_CM_SENSOR_RAW16          IS_SET_CM_BAYER16                                         // occupies 16 Bit

#define IS_CM_BGR555_PACKED         (IS_SET_CM_RGB15 | IS_CM_ORDER_BGR | IS_CM_FORMAT_PACKED) // occupies 16 Bit
#define IS_CM_BGR565_PACKED         (IS_SET_CM_RGB16 | IS_CM_ORDER_BGR | IS_CM_FORMAT_PACKED) // occupies 16 Bit 

#define IS_CM_RGB8_PACKED           (IS_SET_CM_RGB24 | IS_CM_ORDER_RGB | IS_CM_FORMAT_PACKED) // occupies 24 Bit
#define IS_CM_BGR8_PACKED           (IS_SET_CM_RGB24 | IS_CM_ORDER_BGR | IS_CM_FORMAT_PACKED) // occupies 24 Bit  
#define IS_CM_RGBA8_PACKED          (IS_SET_CM_RGB32 | IS_CM_ORDER_RGB | IS_CM_FORMAT_PACKED) // occupies 32 Bit
#define IS_CM_BGRA8_PACKED          (IS_SET_CM_RGB32 | IS_CM_ORDER_BGR | IS_CM_FORMAT_PACKED) // occupies 32 Bit
#define IS_CM_RGBY8_PACKED          (IS_SET_CM_RGBY  | IS_CM_ORDER_RGB | IS_CM_FORMAT_PACKED) // occupies 32 Bit
#define IS_CM_BGRY8_PACKED          (IS_SET_CM_RGBY  | IS_CM_ORDER_BGR | IS_CM_FORMAT_PACKED) // occupies 32 Bit
#define IS_CM_RGB10V2_PACKED        (IS_SET_CM_RGB30 | IS_CM_ORDER_RGB | IS_CM_FORMAT_PACKED) // occupies 32 Bit
#define IS_CM_BGR10V2_PACKED        (IS_SET_CM_RGB30 | IS_CM_ORDER_BGR | IS_CM_FORMAT_PACKED) // occupies 32 Bit

#define IS_CM_YUV422_PACKED         //no compliant version      
#define IS_CM_UYVY_PACKED           (IS_SET_CM_UYVY | IS_CM_FORMAT_PACKED)                    // occupies 16 Bit
#define IS_CM_UYVY_MONO_PACKED      (IS_SET_CM_UYVY_MONO | IS_CM_FORMAT_PACKED)
#define IS_CM_UYVY_BAYER_PACKED     (IS_SET_CM_UYVY_BAYER | IS_CM_FORMAT_PACKED)
#define IS_CM_CBYCRY_PACKED         (IS_SET_CM_CBYCRY | IS_CM_FORMAT_PACKED)                  // occupies 16 Bit

#define IS_CM_RGB8_PLANAR           //no compliant version
#define IS_CM_RGB12_PLANAR          //no compliant version
#define IS_CM_RGB16_PLANAR          //no compliant version


#define IS_CM_ALL_POSSIBLE                  0xFFFF

// ----------------------------------------------------------------------------
// Hotpixel correction
// ----------------------------------------------------------------------------

// Deprecated defines
#define IS_GET_BPC_MODE                      0x8000
#define IS_GET_BPC_THRESHOLD                 0x8001
#define IS_GET_BPC_SUPPORTED_MODE            0x8002

#define IS_BPC_DISABLE                       0
#define IS_BPC_ENABLE_LEVEL_1                1
#define IS_BPC_ENABLE_LEVEL_2                2
#define IS_BPC_ENABLE_USER                   4
#define IS_BPC_ENABLE_SOFTWARE          IS_BPC_ENABLE_LEVEL_2
#define IS_BPC_ENABLE_HARDWARE          IS_BPC_ENABLE_LEVEL_1

#define IS_SET_BADPIXEL_LIST                 0x01
#define IS_GET_BADPIXEL_LIST                 0x02
#define IS_GET_LIST_SIZE                     0x03


// Valid defines
#define IS_HOTPIXEL_DISABLE_CORRECTION                  0x0000
#define IS_HOTPIXEL_ENABLE_SENSOR_CORRECTION            0x0001
#define IS_HOTPIXEL_ENABLE_CAMERA_CORRECTION            0x0002
#define IS_HOTPIXEL_ENABLE_SOFTWARE_USER_CORRECTION     0x0004
#define IS_HOTPIXEL_DISABLE_SENSOR_CORRECTION           0x0008

#define IS_HOTPIXEL_GET_CORRECTION_MODE                 0x8000
#define IS_HOTPIXEL_GET_SUPPORTED_CORRECTION_MODES      0x8001

#define IS_HOTPIXEL_GET_SOFTWARE_USER_LIST_EXISTS       0x8100
#define IS_HOTPIXEL_GET_SOFTWARE_USER_LIST_NUMBER       0x8101
#define IS_HOTPIXEL_GET_SOFTWARE_USER_LIST              0x8102
#define IS_HOTPIXEL_SET_SOFTWARE_USER_LIST              0x8103
#define IS_HOTPIXEL_SAVE_SOFTWARE_USER_LIST             0x8104
#define IS_HOTPIXEL_LOAD_SOFTWARE_USER_LIST             0x8105

#define IS_HOTPIXEL_GET_CAMERA_FACTORY_LIST_EXISTS      0x8106
#define IS_HOTPIXEL_GET_CAMERA_FACTORY_LIST_NUMBER      0x8107
#define IS_HOTPIXEL_GET_CAMERA_FACTORY_LIST             0x8108

#define IS_HOTPIXEL_GET_CAMERA_USER_LIST_EXISTS         0x8109
#define IS_HOTPIXEL_GET_CAMERA_USER_LIST_NUMBER         0x810A
#define IS_HOTPIXEL_GET_CAMERA_USER_LIST                0x810B
#define IS_HOTPIXEL_SET_CAMERA_USER_LIST                0x810C
#define IS_HOTPIXEL_GET_CAMERA_USER_LIST_MAX_NUMBER     0x810D
#define IS_HOTPIXEL_DELETE_CAMERA_USER_LIST             0x810E

#define IS_HOTPIXEL_GET_MERGED_CAMERA_LIST_NUMBER       0x810F
#define IS_HOTPIXEL_GET_MERGED_CAMERA_LIST              0x8110

// ----------------------------------------------------------------------------
// color correction definitions
// ----------------------------------------------------------------------------
#define IS_GET_CCOR_MODE                    0x8000
#define IS_GET_SUPPORTED_CCOR_MODE          0x8001
#define IS_GET_DEFAULT_CCOR_MODE            0x8002
#define IS_GET_CCOR_FACTOR                  0x8003
#define IS_GET_CCOR_FACTOR_MIN              0x8004
#define IS_GET_CCOR_FACTOR_MAX              0x8005
#define IS_GET_CCOR_FACTOR_DEFAULT          0x8006

#define IS_CCOR_DISABLE                     0x0000
#define IS_CCOR_ENABLE                      0x0001
#define IS_CCOR_ENABLE_NORMAL           IS_CCOR_ENABLE
#define IS_CCOR_ENABLE_BG40_ENHANCED        0x0002
#define IS_CCOR_ENABLE_HQ_ENHANCED          0x0004
#define IS_CCOR_SET_IR_AUTOMATIC            0x0080
#define IS_CCOR_FACTOR                      0x0100

#define IS_CCOR_ENABLE_MASK             (IS_CCOR_ENABLE_NORMAL | IS_CCOR_ENABLE_BG40_ENHANCED | IS_CCOR_ENABLE_HQ_ENHANCED)


// ----------------------------------------------------------------------------
// bayer algorithm modes
// ----------------------------------------------------------------------------
#define IS_GET_BAYER_CV_MODE                0x8000

#define IS_SET_BAYER_CV_NORMAL              0x0000
#define IS_SET_BAYER_CV_BETTER              0x0001
#define IS_SET_BAYER_CV_BEST                0x0002


// ----------------------------------------------------------------------------
// color converter modes
// ----------------------------------------------------------------------------
#define IS_CONV_MODE_NONE                   0x0000
#define IS_CONV_MODE_SOFTWARE               0x0001
#define IS_CONV_MODE_SOFTWARE_3X3           0x0002
#define IS_CONV_MODE_SOFTWARE_5X5           0x0004
#define IS_CONV_MODE_HARDWARE_3X3           0x0008
#define IS_CONV_MODE_OPENCL_3X3             0x0020
#define IS_CONV_MODE_OPENCL_5X5             0x0040


// ----------------------------------------------------------------------------
// Edge enhancement
// ----------------------------------------------------------------------------
#define IS_GET_EDGE_ENHANCEMENT             0x8000

#define IS_EDGE_EN_DISABLE                  0
#define IS_EDGE_EN_STRONG                   1
#define IS_EDGE_EN_WEAK                     2


// ----------------------------------------------------------------------------
// white balance modes
// ----------------------------------------------------------------------------
#define IS_GET_WB_MODE                      0x8000

#define IS_SET_WB_DISABLE                   0x0000
#define IS_SET_WB_USER                      0x0001
#define IS_SET_WB_AUTO_ENABLE               0x0002
#define IS_SET_WB_AUTO_ENABLE_ONCE          0x0004

#define IS_SET_WB_DAYLIGHT_65               0x0101
#define IS_SET_WB_COOL_WHITE                0x0102
#define IS_SET_WB_U30                       0x0103
#define IS_SET_WB_ILLUMINANT_A              0x0104
#define IS_SET_WB_HORIZON                   0x0105


// ----------------------------------------------------------------------------
// flash strobe constants
// ----------------------------------------------------------------------------
#define IS_GET_FLASHSTROBE_MODE             0x8000
#define IS_GET_FLASHSTROBE_LINE             0x8001
#define IS_GET_SUPPORTED_FLASH_IO_PORTS     0x8002

#define IS_SET_FLASH_OFF                    0
#define IS_SET_FLASH_ON                     1
#define IS_SET_FLASH_LO_ACTIVE          IS_SET_FLASH_ON
#define IS_SET_FLASH_HI_ACTIVE              2
#define IS_SET_FLASH_HIGH                   3
#define IS_SET_FLASH_LOW                    4
#define IS_SET_FLASH_LO_ACTIVE_FREERUN      5
#define IS_SET_FLASH_HI_ACTIVE_FREERUN      6
#define IS_SET_FLASH_IO_1                   0x0010
#define IS_SET_FLASH_IO_2                   0x0020
#define IS_SET_FLASH_IO_3                   0x0040
#define IS_SET_FLASH_IO_4                   0x0080
#define IS_FLASH_IO_PORT_MASK               (IS_SET_FLASH_IO_1 | IS_SET_FLASH_IO_2 | IS_SET_FLASH_IO_3 | IS_SET_FLASH_IO_4)  

#define IS_GET_FLASH_DELAY                  -1
#define IS_GET_FLASH_DURATION               -2
#define IS_GET_MAX_FLASH_DELAY              -3
#define IS_GET_MAX_FLASH_DURATION           -4
#define IS_GET_MIN_FLASH_DELAY              -5
#define IS_GET_MIN_FLASH_DURATION           -6
#define IS_GET_FLASH_DELAY_GRANULARITY      -7
#define IS_GET_FLASH_DURATION_GRANULARITY   -8

// ----------------------------------------------------------------------------
// Digital IO constants
// ----------------------------------------------------------------------------
#define IS_GET_IO                           0x8000
#define IS_GET_IO_MASK                      0x8000
#define IS_GET_INPUT_MASK                   0x8001
#define IS_GET_OUTPUT_MASK                  0x8002
#define IS_GET_SUPPORTED_IO_PORTS           0x8004


// ----------------------------------------------------------------------------
// EEPROM defines
// ----------------------------------------------------------------------------
#define IS_EEPROM_MIN_USER_ADDRESS          0
#define IS_EEPROM_MAX_USER_ADDRESS          63
#define IS_EEPROM_MAX_USER_SPACE            64


// ----------------------------------------------------------------------------
// error report modes
// ----------------------------------------------------------------------------
#define IS_GET_ERR_REP_MODE                 0x8000
#define IS_ENABLE_ERR_REP                   1
#define IS_DISABLE_ERR_REP                  0


// ----------------------------------------------------------------------------
// display mode selectors
// ----------------------------------------------------------------------------
#define IS_GET_DISPLAY_MODE                 0x8000
#define IS_GET_DISPLAY_SIZE_X               0x8000
#define IS_GET_DISPLAY_SIZE_Y               0x8001
#define IS_GET_DISPLAY_POS_X                0x8000
#define IS_GET_DISPLAY_POS_Y                0x8001

#define IS_SET_DM_DIB                       1
#define IS_SET_DM_DIRECTDRAW                2
#define IS_SET_DM_DIRECT3D                  4
#define IS_SET_DM_ALLOW_SYSMEM              0x40
#define IS_SET_DM_ALLOW_PRIMARY             0x80

// -- overlay display mode ---
#define IS_GET_DD_OVERLAY_SCALE             0x8000

#define IS_SET_DM_ALLOW_OVERLAY             0x100
#define IS_SET_DM_ALLOW_SCALING             0x200
#define IS_SET_DM_ALLOW_FIELDSKIP           0x400
#define IS_SET_DM_MONO                      0x800
#define IS_SET_DM_BAYER                     0x1000
#define IS_SET_DM_YCBCR                     0x4000

// -- backbuffer display mode ---
#define IS_SET_DM_BACKBUFFER                0x2000


// ----------------------------------------------------------------------------
// DirectRenderer commands
// ----------------------------------------------------------------------------
#define DR_GET_OVERLAY_DC                       1
#define DR_GET_MAX_OVERLAY_SIZE                 2
#define DR_GET_OVERLAY_KEY_COLOR                3
#define DR_RELEASE_OVERLAY_DC                   4
#define DR_SHOW_OVERLAY                         5         
#define DR_HIDE_OVERLAY                         6               
#define DR_SET_OVERLAY_SIZE                     7                       
#define DR_SET_OVERLAY_POSITION                 8    
#define DR_SET_OVERLAY_KEY_COLOR                9 
#define DR_SET_HWND                             10 
#define DR_ENABLE_SCALING                       11
#define DR_DISABLE_SCALING                      12
#define DR_CLEAR_OVERLAY                        13
#define DR_ENABLE_SEMI_TRANSPARENT_OVERLAY      14
#define DR_DISABLE_SEMI_TRANSPARENT_OVERLAY     15
#define DR_CHECK_COMPATIBILITY                  16
#define DR_SET_VSYNC_OFF                        17
#define DR_SET_VSYNC_AUTO                       18
#define DR_SET_USER_SYNC                        19
#define DR_GET_USER_SYNC_POSITION_RANGE         20
#define DR_LOAD_OVERLAY_FROM_FILE               21
#define DR_STEAL_NEXT_FRAME                     22
#define DR_SET_STEAL_FORMAT                     23
#define DR_GET_STEAL_FORMAT                     24
#define DR_ENABLE_IMAGE_SCALING                 25
#define DR_GET_OVERLAY_SIZE                     26
#define DR_CHECK_COLOR_MODE_SUPPORT             27


// ----------------------------------------------------------------------------
// DirectDraw keying color constants
// ----------------------------------------------------------------------------
#define IS_GET_KC_RED                       0x8000
#define IS_GET_KC_GREEN                     0x8001
#define IS_GET_KC_BLUE                      0x8002
#define IS_GET_KC_RGB                       0x8003
#define IS_GET_KC_INDEX                     0x8004
#define IS_GET_KEYOFFSET_X                  0x8000
#define IS_GET_KEYOFFSET_Y                  0x8001

// RGB-triple for default key-color in 15,16,24,32 bit mode
#define IS_SET_KC_DEFAULT                   0xFF00FF   // 0xbbggrr
// color index for default key-color in 8bit palette mode
#define IS_SET_KC_DEFAULT_8                 253


// ----------------------------------------------------------------------------
// Memoryboard
// ----------------------------------------------------------------------------
#define IS_MEMORY_GET_COUNT                 0x8000
#define IS_MEMORY_GET_DELAY                 0x8001
#define IS_MEMORY_MODE_DISABLE              0x0000
#define IS_MEMORY_USE_TRIGGER               0xFFFF


// ----------------------------------------------------------------------------
// Test image modes
// ----------------------------------------------------------------------------
#define IS_GET_TEST_IMAGE                   0x8000

#define IS_SET_TEST_IMAGE_DISABLED          0x0000
#define IS_SET_TEST_IMAGE_MEMORY_1          0x0001
#define IS_SET_TEST_IMAGE_MEMORY_2          0x0002
#define IS_SET_TEST_IMAGE_MEMORY_3          0x0003


// ----------------------------------------------------------------------------
// Led settings
// ----------------------------------------------------------------------------
#define IS_SET_LED_OFF                      0
#define IS_SET_LED_ON                       1
#define IS_SET_LED_TOGGLE                   2
#define IS_GET_LED                          0x8000


// ----------------------------------------------------------------------------
// save options
// ----------------------------------------------------------------------------
#define IS_SAVE_USE_ACTUAL_IMAGE_SIZE       0x00010000

// ----------------------------------------------------------------------------
// renumeration modes
// ----------------------------------------------------------------------------
#define IS_RENUM_BY_CAMERA                  0
#define IS_RENUM_BY_HOST                    1

// ----------------------------------------------------------------------------
// event constants
// ----------------------------------------------------------------------------
#define IS_SET_EVENT_ODD                    0
#define IS_SET_EVENT_EVEN                   1
#define IS_SET_EVENT_FRAME                  2
#define IS_SET_EVENT_EXTTRIG                3
#define IS_SET_EVENT_VSYNC                  4
#define IS_SET_EVENT_SEQ                    5
#define IS_SET_EVENT_STEAL                  6
#define IS_SET_EVENT_VPRES                  7
#define IS_SET_EVENT_TRANSFER_FAILED        8
#define IS_SET_EVENT_DEVICE_RECONNECTED     9
#define IS_SET_EVENT_MEMORY_MODE_FINISH     10
#define IS_SET_EVENT_FRAME_RECEIVED         11
#define IS_SET_EVENT_WB_FINISHED            12
#define IS_SET_EVENT_AUTOBRIGHTNESS_FINISHED 13
#define IS_SET_EVENT_OVERLAY_DATA_LOST       16

#define IS_SET_EVENT_REMOVE                 128
#define IS_SET_EVENT_REMOVAL                129
#define IS_SET_EVENT_NEW_DEVICE             130
#define IS_SET_EVENT_STATUS_CHANGED         131


// ----------------------------------------------------------------------------
// Window message defines
// ----------------------------------------------------------------------------
#define IS_UEYE_MESSAGE                     (WM_USER + 0x0100) 
  #define IS_FRAME                          0x0000
  #define IS_SEQUENCE                       0x0001
  #define IS_TRIGGER                        0x0002
  #define IS_TRANSFER_FAILED                0x0003
  #define IS_DEVICE_RECONNECTED             0x0004
  #define IS_MEMORY_MODE_FINISH             0x0005
  #define IS_FRAME_RECEIVED                 0x0006
  #define IS_GENERIC_ERROR                  0x0007
  #define IS_STEAL_VIDEO                    0x0008
  #define IS_WB_FINISHED                    0x0009
  #define IS_AUTOBRIGHTNESS_FINISHED        0x000A
  #define IS_OVERLAY_DATA_LOST              0x000B

  #define IS_DEVICE_REMOVED                 0x1000
  #define IS_DEVICE_REMOVAL                 0x1001
  #define IS_NEW_DEVICE                     0x1002
  #define IS_DEVICE_STATUS_CHANGED          0x1003


// ----------------------------------------------------------------------------
// camera id constants
// ----------------------------------------------------------------------------
#define IS_GET_CAMERA_ID                    0x8000


// ----------------------------------------------------------------------------
// camera info constants
// ----------------------------------------------------------------------------
#define IS_GET_STATUS                       0x8000

#define IS_EXT_TRIGGER_EVENT_CNT            0
#define IS_FIFO_OVR_CNT                     1
#define IS_SEQUENCE_CNT                     2
#define IS_LAST_FRAME_FIFO_OVR              3
#define IS_SEQUENCE_SIZE                    4
#define IS_VIDEO_PRESENT                    5
#define IS_STEAL_FINISHED                   6
#define IS_STORE_FILE_PATH                  7
#define IS_LUMA_BANDWIDTH_FILTER            8
#define IS_BOARD_REVISION                   9
#define IS_MIRROR_BITMAP_UPDOWN             10
#define IS_BUS_OVR_CNT                      11
#define IS_STEAL_ERROR_CNT                  12
#define IS_LOW_COLOR_REMOVAL                13
#define IS_CHROMA_COMB_FILTER               14
#define IS_CHROMA_AGC                       15
#define IS_WATCHDOG_ON_BOARD                16
#define IS_PASSTHROUGH_ON_BOARD             17
#define IS_EXTERNAL_VREF_MODE               18
#define IS_WAIT_TIMEOUT                     19
#define IS_TRIGGER_MISSED                   20
#define IS_LAST_CAPTURE_ERROR               21
#define IS_PARAMETER_SET_1                  22
#define IS_PARAMETER_SET_2                  23
#define IS_STANDBY                          24
#define IS_STANDBY_SUPPORTED                25
#define IS_QUEUED_IMAGE_EVENT_CNT           26

// ----------------------------------------------------------------------------
// interface type defines
// ----------------------------------------------------------------------------
#define IS_INTERFACE_TYPE_USB               0x40
#define IS_INTERFACE_TYPE_ETH               0x80

// ----------------------------------------------------------------------------
// board type defines
// ----------------------------------------------------------------------------
#define IS_BOARD_TYPE_FALCON                1
#define IS_BOARD_TYPE_EAGLE                 2
#define IS_BOARD_TYPE_FALCON2               3
#define IS_BOARD_TYPE_FALCON_PLUS           7
#define IS_BOARD_TYPE_FALCON_QUATTRO        9
#define IS_BOARD_TYPE_FALCON_DUO            10
#define IS_BOARD_TYPE_EAGLE_QUATTRO         11
#define IS_BOARD_TYPE_EAGLE_DUO             12
#define IS_BOARD_TYPE_UEYE_USB              (IS_INTERFACE_TYPE_USB + 0)     // 0x40
#define IS_BOARD_TYPE_UEYE_USB_SE           IS_BOARD_TYPE_UEYE_USB          // 0x40
#define IS_BOARD_TYPE_UEYE_USB_RE           IS_BOARD_TYPE_UEYE_USB          // 0x40
#define IS_BOARD_TYPE_UEYE_USB_ME           (IS_INTERFACE_TYPE_USB + 0x01)  // 0x41
#define IS_BOARD_TYPE_UEYE_USB_LE           (IS_INTERFACE_TYPE_USB + 0x02)  // 0x42
#define IS_BOARD_TYPE_UEYE_USB_XS           (IS_INTERFACE_TYPE_USB + 0x03)  // 0x43
#define IS_BOARD_TYPE_UEYE_ETH              IS_INTERFACE_TYPE_ETH           // 0x80
#define IS_BOARD_TYPE_UEYE_ETH_HE           IS_BOARD_TYPE_UEYE_ETH          // 0x80
#define IS_BOARD_TYPE_UEYE_ETH_SE           (IS_INTERFACE_TYPE_ETH + 0x01)  // 0x81
#define IS_BOARD_TYPE_UEYE_ETH_RE           IS_BOARD_TYPE_UEYE_ETH_SE       // 0x81
#define IS_BOARD_TYPE_UEYE_ETH_CP           (IS_INTERFACE_TYPE_ETH + 0x04)  // 0x84

// ----------------------------------------------------------------------------
// camera type defines
// ----------------------------------------------------------------------------
#define IS_CAMERA_TYPE_UEYE_USB         IS_BOARD_TYPE_UEYE_USB_SE
#define IS_CAMERA_TYPE_UEYE_USB_SE      IS_BOARD_TYPE_UEYE_USB_SE
#define IS_CAMERA_TYPE_UEYE_USB_RE      IS_BOARD_TYPE_UEYE_USB_RE
#define IS_CAMERA_TYPE_UEYE_USB_ME      IS_BOARD_TYPE_UEYE_USB_ME
#define IS_CAMERA_TYPE_UEYE_USB_LE      IS_BOARD_TYPE_UEYE_USB_LE
#define IS_CAMERA_TYPE_UEYE_ETH         IS_BOARD_TYPE_UEYE_ETH_HE
#define IS_CAMERA_TYPE_UEYE_ETH_HE      IS_BOARD_TYPE_UEYE_ETH_HE
#define IS_CAMERA_TYPE_UEYE_ETH_SE      IS_BOARD_TYPE_UEYE_ETH_SE
#define IS_CAMERA_TYPE_UEYE_ETH_RE      IS_BOARD_TYPE_UEYE_ETH_RE
#define IS_CAMERA_TYPE_UEYE_ETH_CP      IS_BOARD_TYPE_UEYE_ETH_CP

// ----------------------------------------------------------------------------
// readable operation system defines
// ----------------------------------------------------------------------------
#define IS_OS_UNDETERMINED                  0
#define IS_OS_WIN95                         1
#define IS_OS_WINNT40                       2
#define IS_OS_WIN98                         3
#define IS_OS_WIN2000                       4
#define IS_OS_WINXP                         5
#define IS_OS_WINME                         6
#define IS_OS_WINNET                        7
#define IS_OS_WINSERVER2003                 8
#define IS_OS_WINVISTA                      9
#define IS_OS_LINUX24                       10
#define IS_OS_LINUX26                       11
#define IS_OS_WIN7                          12


// ----------------------------------------------------------------------------
// Bus speed
// ----------------------------------------------------------------------------
#define IS_USB_10                           0x0001 //  1,5 Mb/s
#define IS_USB_11                           0x0002 //   12 Mb/s
#define IS_USB_20                           0x0004 //  480 Mb/s
#define IS_USB_30                           0x0008 // 5000 Mb/s
#define IS_ETHERNET_10                      0x0080 //   10 Mb/s
#define IS_ETHERNET_100                     0x0100 //  100 Mb/s
#define IS_ETHERNET_1000                    0x0200 // 1000 Mb/s
#define IS_ETHERNET_10000                   0x0400 //10000 Mb/s

#define IS_USB_LOW_SPEED                    1
#define IS_USB_FULL_SPEED                   12
#define IS_USB_HIGH_SPEED                   480
#define IS_USB_SUPER_SPEED                  5000
#define IS_ETHERNET_10Base                  10
#define IS_ETHERNET_100Base                 100
#define IS_ETHERNET_1000Base                1000
#define IS_ETHERNET_10GBase                 10000

// ----------------------------------------------------------------------------
// HDR
// ----------------------------------------------------------------------------
#define IS_HDR_NOT_SUPPORTED                0
#define IS_HDR_KNEEPOINTS                   1
#define IS_DISABLE_HDR                      0
#define IS_ENABLE_HDR                       1


// ----------------------------------------------------------------------------
// Test images
// ----------------------------------------------------------------------------
#define IS_TEST_IMAGE_NONE                          0x00000000
#define IS_TEST_IMAGE_WHITE                         0x00000001
#define IS_TEST_IMAGE_BLACK                         0x00000002
#define IS_TEST_IMAGE_HORIZONTAL_GREYSCALE          0x00000004
#define IS_TEST_IMAGE_VERTICAL_GREYSCALE            0x00000008
#define IS_TEST_IMAGE_DIAGONAL_GREYSCALE            0x00000010
#define IS_TEST_IMAGE_WEDGE_GRAY                    0x00000020
#define IS_TEST_IMAGE_WEDGE_COLOR                   0x00000040
#define IS_TEST_IMAGE_ANIMATED_WEDGE_GRAY           0x00000080

#define IS_TEST_IMAGE_ANIMATED_WEDGE_COLOR          0x00000100
#define IS_TEST_IMAGE_MONO_BARS                     0x00000200
#define IS_TEST_IMAGE_COLOR_BARS1                   0x00000400
#define IS_TEST_IMAGE_COLOR_BARS2                   0x00000800
#define IS_TEST_IMAGE_GREYSCALE1                    0x00001000
#define IS_TEST_IMAGE_GREY_AND_COLOR_BARS           0x00002000
#define IS_TEST_IMAGE_MOVING_GREY_AND_COLOR_BARS    0x00004000
#define IS_TEST_IMAGE_ANIMATED_LINE                 0x00008000

#define IS_TEST_IMAGE_ALTERNATE_PATTERN             0x00010000
#define IS_TEST_IMAGE_VARIABLE_GREY                 0x00020000
#define IS_TEST_IMAGE_MONOCHROME_HORIZONTAL_BARS    0x00040000
#define IS_TEST_IMAGE_MONOCHROME_VERTICAL_BARS      0x00080000
#define IS_TEST_IMAGE_CURSOR_H                      0x00100000
#define IS_TEST_IMAGE_CURSOR_V                      0x00200000
#define IS_TEST_IMAGE_COLDPIXEL_GRID                0x00400000
#define IS_TEST_IMAGE_HOTPIXEL_GRID                 0x00800000

#define IS_TEST_IMAGE_VARIABLE_RED_PART             0x01000000
#define IS_TEST_IMAGE_VARIABLE_GREEN_PART           0x02000000
#define IS_TEST_IMAGE_VARIABLE_BLUE_PART            0x04000000
#define IS_TEST_IMAGE_SHADING_IMAGE                 0x08000000
#define IS_TEST_IMAGE_WEDGE_GRAY_SENSOR             0x10000000
#define IS_TEST_IMAGE_ANIMATED_WEDGE_GRAY_SENSOR    0x20000000
#define IS_TEST_IMAGE_RAMPING_PATTERN               0x40000000
//                                                  0x80000000


// ----------------------------------------------------------------------------
// Sensor scaler
// ----------------------------------------------------------------------------
#define IS_ENABLE_SENSOR_SCALER             1
#define IS_ENABLE_ANTI_ALIASING             2


// ----------------------------------------------------------------------------
// Timeouts
// ----------------------------------------------------------------------------
#define IS_TRIGGER_TIMEOUT                  0


// ----------------------------------------------------------------------------
// Auto pixel clock modes
// ----------------------------------------------------------------------------
#define IS_BEST_PCLK_RUN_ONCE               0

// ----------------------------------------------------------------------------
// sequence flags
// ----------------------------------------------------------------------------
#define IS_LOCK_LAST_BUFFER                 0x8002
#define IS_GET_ALLOC_ID_OF_THIS_BUF         0x8004
#define IS_GET_ALLOC_ID_OF_LAST_BUF         0x8008
#define IS_USE_ALLOC_ID                     0x8000
#define IS_USE_CURRENT_IMG_SIZE             0xC000

// ------------------------------------------
// memory information flags
// ------------------------------------------
#define IS_GET_D3D_MEM                  0x8000


// ----------------------------------------------------------------------------
// Image files types
// ----------------------------------------------------------------------------
#define IS_IMG_BMP                          0
#define IS_IMG_JPG                          1
#define IS_IMG_PNG                          2
#define IS_IMG_RAW                          4
#define IS_IMG_TIF                          8

// ----------------------------------------------------------------------------
// I2C defines
// nRegisterAddr | IS_I2C_16_BIT_REGISTER
// ----------------------------------------------------------------------------
#define IS_I2C_16_BIT_REGISTER              0x10000000

// ----------------------------------------------------------------------------
// DirectDraw steal video constants   (Falcon)
// ----------------------------------------------------------------------------
#define IS_INIT_STEAL_VIDEO                 1
#define IS_EXIT_STEAL_VIDEO                 2
#define IS_INIT_STEAL_VIDEO_MANUAL          3
#define IS_INIT_STEAL_VIDEO_AUTO            4
#define IS_SET_STEAL_RATIO                  64
#define IS_USE_MEM_IMAGE_SIZE               128
#define IS_STEAL_MODES_MASK                 7
#define IS_SET_STEAL_COPY                   0x1000
#define IS_SET_STEAL_NORMAL                 0x2000

// ----------------------------------------------------------------------------
// AGC modes   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_AGC_MODE                     0x8000
#define IS_SET_AGC_OFF                      0
#define IS_SET_AGC_ON                       1


// ----------------------------------------------------------------------------
// Gamma modes   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_GAMMA_MODE                   0x8000
#define IS_SET_GAMMA_OFF                    0
#define IS_SET_GAMMA_ON                     1


// ----------------------------------------------------------------------------
// sync levels   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_SYNC_LEVEL                   0x8000
#define IS_SET_SYNC_75                      0
#define IS_SET_SYNC_125                     1


// ----------------------------------------------------------------------------
// color bar modes   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_CBARS_MODE                   0x8000
#define IS_SET_CBARS_OFF                    0
#define IS_SET_CBARS_ON                     1


// ----------------------------------------------------------------------------
// horizontal filter defines   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_HOR_FILTER_MODE              0x8000
#define IS_GET_HOR_FILTER_STEP              0x8001

#define IS_DISABLE_HOR_FILTER               0
#define IS_ENABLE_HOR_FILTER                1
#define IS_HOR_FILTER_STEP(_s_)         ((_s_ + 1) << 1)
#define IS_HOR_FILTER_STEP1                 2
#define IS_HOR_FILTER_STEP2                 4
#define IS_HOR_FILTER_STEP3                 6


// ----------------------------------------------------------------------------
// vertical filter defines   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_VERT_FILTER_MODE             0x8000
#define IS_GET_VERT_FILTER_STEP             0x8001

#define IS_DISABLE_VERT_FILTER              0
#define IS_ENABLE_VERT_FILTER               1
#define IS_VERT_FILTER_STEP(_s_)        ((_s_ + 1) << 1)
#define IS_VERT_FILTER_STEP1                2
#define IS_VERT_FILTER_STEP2                4
#define IS_VERT_FILTER_STEP3                6


// ----------------------------------------------------------------------------
// scaler modes   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_SCALER_MODE          (float) 1000
#define IS_SET_SCALER_OFF           (float) 0
#define IS_SET_SCALER_ON            (float) 1

#define IS_MIN_SCALE_X              (float)   6.25
#define IS_MAX_SCALE_X              (float) 100.00
#define IS_MIN_SCALE_Y              (float)   6.25
#define IS_MAX_SCALE_Y              (float) 100.00


// ----------------------------------------------------------------------------
// video source selectors   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_VIDEO_IN                     0x8000
#define IS_GET_VIDEO_PASSTHROUGH            0x8000
#define IS_GET_VIDEO_IN_TOGGLE              0x8001
#define IS_GET_TOGGLE_INPUT_1               0x8000
#define IS_GET_TOGGLE_INPUT_2               0x8001
#define IS_GET_TOGGLE_INPUT_3               0x8002
#define IS_GET_TOGGLE_INPUT_4               0x8003

#define IS_SET_VIDEO_IN_1                   0x00
#define IS_SET_VIDEO_IN_2                   0x01
#define IS_SET_VIDEO_IN_S                   0x02
#define IS_SET_VIDEO_IN_3                   0x03
#define IS_SET_VIDEO_IN_4                   0x04
#define IS_SET_VIDEO_IN_1S                  0x10
#define IS_SET_VIDEO_IN_2S                  0x11
#define IS_SET_VIDEO_IN_3S                  0x13
#define IS_SET_VIDEO_IN_4S                  0x14
#define IS_SET_VIDEO_IN_EXT                 0x40
#define IS_SET_TOGGLE_OFF                   0xFF
#define IS_SET_VIDEO_IN_SYNC                0x4000


// ----------------------------------------------------------------------------
// video crossbar selectors   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_CROSSBAR                     0x8000

#define IS_CROSSBAR_1                       0
#define IS_CROSSBAR_2                       1
#define IS_CROSSBAR_3                       2
#define IS_CROSSBAR_4                       3
#define IS_CROSSBAR_5                       4
#define IS_CROSSBAR_6                       5
#define IS_CROSSBAR_7                       6
#define IS_CROSSBAR_8                       7
#define IS_CROSSBAR_9                       8
#define IS_CROSSBAR_10                      9
#define IS_CROSSBAR_11                      10
#define IS_CROSSBAR_12                      11
#define IS_CROSSBAR_13                      12
#define IS_CROSSBAR_14                      13
#define IS_CROSSBAR_15                      14
#define IS_CROSSBAR_16                      15
#define IS_SELECT_AS_INPUT                  128


// ----------------------------------------------------------------------------
// video format selectors   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_VIDEO_MODE                   0x8000

#define IS_SET_VM_PAL                       0
#define IS_SET_VM_NTSC                      1
#define IS_SET_VM_SECAM                     2
#define IS_SET_VM_AUTO                      3


// ----------------------------------------------------------------------------
// capture modes   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_CAPTURE_MODE                 0x8000

#define IS_SET_CM_ODD                       0x0001
#define IS_SET_CM_EVEN                      0x0002
#define IS_SET_CM_FRAME                     0x0004
#define IS_SET_CM_NONINTERLACED             0x0008
#define IS_SET_CM_NEXT_FRAME                0x0010
#define IS_SET_CM_NEXT_FIELD                0x0020
#define IS_SET_CM_BOTHFIELDS            (IS_SET_CM_ODD | IS_SET_CM_EVEN | IS_SET_CM_NONINTERLACED)
#define IS_SET_CM_FRAME_STEREO              0x2004


// ----------------------------------------------------------------------------
// display update mode constants   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_UPDATE_MODE                  0x8000
#define IS_SET_UPDATE_TIMER                 1
#define IS_SET_UPDATE_EVENT                 2


// ----------------------------------------------------------------------------
// sync generator mode constants   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_SYNC_GEN                     0x8000
#define IS_SET_SYNC_GEN_OFF                 0
#define IS_SET_SYNC_GEN_ON                  1


// ----------------------------------------------------------------------------
// decimation modes   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_DECIMATION_MODE              0x8000
#define IS_GET_DECIMATION_NUMBER            0x8001

#define IS_DECIMATION_OFF                   0
#define IS_DECIMATION_CONSECUTIVE           1
#define IS_DECIMATION_DISTRIBUTED           2


// ----------------------------------------------------------------------------
// hardware watchdog defines   (Falcon)
// ----------------------------------------------------------------------------
#define IS_GET_WATCHDOG_TIME                0x2000
#define IS_GET_WATCHDOG_RESOLUTION          0x4000
#define IS_GET_WATCHDOG_ENABLE              0x8000

#define IS_WATCHDOG_MINUTES                 0
#define IS_WATCHDOG_SECONDS                 0x8000
#define IS_DISABLE_WATCHDOG                 0
#define IS_ENABLE_WATCHDOG                  1
#define IS_RETRIGGER_WATCHDOG               2
#define IS_ENABLE_AUTO_DEACTIVATION         4
#define IS_DISABLE_AUTO_DEACTIVATION        8
#define IS_WATCHDOG_RESERVED                0x1000


// ----------------------------------------------------------------------------
// typedefs
// ----------------------------------------------------------------------------
#ifdef __LINUX__
        #define FORCEINLINE         inline
        #define USHORT              IS_U16

		#include <unistd.h>

		#define Sleep(n)       usleep(n)

		#include <stdint.h>

        // aliases for common Win32 types
        typedef int32_t           BOOLEAN;
        typedef int32_t           BOOL;
        typedef int32_t           INT;
        typedef uint32_t          UINT;
        typedef int32_t           LONG;
        typedef void              VOID;
        typedef void*             LPVOID;
        typedef uint32_t          ULONG;

        typedef uint64_t          UINT64;
        typedef int64_t           __int64;
        typedef int64_t           LONGLONG;
        typedef uint32_t          DWORD;
        typedef uint16_t          WORD;

        typedef unsigned char     BYTE;
        typedef char              CHAR;
        typedef char              TCHAR;
        typedef unsigned char     UCHAR;

        typedef int8_t*           LPTSTR;
        typedef const int8_t*     LPCTSTR;
        typedef const int8_t*     LPCSTR;
        typedef uint32_t          WPARAM;
        typedef uint32_t          LPARAM;
        typedef uint32_t          LRESULT;
        typedef uint32_t          HRESULT;

        typedef void*             HWND;
        typedef void*             HGLOBAL;
        typedef void*             HINSTANCE;
        typedef void*             HDC;
        typedef void*             HMODULE;
        typedef void*             HKEY;
        typedef void*             HANDLE;

        typedef BYTE*             LPBYTE;
        typedef DWORD*            PDWORD;
        typedef VOID*             PVOID;
        typedef CHAR*             PCHAR;

				

    #ifndef FALSE
        #define FALSE 0
    #endif
    #ifndef TRUE
        #define TRUE 1
    #endif

    #ifndef HIBYTE
        #define HIBYTE(_x_)    ( (_x_)>>8 )
    #endif

    #ifndef LOBYTE
        #define LOBYTE(_x_)    ( (_x_)&0x00ff )
    #endif

    #ifndef HIWORD
        #define HIWORD(_x_)    ( (_x_)>>16 )
    #endif

    #ifndef LOWORD
        #define LOWORD(_x_)    ( (_x_)&0x0000ffff )
    #endif

    #ifndef _min_
        #define _min_( _x_, _y_ ) ( (_x_)<(_y_) ? (_x_) : (_y_) )
    #endif

    #ifndef _max_
        #define _max_( _x_, _y_ ) ( (_x_)>(_y_) ? (_x_) : (_y_) )
    #endif

    #ifndef WM_USER
        #define WM_USER        0x400
    #endif

        // unknown stuff for Linux
        #define WINAPI
        #define CALLBACK
        #undef  UNICODE
        #define __stdcall
#if defined __i386__
        #define IDSEXP    __attribute__((cdecl)) INT
        #define IDSEXPUL  __attribute__((cdecl)) ULONG
#else
        #define IDSEXP    INT
        #define IDSEXPUL  ULONG
#endif

        typedef long (*WNDPROC) (HWND, UINT, WPARAM, LPARAM);
#if 0
        typedef union _LARGE_INTEGER
        {
            struct
            {
                DWORD LowPart;
                LONG HighPart;
            };
            struct
            {
                DWORD LowPart;
                LONG HighPart;
            } u;
            LONGLONG QuadPart;
        } LARGE_INTEGER, *PLARGE_INTEGER;

        //useful structs that were in windows.h
        typedef struct tagRECT
        {
            long    left;
            long    top;
            long    right;
            long    bottom;
        } RECT, *PRECT, *LPRECT;

        typedef struct tagRGNDATAHEADER
        {
            DWORD   dwSize;
            DWORD   iType;
            DWORD   nCount;
            DWORD   nRgnSize;
            RECT    rcBound;
        } RGNDATAHEADER, *PRGNDATAHEADER;

        typedef struct tagRGNDATA
        {
            RGNDATAHEADER   rdh;
            char            Buffer[1];
        } RGNDATA, *PRGNDATA, *LPRGNDATA;


        typedef struct tagBITMAPINFOHEADER
        {
                DWORD      biSize;
                long       biWidth;
                long       biHeight;
                WORD       biPlanes;
                WORD       biBitCount;
                DWORD      biCompression;
                DWORD      biSizeImage;
                long       biXPelsPerMeter;
                long       biYPelsPerMeter;
                DWORD      biClrUsed;
                DWORD      biClrImportant;
        } BITMAPINFOHEADER, *PBITMAPINFOHEADER, *LPBITMAPINFOHEADER;

        typedef struct tagRGBQUAD
        {
                BYTE    rgbBlue;
                BYTE    rgbGreen;
                BYTE    rgbRed;
                BYTE    rgbReserved;
        } RGBQUAD;

        typedef struct tagBITMAPINFO
        {
            BITMAPINFOHEADER    bmiHeader;
            RGBQUAD             bmiColors[1];
        } BITMAPINFO, *PBITMAPINFO, *LPBITMAPINFO;
#endif /* 0 */

    #define ZeroMemory(a,b)      memset((a), 0, (b))
    #define OutputDebugString(s) fprintf(stderr, s)


    #define INFINITE    -1
#else

#include <windows.h>

#if defined (_MSC_VER) || defined (__BORLANDC__) || defined (_WIN32_WCE)
  #if defined (_PURE_C) && !defined (_IDS_EXPORT) && !defined (_FALC_EXPORT)
    #define IDSEXP     extern  __declspec(dllimport) INT __cdecl
    #define IDSEXPUL   extern  __declspec(dllimport) ULONG __cdecl
  #elif defined (__STDC__) && !defined (_IDS_EXPORT) && !defined (_FALC_EXPORT)
    #define IDSEXP   extern  __declspec(dllimport) INT __cdecl
    #define IDSEXPUL extern  __declspec(dllimport) ULONG __cdecl
  #elif !defined (_IDS_EXPORT) && !defined (_FALC_EXPORT)   // using the DLL, not creating one
    #define IDSEXP   extern "C" __declspec(dllimport) INT __cdecl
    #define IDSEXPUL extern "C" __declspec(dllimport) ULONG __cdecl
  #elif defined (_IDS_VBSTD) || defined (_FALC_VBSTD)     // for creating stdcall dll
    #define IDSEXP    extern __declspec(dllexport) INT __stdcall
    #define IDSEXPUL  extern __declspec(dllexport) ULONG __stdcall
  #else            // for creating cdecl dll
    #define IDSEXP    extern  __declspec(dllexport) INT __cdecl
    #define IDSEXPUL  extern  __declspec(dllexport) ULONG __cdecl
  #endif
#elif !defined (_IDS_EXPORT) && !defined (_FALC_EXPORT)  // using the DLL, not creating one
  #define IDSEXP    extern  __declspec(dllimport) INT __cdecl
  #define IDSEXPUL  extern  __declspec(dllimport) ULONG __cdecl
#endif

typedef int     INT;

#endif    // Linux

#ifdef _WIN32_WCE
  typedef TCHAR IS_CHAR;
#else
  typedef char IS_CHAR;
#endif


// ----------------------------------------------------------------------------
// typedefs
// ----------------------------------------------------------------------------
typedef DWORD   HIDS;
#define HIDS_DEFINED

typedef DWORD   HCAM;
#define HCAM_DEFINED

typedef DWORD   HFALC;
#define HFALC_DEFINED

// ----------------------------------------------------------------------------
// invalid values for device handles
// ----------------------------------------------------------------------------
#define IS_INVALID_HIDS (HIDS)0
#define IS_INVALID_HCAM (HIDS)0
#define IS_INVALID_HFALC (HIDS)0


// ----------------------------------------------------------------------------
// info struct
// ----------------------------------------------------------------------------
#define FALCINFO   BOARDINFO
#define PFALCINFO  PBOARDINFO
#define CAMINFO    BOARDINFO
#define PCAMINFO   PBOARDINFO

typedef struct
{
  char          SerNo[12];          // e.g. "1234512345"  (11 char)
  char          ID[20];             // e.g. "IDS GmbH"
  char          Version[10];        // e.g. "V2.10"  (9 char)
  char          Date[12];           // e.g. "24.01.2006" (11 char)
  unsigned char Select;             // contains board select number for multi board support
  unsigned char Type;               // e.g. IS_BOARD_TYPE_UEYE_USB
  char          Reserved[8];        // (7 char)
} BOARDINFO, *PBOARDINFO;


typedef struct _SENSORINFO
{
  WORD          SensorID;           // e.g. IS_SENSOR_UI224X_C
  IS_CHAR       strSensorName[32];  // e.g. "UI-224X-C"
  char          nColorMode;         // e.g. IS_COLORMODE_BAYER
  DWORD         nMaxWidth;          // e.g. 1280
  DWORD         nMaxHeight;         // e.g. 1024
  BOOL          bMasterGain;        // e.g. TRUE
  BOOL          bRGain;             // e.g. TRUE
  BOOL          bGGain;             // e.g. TRUE
  BOOL          bBGain;             // e.g. TRUE
  BOOL          bGlobShutter;       // e.g. TRUE
  char          Reserved[16];       // not used
} SENSORINFO, *PSENSORINFO;


typedef struct _REVISIONINFO
{
    WORD  size;                     // 2
    WORD  Sensor;                   // 2
    WORD  Cypress;                  // 2
    DWORD Blackfin;                 // 4
    WORD  DspFirmware;              // 2
                                    // --12
    WORD  USB_Board;                // 2
    WORD  Sensor_Board;             // 2
    WORD  Processing_Board;         // 2
    WORD  Memory_Board;             // 2
    WORD  Housing;                  // 2
    WORD  Filter;                   // 2
    WORD  Timing_Board;             // 2
    WORD  Product;                  // 2
    WORD  Power_Board;              // 2
    WORD  Logic_Board;              // 2
                                    // --28
    BYTE reserved[96];              // --128
} REVISIONINFO, *PREVISIONINFO;



// ----------------------------------------------------------------------------
// Capture errors
// ----------------------------------------------------------------------------
typedef enum _UEYE_CAPTURE_ERROR
{
    IS_CAPERR_API_NO_DEST_MEM=              0xa2,
    IS_CAPERR_API_CONVERSION_FAILED=        0xa3,
    IS_CAPERR_API_IMAGE_LOCKED=             0xa5,

    IS_CAPERR_DRV_OUT_OF_BUFFERS=           0xb2,
    IS_CAPERR_DRV_DEVICE_NOT_READY=         0xb4,

    IS_CAPERR_USB_TRANSFER_FAILED=          0xc7,

    IS_CAPERR_DEV_TIMEOUT=                  0xd6,

    IS_CAPERR_ETH_BUFFER_OVERRUN=           0xe4,
    IS_CAPERR_ETH_MISSED_IMAGES=            0xe5

} UEYE_CAPTURE_ERROR;

typedef struct _UEYE_CAPTURE_ERROR_INFO
{
    DWORD dwCapErrCnt_Total;

    BYTE  reserved[60];

    DWORD adwCapErrCnt_Detail[256]; // access via UEYE_CAPTURE_ERROR

} UEYE_CAPTURE_ERROR_INFO;



#ifndef UEYE_CAMERA_INFO_STRUCT
#define UEYE_CAMERA_INFO_STRUCT
typedef struct _UEYE_CAMERA_INFO
{
  DWORD     dwCameraID;   // this is the user definable camera ID
  DWORD     dwDeviceID;   // this is the systems enumeration ID
  DWORD     dwSensorID;   // this is the sensor ID e.g. IS_SENSOR_UI141X_M
  DWORD     dwInUse;      // flag, whether the camera is in use or not
  IS_CHAR   SerNo[16];    // serial number of the camera
  IS_CHAR   Model[16];    // model name of the camera
  DWORD     dwStatus;     // various flags with camera status
  DWORD     dwReserved[15];
}UEYE_CAMERA_INFO, *PUEYE_CAMERA_INFO;
#endif //UEYE_CAMERA_INFO_STRUCT

// usage of the list:
// 1. call the DLL with .dwCount = 0
// 2. DLL returns .dwCount = N  (N = number of available cameras)
// 3. call DLL with .dwCount = N and a pointer to UEYE_CAMERA_LIST with
//    and array of UEYE_CAMERA_INFO[N]
// 4. DLL will fill in the array with the camera infos and
//    will update the .dwCount member with the actual number of cameras
//    because there may be a change in number of cameras between step 2 and 3
// 5. check if there's a difference in actual .dwCount and formerly
//    reported value of N and call DLL again with an updated array size
#ifndef UEYE_CAMERA_LIST_STRUCT
#define UEYE_CAMERA_LIST_STRUCT
typedef struct _UEYE_CAMERA_LIST
{
  ULONG     dwCount;
  UEYE_CAMERA_INFO uci[1];
}UEYE_CAMERA_LIST, *PUEYE_CAMERA_LIST;
#endif //UEYE_CAMERA_LIST_STRUCT

// ----------------------------------------------------------------------------
// the  following defines are the status bits of the dwStatus member of
// the UEYE_CAMERA_INFO structure
#define FIRMWARE_DOWNLOAD_NOT_SUPPORTED                 0x00000001
#define INTERFACE_SPEED_NOT_SUPPORTED                   0x00000002
#define INVALID_SENSOR_DETECTED                         0x00000004
#define AUTHORIZATION_FAILED                            0x00000008
#define DEVSTS_INCLUDED_STARTER_FIRMWARE_INCOMPATIBLE   0x00000010

// the following macro determines the availability of the camera based
// on the status flags
#define IS_CAMERA_AVAILABLE(_s_)     ( (((_s_) & FIRMWARE_DOWNLOAD_NOT_SUPPORTED) == 0) && \
                                       (((_s_) & INTERFACE_SPEED_NOT_SUPPORTED)   == 0) && \
                                       (((_s_) & INVALID_SENSOR_DETECTED)         == 0) && \
                                       (((_s_) & AUTHORIZATION_FAILED)            == 0) )

// ----------------------------------------------------------------------------
// auto feature structs and definitions
// ----------------------------------------------------------------------------
#define AC_SHUTTER                          0x00000001
#define AC_GAIN                             0x00000002
#define AC_WHITEBAL                         0x00000004
#define AC_WB_RED_CHANNEL                   0x00000008
#define AC_WB_GREEN_CHANNEL                 0x00000010
#define AC_WB_BLUE_CHANNEL                  0x00000020
#define AC_FRAMERATE                        0x00000040
#define AC_SENSOR_SHUTTER                   0x00000080
#define AC_SENSOR_GAIN                      0x00000100
#define AC_SENSOR_GAIN_SHUTTER              0x00000200
#define AC_SENSOR_FRAMERATE                 0x00000400
#define AC_SENSOR_WB                        0x00000800
#define AC_SENSOR_AUTO_REFERENCE            0x00001000
#define AC_SENSOR_AUTO_SPEED                0x00002000
#define AC_SENSOR_AUTO_HYSTERESIS           0x00004000
#define AC_SENSOR_AUTO_SKIPFRAMES           0x00008000
#define AC_SENSOR_AUTO_CONTRAST_CORRECTION  0x00010000
#define AC_SENSOR_AUTO_CONTRAST_FDT_AOI     0x00020000
#define AC_SENSOR_AUTO_BACKLIGHT_COMP       0x00040000

#define ACS_ADJUSTING 0x00000001
#define ACS_FINISHED  0x00000002
#define ACS_DISABLED  0x00000004

typedef struct _AUTO_BRIGHT_STATUS
{
    DWORD curValue;             // current average greylevel
    long curError;              // current auto brightness error
    DWORD curController;        // current active brightness controller -> AC_x
    DWORD curCtrlStatus;        // current control status -> ACS_x
} AUTO_BRIGHT_STATUS, *PAUTO_BRIGHT_STATUS;



typedef struct _AUTO_WB_CHANNNEL_STATUS
{
    DWORD curValue;             // current average greylevel
    long curError;              // current auto wb error
    DWORD curCtrlStatus;        // current control status -> ACS_x
} AUTO_WB_CHANNNEL_STATUS, *PAUTO_WB_CHANNNEL_STATUS;

typedef struct _AUTO_WB_STATUS
{
    AUTO_WB_CHANNNEL_STATUS RedChannel;
    AUTO_WB_CHANNNEL_STATUS GreenChannel;
    AUTO_WB_CHANNNEL_STATUS BlueChannel;
    DWORD curController;        // current active wb controller -> AC_x
} AUTO_WB_STATUS, *PAUTO_WB_STATUS;

// auto shutter photometry capabilities
typedef enum E_AUTO_SHUTTER_PHOTOM
{
    AS_PM_NONE                  = 0,
    AS_PM_SENS_CENTER_WEIGHTED  = 0x00000001, // sensor auto shutter: center weighted
    AS_PM_SENS_CENTER_SPOT      = 0x00000002, // sensor auto shutter: center spot
    AS_PM_SENS_PORTRAIT         = 0x00000004, // sensor auto shutter: portrait
    AS_PM_SENS_LANDSCAPE        = 0x00000008  // sensor auto shutter: landscape

}AUTO_SHUTTER_PHOTOM;

// auto gain photometry capabilities
typedef enum E_AUTO_GAIN_PHOTOM
{
    AG_PM_NONE                  = 0,
    AG_PM_SENS_CENTER_WEIGHTED  = 0x00000001, // sensor auto gain: center weighted
    AG_PM_SENS_CENTER_SPOT      = 0x00000002, // sensor auto gain: center spot
    AG_PM_SENS_PORTRAIT         = 0x00000004, // sensor auto gain: portrait
    AG_PM_SENS_LANDSCAPE        = 0x00000008  // sensor auto gain: landscape
}AUTO_GAIN_PHOTOM;

// anti flicker modes
typedef enum E_ANTI_FLICKER_MODE
{
    ANTIFLCK_MODE_OFF             = 0,
    ANTIFLCK_MODE_SENS_AUTO       = 0x00000001,
    ANTIFLCK_MODE_SENS_50_FIXED   = 0x00000002,
    ANTIFLCK_MODE_SENS_60_FIXED   = 0x00000004
}ANTI_FLICKER_MODE;

// whitebalance  modes
typedef enum E_WHITEBALANCE_MODE
{
    WB_MODE_DISABLE                 = 0,
    WB_MODE_AUTO                    = 0x00000001,
    WB_MODE_ALL_PULLIN              = 0x00000002,
    WB_MODE_INCANDESCENT_LAMP       = 0x00000004,
    WB_MODE_FLUORESCENT_DL          = 0x00000008,
    WB_MODE_OUTDOOR_CLEAR_SKY       = 0x00000010,
    WB_MODE_OUTDOOR_CLOUDY          = 0x00000020
}WHITEBALANCE_MODE;

typedef struct _UEYE_AUTO_INFO
{
    DWORD               AutoAbility;                // auto control ability
    AUTO_BRIGHT_STATUS  sBrightCtrlStatus;          // brightness auto control status
    AUTO_WB_STATUS      sWBCtrlStatus;              // white balance auto control status
    DWORD               AShutterPhotomCaps;         // auto shutter photometry capabilities(AUTO_SHUTTER_PHOTOM)
    DWORD               AGainPhotomCaps;            // auto gain photometry capabilities (AUTO_GAIN_PHOTOM)
    DWORD               AAntiFlickerCaps;           // auto anti-flicker capabilities
    DWORD               SensorWBModeCaps;           // white balance mode capabilities
    DWORD               reserved[8];
} UEYE_AUTO_INFO, *PUEYE_AUTO_INFO;

typedef struct _DC_INFO
{
    unsigned int        nSize;      // size of this structure (16  bytes)
    HDC                 hDC;        // handle to a DC
    unsigned int        nCx;        // destination width to use for rendering
    unsigned int        nCy;        // destination height to use for rendering
}DC_INFO, *PDC_INFO;


// ----------------------------------------------------------------------------
// function exports
// ----------------------------------------------------------------------------
#ifdef __LINUX__
    IDSEXP is_WaitEvent             (HIDS hf, INT which, INT nTimeout);
#endif

// ----------------------------------------------------------------------------
// functions only effective on Falcon boards
// ----------------------------------------------------------------------------
  IDSEXP   is_SetVideoInput          (HIDS hf, INT Source);
  IDSEXP   is_SetSaturation          (HIDS hf, INT ChromU, INT ChromV);
  IDSEXP   is_SetHue                 (HIDS hf, INT Hue);
  IDSEXP   is_SetVideoMode           (HIDS hf, INT Mode);
  IDSEXP   is_SetAGC                 (HIDS hf, INT Mode);
  IDSEXP   is_SetSyncLevel           (HIDS hf, INT Level);
  IDSEXP   is_ShowColorBars          (HIDS hf, INT Mode);
  IDSEXP   is_SetScaler              (HIDS hf, float Scalex, float Scaley);
  IDSEXP   is_SetCaptureMode         (HIDS hf, INT Mode);
  IDSEXP   is_SetHorFilter           (HIDS hf, INT Mode);
  IDSEXP   is_SetVertFilter          (HIDS hf, INT Mode);
  IDSEXP   is_ScaleDDOverlay         (HIDS hf, BOOL boScale);
  IDSEXP   is_GetCurrentField        (HIDS hf, int* pField);
  IDSEXP   is_SetVideoSize           (HIDS hf, INT xpos, INT ypos, INT xsize, INT ysize);
  IDSEXP   is_SetKeyOffset           (HIDS hf, INT nOffsetX, INT nOffsetY);
  IDSEXP   is_PrepareStealVideo      (HIDS hf, int Mode, ULONG StealColorMode);
  IDSEXP   is_SetParentHwnd          (HIDS hf, HWND hwnd);
  IDSEXP   is_SetUpdateMode          (HIDS hf, INT mode);
  IDSEXP   is_OvlSurfaceOffWhileMove (HIDS hf, BOOL boMode);
  IDSEXP   is_GetPciSlot             (HIDS hf, INT* pnSlot);
  IDSEXP   is_GetIRQ                 (HIDS hf, INT* pnIRQ);
  IDSEXP   is_SetToggleMode          (HIDS hf, int nInput1, int nInput2, int nInput3, int nInput4);
  IDSEXP   is_SetDecimationMode      (HIDS hf, INT nMode, INT nDecimate);
  IDSEXP   is_SetSync                (HIDS hf, INT nSync);
  // only FALCON duo/quattro
  IDSEXP   is_SetVideoCrossbar       (HIDS hf, INT In, INT Out);
  // watchdog functions
  IDSEXP   is_WatchdogTime           (HIDS hf, long lTime);
  IDSEXP   is_Watchdog               (HIDS hf, long lMode);
  // video out functions
  IDSEXP   is_SetPassthrough         (HIDS hf, INT Source);

// ----------------------------------------------------------------------------
// alias functions for compatibility
// ----------------------------------------------------------------------------
  IDSEXP   is_InitBoard              (HIDS* phf, HWND hWnd);
  IDSEXP   is_ExitBoard              (HIDS hf);
  IDSEXP   is_InitFalcon             (HIDS* phf, HWND hWnd);
  IDSEXP   is_ExitFalcon             (HIDS hf);

  IDSEXP   is_GetBoardType           (HIDS hf);
  IDSEXP   is_GetBoardInfo           (HIDS hf, PBOARDINFO pInfo);
  IDSEXPUL is_BoardStatus            (HIDS hf, INT nInfo, ULONG ulValue);
  IDSEXP   is_GetNumberOfDevices     (void);
  IDSEXP   is_GetNumberOfBoards      (INT* pnNumBoards);

// ----------------------------------------------------------------------------
// common function
// ----------------------------------------------------------------------------
  IDSEXP   is_StopLiveVideo          (HIDS hf, INT Wait);
  IDSEXP   is_FreezeVideo            (HIDS hf, INT Wait);
  IDSEXP   is_CaptureVideo           (HIDS hf, INT Wait);
  IDSEXP   is_IsVideoFinish          (HIDS hf, INT* pValue);
  IDSEXP   is_HasVideoStarted        (HIDS hf, BOOL* pbo);

  IDSEXP   is_SetBrightness          (HIDS hf, INT Bright);
  IDSEXP   is_SetContrast            (HIDS hf, INT Cont);
  IDSEXP   is_SetGamma               (HIDS hf, INT nGamma);

  IDSEXP   is_AllocImageMem          (HIDS hf, INT width, INT height, INT bitspixel, char** ppcImgMem, int* pid);
  IDSEXP   is_SetImageMem            (HIDS hf, char* pcMem, int id);
  IDSEXP   is_FreeImageMem           (HIDS hf, char* pcMem, int id);
  IDSEXP   is_GetImageMem            (HIDS hf, VOID** pMem);
  IDSEXP   is_GetActiveImageMem      (HIDS hf, char** ppcMem, int* pnID);
  IDSEXP   is_InquireImageMem        (HIDS hf, char* pcMem, int nID, int* pnX, int* pnY, int* pnBits, int* pnPitch);
  IDSEXP   is_GetImageMemPitch       (HIDS hf, INT* pPitch);

  IDSEXP   is_SetAllocatedImageMem   (HIDS hf, INT width, INT height, INT bitspixel, char* pcImgMem, int* pid);
  IDSEXP   is_SaveImageMem           (HIDS hf, const IS_CHAR* File, char* pcMem, int nID);
  IDSEXP   is_CopyImageMem           (HIDS hf, char* pcSource, int nID, char* pcDest);
  IDSEXP   is_CopyImageMemLines      (HIDS hf, char* pcSource, int nID, int nLines, char* pcDest);

  IDSEXP   is_AddToSequence          (HIDS hf, char* pcMem, INT nID);
  IDSEXP   is_ClearSequence          (HIDS hf);
  IDSEXP   is_GetActSeqBuf           (HIDS hf, INT* pnNum, char** ppcMem, char** ppcMemLast);
  IDSEXP   is_LockSeqBuf             (HIDS hf, INT nNum, char* pcMem);
  IDSEXP   is_UnlockSeqBuf           (HIDS hf, INT nNum, char* pcMem);

  IDSEXP   is_SetImageSize           (HIDS hf, INT x, INT y);
  IDSEXP   is_SetImagePos            (HIDS hf, INT x, INT y);

  IDSEXP   is_GetError               (HIDS hf, INT* pErr, IS_CHAR** ppcErr);
  IDSEXP   is_SetErrorReport         (HIDS hf, INT Mode);

  IDSEXP   is_ReadEEPROM             (HIDS hf, INT Adr, char* pcString, INT Count);
  IDSEXP   is_WriteEEPROM            (HIDS hf, INT Adr, char* pcString, INT Count);
  IDSEXP   is_SaveImage              (HIDS hf, const IS_CHAR* File);

  IDSEXP   is_SetColorMode           (HIDS hf, INT Mode);
  IDSEXP   is_GetColorDepth          (HIDS hf, INT* pnCol, INT* pnColMode);
  // bitmap display function
  IDSEXP   is_RenderBitmap           (HIDS hf, INT nMemID, HWND hwnd, INT nMode);

  IDSEXP   is_SetDisplayMode         (HIDS hf, INT Mode);
  IDSEXP   is_GetDC                  (HIDS hf, HDC* phDC);
  IDSEXP   is_ReleaseDC              (HIDS hf, HDC hDC);
  IDSEXP   is_UpdateDisplay          (HIDS hf);
  IDSEXP   is_SetDisplaySize         (HIDS hf, INT x, INT y);
  IDSEXP   is_SetDisplayPos          (HIDS hf, INT x, INT y);

  IDSEXP   is_LockDDOverlayMem       (HIDS hf, VOID** ppMem, INT* pPitch);
  IDSEXP   is_UnlockDDOverlayMem     (HIDS hf);
  IDSEXP   is_LockDDMem              (HIDS hf, VOID** ppMem, INT* pPitch);
  IDSEXP   is_UnlockDDMem            (HIDS hf);
  IDSEXP   is_GetDDOvlSurface        (HIDS hf, void** ppDDSurf);
  IDSEXP   is_SetKeyColor            (HIDS hf, INT r, INT g, INT b);
  IDSEXP   is_StealVideo             (HIDS hf, int Wait);
  IDSEXP   is_SetHwnd                (HIDS hf, HWND hwnd);


  IDSEXP   is_SetDDUpdateTime        (HIDS hf, INT ms);
  IDSEXP   is_EnableDDOverlay        (HIDS hf);
  IDSEXP   is_DisableDDOverlay       (HIDS hf);
  IDSEXP   is_ShowDDOverlay          (HIDS hf);
  IDSEXP   is_HideDDOverlay          (HIDS hf);


  IDSEXP   is_GetVsyncCount          (HIDS hf, long* pIntr, long* pActIntr);
  IDSEXP   is_GetOsVersion           (void);
  // version information
  IDSEXP   is_GetDLLVersion          (void);

  IDSEXP   is_InitEvent              (HIDS hf, HANDLE hEv, INT which);
  IDSEXP   is_ExitEvent              (HIDS hf, INT which);
  IDSEXP   is_EnableEvent            (HIDS hf, INT which);
  IDSEXP   is_DisableEvent           (HIDS hf, INT which);

  IDSEXP   is_SetIO                  (HIDS hf, INT nIO);
  IDSEXP   is_SetFlashStrobe         (HIDS hf, INT nMode, INT nLine);
  IDSEXP   is_SetExternalTrigger     (HIDS hf, INT nTriggerMode);
  IDSEXP   is_SetTriggerCounter      (HIDS hf, INT nValue);
  IDSEXP   is_SetRopEffect           (HIDS hf, INT effect, INT param, INT reserved);

// ----------------------------------------------------------------------------
// new functions only valid for uEye camera family
// ----------------------------------------------------------------------------
  // Camera functions
  IDSEXP is_InitCamera                  (HIDS* phf, HWND hWnd);
  IDSEXP is_ExitCamera                  (HIDS hf);
  IDSEXP is_GetCameraInfo               (HIDS hf, PCAMINFO pInfo);
  IDSEXPUL is_CameraStatus              (HIDS hf, INT nInfo, ULONG ulValue);
  IDSEXP is_GetCameraType               (HIDS hf);
  IDSEXP is_GetNumberOfCameras          (INT* pnNumCams);

  // PixelClock
  IDSEXP is_GetPixelClockRange          (HIDS hf, INT *pnMin, INT *pnMax);
  IDSEXP is_SetPixelClock               (HIDS hf, INT Clock);
  IDSEXP is_GetUsedBandwidth            (HIDS hf);
  // Set/Get Frame rate
  IDSEXP is_GetFrameTimeRange           (HIDS hf, double *min, double *max, double *intervall);
  IDSEXP is_SetFrameRate                (HIDS hf, double FPS, double* newFPS);
  // Set/Get Exposure
  IDSEXP is_GetExposureRange            (HIDS hf, double *min, double *max, double *intervall);
  IDSEXP is_SetExposureTime             (HIDS hf, double EXP, double* newEXP);
  // get frames per second
  IDSEXP is_GetFramesPerSecond          (HIDS hf, double *dblFPS);

  // is_SetIOMask ( only uEye USB )
  IDSEXP is_SetIOMask                   (HIDS hf, INT nMask);

  // Get Sensor info
  IDSEXP is_GetSensorInfo               (HIDS hf, PSENSORINFO pInfo);
  // Get RevisionInfo
  IDSEXP is_GetRevisionInfo             (HIDS hf, PREVISIONINFO prevInfo);

  // enable/disable AutoExit after device remove
  IDSEXP is_EnableAutoExit              (HIDS hf, INT nMode);
  // Message
  IDSEXP is_EnableMessage               (HIDS hf, INT which, HWND hWnd);

  // hardware gain settings
  IDSEXP is_SetHardwareGain             (HIDS hf, INT nMaster, INT nRed, INT nGreen, INT nBlue);

  // set render mode
  IDSEXP is_SetRenderMode               (HIDS hf, INT Mode);

  // enable/disable WhiteBalance
  IDSEXP is_SetWhiteBalance             (HIDS hf, INT nMode);
  IDSEXP is_SetWhiteBalanceMultipliers  (HIDS hf, double dblRed, double dblGreen, double dblBlue);
  IDSEXP is_GetWhiteBalanceMultipliers  (HIDS hf, double *pdblRed, double *pdblGreen, double *pdblBlue);

  // Edge enhancement
  IDSEXP is_SetEdgeEnhancement          (HIDS hf, INT nEnable);

  // Sensor features
  IDSEXP is_SetColorCorrection          (HIDS hf, INT nEnable, double *factors);
  IDSEXP is_SetBlCompensation           (HIDS hf, INT nEnable, INT offset, INT reserved);

  // Hotpixel
  IDSEXP is_SetBadPixelCorrection       (HIDS hf, INT nEnable, INT threshold);
  IDSEXP is_LoadBadPixelCorrectionTable (HIDS hf, const IS_CHAR *File);
  IDSEXP is_SaveBadPixelCorrectionTable (HIDS hf, const IS_CHAR *File);
  IDSEXP is_SetBadPixelCorrectionTable  (HIDS hf, INT nMode, WORD *pList);

  // Memoryboard
  IDSEXP is_SetMemoryMode               (HIDS hf, INT nCount, INT nDelay);
  IDSEXP is_TransferImage               (HIDS hf, INT nMemID, INT seqID, INT imageNr, INT reserved);
  IDSEXP is_TransferMemorySequence      (HIDS hf, INT seqID, INT StartNr, INT nCount, INT nSeqPos);
  IDSEXP is_MemoryFreezeVideo           (HIDS hf, INT nMemID, INT Wait);
  IDSEXP is_GetLastMemorySequence       (HIDS hf, INT *pID);
  IDSEXP is_GetNumberOfMemoryImages     (HIDS hf, INT nID, INT *pnCount);
  IDSEXP is_GetMemorySequenceWindow     (HIDS hf, INT nID, INT *left, INT *top, INT *right, INT *bottom);
  IDSEXP is_IsMemoryBoardConnected      (HIDS hf, BOOL *pConnected);
  IDSEXP is_ResetMemory                 (HIDS hf, INT nReserved);

  IDSEXP is_SetSubSampling              (HIDS hf, INT mode);
  IDSEXP is_ForceTrigger                (HIDS hf);

  // new with driver version 1.12.0006
  IDSEXP is_GetBusSpeed                 (HIDS hf);

  // new with driver version 1.12.0015
  IDSEXP is_SetBinning                  (HIDS hf, INT mode);

  // new with driver version 1.12.0017
  IDSEXP is_ResetToDefault              (HIDS hf);
  IDSEXP is_LoadParameters              (HIDS hf, const IS_CHAR* pFilename);
  IDSEXP is_SaveParameters              (HIDS hf, const IS_CHAR* pFilename);

  // new with driver version 1.14.0001
  IDSEXP is_GetGlobalFlashDelays        (HIDS hf, ULONG *pulDelay, ULONG *pulDuration);
  IDSEXP is_SetFlashDelay               (HIDS hf, ULONG ulDelay, ULONG ulDuration);
  // new with driver version 1.14.0002
  IDSEXP is_LoadImage                   (HIDS hf, const IS_CHAR* File);

  // new with driver version 1.14.0008
  IDSEXP is_SetImageAOI                 (HIDS hf, INT xPos, INT yPos, INT width, INT height);
  IDSEXP is_SetCameraID                 (HIDS hf, INT nID);
  IDSEXP is_SetBayerConversion          (HIDS hf, INT nMode);
  IDSEXP is_SetTestImage                (HIDS hf, INT nMode);
  // new with driver version 1.14.0009
  IDSEXP is_SetHardwareGamma            (HIDS hf, INT nMode);

  // new with driver version 2.00.0001
  IDSEXP is_GetCameraList               (PUEYE_CAMERA_LIST pucl);

  // new with driver version 2.00.0011
  IDSEXP is_SetAOI                      (HIDS hf, INT cmd, INT *pXPos, INT *pYPos, INT *pWidth, INT *pHeight);
  IDSEXP is_SetAutoParameter            (HIDS hf, INT param, double *pval1, double *pval2);
  IDSEXP is_GetAutoInfo                 (HIDS hf, UEYE_AUTO_INFO *pInfo);
  
  // new with driver version 2.20.0001
  IDSEXP is_ConvertImage                (HIDS hf, char* pcSource, int nIDSource, char** pcDest, INT *nIDDest, INT *reserved);
  IDSEXP is_SetConvertParam             (HIDS hf, BOOL ColorCorrection, INT BayerConversionMode, INT ColorMode, INT Gamma, double* WhiteBalanceMultipliers);
  
  IDSEXP is_SaveImageEx                 (HIDS hf, const IS_CHAR* File, INT fileFormat, INT Param);
  IDSEXP is_SaveImageMemEx              (HIDS hf, const IS_CHAR* File, char* pcMem, INT nID, INT FileFormat, INT Param);
  IDSEXP is_LoadImageMem                (HIDS hf, const IS_CHAR* File, char** ppcImgMem, INT* pid);
  
  IDSEXP is_GetImageHistogram           (HIDS hf, int nID, INT ColorMode, DWORD* pHistoMem);
  IDSEXP is_SetTriggerDelay             (HIDS hf, INT nTriggerDelay);

  // new with driver version 2.21.0000
  IDSEXP is_SetGainBoost                (HIDS hf, INT mode);
  IDSEXP is_SetLED                      (HIDS hf, INT nValue);

  IDSEXP is_SetGlobalShutter            (HIDS hf, INT mode);
  IDSEXP is_SetExtendedRegister         (HIDS hf, INT index,WORD value);
  IDSEXP is_GetExtendedRegister         (HIDS hf, INT index, WORD *pwValue);

  // new with driver version 2.22.0002
  IDSEXP is_SetHWGainFactor             (HIDS hf, INT nMode, INT nFactor);

  // camera renumeration
  IDSEXP is_Renumerate                  (HIDS hf, INT nMode);

  // Read / Write I2C
  IDSEXP is_WriteI2C                    (HIDS hf, INT nDeviceAddr, INT nRegisterAddr, BYTE* pbData, INT nLen);
  IDSEXP is_ReadI2C                     (HIDS hf, INT nDeviceAddr, INT nRegisterAddr, BYTE* pbData, INT nLen);


  // new with driver version 3.10.0000
  typedef struct _KNEEPOINT
  {
      double x;
      double y;
  } KNEEPOINT, *PKNEEPOINT;


  typedef struct _KNEEPOINTARRAY
  {
      INT NumberOfUsedKneepoints;
      KNEEPOINT Kneepoint[10];
  } KNEEPOINTARRAY, *PKNEEPOINTARRAY;


  typedef struct _KNEEPOINTINFO
  {
      INT NumberOfSupportedKneepoints;
      INT NumberOfUsedKneepoints;
      double MinValueX;
      double MaxValueX;
      double MinValueY;
      double MaxValueY;
      KNEEPOINT DefaultKneepoint[10];
      INT Reserved[10];
  } KNEEPOINTINFO, *PKNEEPOINTINFO;


  // HDR functions
  IDSEXP is_GetHdrMode                  (HIDS hf, INT *Mode);
  IDSEXP is_EnableHdr                   (HIDS hf, INT Enable);
  IDSEXP is_SetHdrKneepoints            (HIDS hf, KNEEPOINTARRAY *KneepointArray, INT KneepointArraySize);
  IDSEXP is_GetHdrKneepoints            (HIDS hf, KNEEPOINTARRAY *KneepointArray, INT KneepointArraySize);
  IDSEXP is_GetHdrKneepointInfo         (HIDS hf, KNEEPOINTINFO *KneepointInfo, INT KneepointInfoSize);

  IDSEXP is_SetOptimalCameraTiming      (HIDS hf, INT Mode, INT Timeout, INT *pMaxPxlClk, double *pMaxFrameRate);

  IDSEXP is_GetSupportedTestImages      (HIDS hf, INT *SupportedTestImages);
  IDSEXP is_GetTestImageValueRange      (HIDS hf, INT TestImage, INT *TestImageValueMin, INT *TestImageValueMax);
  IDSEXP is_SetSensorTestImage          (HIDS hf, INT Param1, INT Param2);

  IDSEXP is_SetCameraLUT                (HIDS hf, UINT Mode, UINT NumberOfEntries, double *pRed_Grey, double *pGreen, double *pBlue);
  IDSEXP is_GetCameraLUT                (HIDS hf, UINT Mode, UINT NumberOfEntries, double *pRed_Grey, double *pGreen, double *pBlue);

  IDSEXP is_GetColorConverter           (HIDS hf, INT ColorMode, INT *pCurrentConvertMode, INT *pDefaultConvertMode, INT *pSupportedConvertModes);
  IDSEXP is_SetColorConverter           (HIDS hf, INT ColorMode, INT ConvertMode);

  IDSEXP is_GetCaptureErrorInfo         (HIDS hf, UEYE_CAPTURE_ERROR_INFO *pCaptureErrorInfo, UINT SizeCaptureErrorInfo);
  IDSEXP is_ResetCaptureErrorInfo       (HIDS hf );

  IDSEXP is_WaitForNextImage            (HIDS hf, UINT timeout, char **ppcMem, INT *imageID);
  IDSEXP is_InitImageQueue              (HIDS hf, INT nMode);
  IDSEXP is_ExitImageQueue              (HIDS hf);

  IDSEXP is_SetTimeout                  (HIDS hf, UINT nMode, UINT Timeout);
  IDSEXP is_GetTimeout                  (HIDS hf, UINT nMode, UINT *pTimeout);


  typedef enum  eUEYE_GET_ESTIMATED_TIME_MODE
  {
      IS_SE_STARTER_FW_UPLOAD =   0x00000001, /*!< get estimated duration of GigE SE starter firmware upload in milliseconds */
      IS_CP_STARTER_FW_UPLOAD =   0x00000002, /*!< get estimated duration of GigE CP starter firmware upload in milliseconds */
      IS_STARTER_FW_UPLOAD    =   0x00000004  /*!< get estimated duration of starter firmware upload in milliseconds using hf to */ 
  } UEYE_GET_ESTIMATED_TIME_MODE;    
  
  
  IDSEXP is_GetDuration                 (HIDS hf, UINT nMode, INT* pnTime);


  // new with driver version 3.40.0000
  typedef struct _SENSORSCALERINFO
  {
      INT       nCurrMode;
      INT       nNumberOfSteps;
      double    dblFactorIncrement;
      double    dblMinFactor;
      double    dblMaxFactor;
      double    dblCurrFactor;
      INT       nSupportedModes;
      BYTE      bReserved[84];
  } SENSORSCALERINFO;


  IDSEXP is_GetSensorScalerInfo (HIDS hf, SENSORSCALERINFO *pSensorScalerInfo, INT nSensorScalerInfoSize);
  IDSEXP is_SetSensorScaler      (HIDS hf, UINT nMode, double dblFactor); 

  typedef struct _UEYETIME
  {
      WORD      wYear;
      WORD      wMonth;
      WORD      wDay;
      WORD      wHour;
      WORD      wMinute;
      WORD      wSecond;
      WORD      wMilliseconds;
      BYTE      byReserved[10];
  } UEYETIME;


  typedef struct _UEYEIMAGEINFO
  {
      DWORD                 dwFlags;
      BYTE                  byReserved1[4];
      UINT64                u64TimestampDevice;
      UEYETIME              TimestampSystem;
      DWORD                 dwIoStatus;
      BYTE                  byReserved2[4];
      UINT64                u64FrameNumber;
      DWORD                 dwImageBuffers;
      DWORD                 dwImageBuffersInUse;
      DWORD                 dwReserved3;
      DWORD                 dwImageHeight;
      DWORD                 dwImageWidth;
  } UEYEIMAGEINFO;


    IDSEXP is_GetImageInfo (HIDS hf, INT nImageBufferID, UEYEIMAGEINFO *pImageInfo, INT nImageInfoSize);


    // New functions and defines for 3.52 (uEye XS)
    IDSEXP is_ImageFormat (HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);


    typedef enum E_IMAGE_FORMAT_CMD
    {
       IMGFRMT_CMD_GET_NUM_ENTRIES              = 1,  /* Get the number of supported image formats.
                                                         pParam hast to be a Pointer to IS_U32. If  -1 is reported, the device
                                                         supports continuous AOI settings (maybe with fixed increments)         */
       IMGFRMT_CMD_GET_LIST                     = 2,  /* Get a array of IMAGE_FORMAT_ELEMENTs.                                  */
       IMGFRMT_CMD_SET_FORMAT                   = 3,  /* Select a image format                                                  */
       IMGFRMT_CMD_GET_ARBITRARY_AOI_SUPPORTED  = 4,  /* Does the device supports the setting of an arbitrary AOI.              */
       IMGFRMT_CMD_GET_FORMAT_INFO              = 5   /* Get IMAGE_FORMAT_INFO for a given formatID                             */

    } IMAGE_FORMAT_CMD;


    typedef enum E_CAPTUREMODE
    {

        // no trigger
        CAPTMODE_FREERUN                    = 0x00000001,
        CAPTMODE_SINGLE                     = 0x00000002,

        // software trigger modes
        CAPTMODE_TRIGGER_SOFT_SINGLE        = 0x00000010,
        CAPTMODE_TRIGGER_SOFT_CONTINUOUS    = 0x00000020,

        // hardware trigger modes
        CAPTMODE_TRIGGER_HW_SINGLE          = 0x00000100,
        CAPTMODE_TRIGGER_HW_CONTINUOUS      = 0x00000200

    } CAPTUREMODE;


    typedef struct S_IMAGE_FORMAT_INFO
    {
        INT  nFormatID;                     /* Image format ID.                                                         */
        UINT nWidth;                        /* Width.                                                                   */
        UINT nHeight;                       /* Height.                                                                  */
        INT nX0;                            /* Start position x.                                                        */
        INT nY0;                            /* Start position Y.                                                        */
        UINT nSupportedCaptureModes;        /* Flag field with supported capture modes for this resolution (Bitmask of
                                               of CAPTUREMODE enumeration).                                             */
        UINT nBinningMode;                  /* Binning mode.                                                            */
        UINT nSubsamplingMode;              /* Subsampling mode.                                                        */
        IS_CHAR strFormatName[64];          /* Format name.                                                             */
        double dSensorScalerFactor;         /* Sensor scaler factor.                                                    */
        UINT nReserved[22];
    } IMAGE_FORMAT_INFO;


    typedef struct S_IMAGE_FORMAT_LIST
    {
        UINT nSizeOfListEntry;              /* Size of one list entry in byte. */
        UINT nNumListElements;              /* Number of list entries.         */
        UINT nReserved[4];                  /* Reserved for future use.        */
        IMAGE_FORMAT_INFO FormatInfo[1];    /* First format entry.             */
    } IMAGE_FORMAT_LIST;


IDSEXP is_FaceDetection (HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);


    typedef enum E_FDT_CAPABILITY_FLAGS
    {
        FDT_CAP_INVALID             = 0,
        FDT_CAP_SUPPORTED           = 0x00000001, /* Face detection supported.                                      */
        FDT_CAP_SEARCH_ANGLE        = 0x00000002, /* Search angle.                                                  */
        FDT_CAP_SEARCH_AOI          = 0x00000004, /* Search AOI.                                                    */
        FDT_CAP_INFO_POSX           = 0x00000010, /* Query horizontal position (center) of detected face.           */
        FDT_CAP_INFO_POSY           = 0x00000020, /* Query vertical position(center) of detected face.              */
        FDT_CAP_INFO_WIDTH          = 0x00000040, /* Query width of detected face.                                  */
        FDT_CAP_INFO_HEIGHT         = 0x00000080, /* Query height of detected face.                                 */
        FDT_CAP_INFO_ANGLE          = 0x00000100, /* Query angle of detected face.                                  */
        FDT_CAP_INFO_POSTURE        = 0x00000200, /* Query posture of detected face.                                */
        FDT_CAP_INFO_FACENUMBER     = 0x00000400, /* Query number of detected faces.                                */
        FDT_CAP_INFO_OVL            = 0x00000800, /* Overlay: Mark the detected face in the image.                  */
        FDT_CAP_INFO_NUM_OVL        = 0x00001000, /* Overlay: Limit the maximum number of overlays in one image.    */
        FDT_CAP_INFO_OVL_LINEWIDTH  = 0x00002000  /* Overlay line width.                                            */
    } FDT_CAPABILITY_FLAGS;


    typedef struct S_FDT_INFO_EL
    {
        INT nFacePosX;              /* Start X position.                                                                */
        INT nFacePosY;              /* Start Y position.                                                                */
        INT nFaceWidth;             /* Face width.                                                                      */
        INT nFaceHeight;            /* Face height.                                                                     */
        INT nAngle;                 /* Face Angle (0...360° clockwise, 0° at twelve o'clock position. -1: undefined ).  */
        UINT nPosture;              /* Face posture.                                                                    */
        UEYETIME TimestampSystem;   /* System time stamp (device query time) .                                          */
        UINT64 nReserved;           /* Reserved for future use.                                                         */
        UINT nReserved2[4];         /* Reserved for future use.                                                         */

    } FDT_INFO_EL;


    typedef struct S_FDT_INFO_LIST
    {
        UINT nSizeOfListEntry;      /* Size of one list entry in byte(in).  */
        UINT nNumDetectedFaces;     /* Number of detected faces(out).       */
        UINT nNumListElements;      /* Number of list elements(in).         */
        UINT nReserved[4];          /* reserved for future use(out).        */
        FDT_INFO_EL FaceEntry[1];   /* First face entry.                    */
    } FDT_INFO_LIST;


    typedef enum E_FDT_CMD
    {
        FDT_CMD_GET_CAPABILITIES            = 0,    /* Get the capabilities for face detection.                     */
        FDT_CMD_SET_DISABLE                 = 1,    /* Disable face detection.                                      */
        FDT_CMD_SET_ENABLE                  = 2,    /* Enable face detection.                                       */
        FDT_CMD_SET_SEARCH_ANGLE            = 3,    /* Set the search angle.                                        */
        FDT_CMD_GET_SEARCH_ANGLE            = 4,    /* Get the search angle parameter.                              */
        FDT_CMD_SET_SEARCH_ANGLE_ENABLE     = 5,    /* Enable search angle.                                         */
        FDT_CMD_SET_SEARCH_ANGLE_DISABLE    = 6,    /* Enable search angle.                                         */
        FDT_CMD_GET_SEARCH_ANGLE_ENABLE     = 7,    /* Get the current setting of search angle enable.              */
        FDT_CMD_SET_SEARCH_AOI              = 8,    /* Set the search AOI.                                          */
        FDT_CMD_GET_SEARCH_AOI              = 9,    /* Get the search AOI.                                          */
        FDT_CMD_GET_FACE_LIST               = 10,   /* Get a list with detected faces.                              */
        FDT_CMD_GET_NUMBER_FACES            = 11,   /* Get the number of detected faces.                            */
        FDT_CMD_SET_SUSPEND                 = 12,   /* Keep the face detection result of that moment.               */
        FDT_CMD_SET_RESUME                  = 13,   /* Continue with the face detection.                            */
        FDT_CMD_GET_MAX_NUM_FACES           = 14,   /* Get the maximum number of faces that can be detected once.   */
        FDT_CMD_SET_INFO_MAX_NUM_OVL        = 15,   /* Set the maximum number of overlays displayed.                */
        FDT_CMD_GET_INFO_MAX_NUM_OVL        = 16,   /* Get the setting 'maximum number of overlays displayed'.      */
        FDT_CMD_SET_INFO_OVL_LINE_WIDTH     = 17,   /* Set the overlay line width.                                  */
        FDT_CMD_GET_INFO_OVL_LINE_WIDTH     = 18,   /* Get the overlay line width.                                  */
        FDT_CMD_GET_ENABLE                  = 19,   /* Face detection enabled?.                                     */
        FDT_CMD_GET_SUSPEND                 = 20,   /* Face detection suspended?.                                   */
        FDT_CMD_GET_HORIZONTAL_RESOLUTION   = 21,   /* Horizontal resolution of face detection.                     */
        FDT_CMD_GET_VERTICAL_RESOLUTION     = 22    /* Vertical resolution of face detection.                       */

    } FDT_CMD;


    IDSEXP is_Focus (HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);


    typedef enum E_FOCUS_CAPABILITY_FLAGS
    {
        FOC_CAP_INVALID             = 0,
        FOC_CAP_AUTOFOCUS_SUPPORTED = 0x00000001,   /* Auto focus supported.                                    */
        FOC_CAP_MANUAL_SUPPORTED    = 0x00000002,   /* Manual focus supported.                                  */
        FOC_CAP_GET_DISTANCE        = 0x00000004,   /* Support for query the distance of the focused object.    */
        FOC_CAP_SET_AUTOFOCUS_RANGE = 0x00000008,   /* Support for setting focus ranges.                        */
        FOC_CAP_AUTOFOCUS_FDT_AOI   = 0x00000010    /* Use of face detection AOI for autofocus supported.       */
    } FOCUS_CAPABILITY_FLAGS;


    typedef enum E_FOCUS_RANGE
    {
        FOC_RANGE_NORMAL            = 0x00000001,   /* Normal focus range(without Macro).   */
        FOC_RANGE_ALLRANGE          = 0x00000002,   /* Allrange (macro to Infinity).        */
        FOC_RANGE_MACRO             = 0x00000004    /* Macro (only macro).                  */
    } FOCUS_RANGE;


    typedef enum E_FOCUS_CMD
    {
        FOC_CMD_GET_CAPABILITIES        = 0,    /* Get focus capabilities.                      */
        FOC_CMD_SET_DISABLE_AUTOFOCUS   = 1,    /* Disable autofocus.                           */
        FOC_CMD_SET_ENABLE_AUTOFOCUS    = 2,    /* Enable autofocus.                            */
        FOC_CMD_GET_AUTOFOCUS_ENABLE    = 3,    /* Autofocus enabled?.                          */
        FOC_CMD_SET_AUTOFOCUS_RANGE     = 4,    /* Preset autofocus range.                      */
        FOC_CMD_GET_AUTOFOCUS_RANGE     = 5,    /* Get preset of autofocus range.               */
        FOC_CMD_GET_DISTANCE            = 6,    /* Get distance to focused object.              */
        FOC_CMD_SET_MANUAL_FOCUS        = 7,    /* Set manual focus.                            */
        FOC_CMD_GET_MANUAL_FOCUS        = 8,    /* Get the value for manual focus.              */
        FOC_CMD_GET_MANUAL_FOCUS_MIN    = 9,    /* Get the minimum manual focus value.          */
        FOC_CMD_GET_MANUAL_FOCUS_MAX    = 10,   /* Get the maximum manual focus value.          */
        FOC_CMD_GET_MANUAL_FOCUS_INC    = 11,   /* Get the increment of the manual focus value. */
        FOC_CMD_SET_ENABLE_AF_FDT_AOI   = 12,   /* Enable face detection AOI use for autofocus. */
        FOC_CMD_SET_DISABLE_AF_FDT_AOI  = 13,   /* Disable face detection AOI use for autofocus */
        FOC_CMD_GET_AF_FDT_AOI_ENABLE   = 14    /* Use autofocus FDT AOI?                       */
    } FOCUS_CMD;


    IDSEXP is_ImageStabilization(HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);

    // image stabilization capability flags
    typedef enum E_IMGSTAB_CAPABILITY_FLAGS
    {
        IMGSTAB_CAP_INVALID                         = 0,
        IMGSTAB_CAP_IMAGE_STABILIZATION_SUPPORTED   = 0x00000001    /* Image stabilization supported. */
    } IMGSTAB_CAPABILITY_FLAGS;


    typedef enum E_IMGSTAB_CMD
    {
        IMGSTAB_CMD_GET_CAPABILITIES        = 0,    /* Get the capabilities for image stabilization.    */
        IMGSTAB_CMD_SET_DISABLE             = 1,    /* Disable image stabilization.                     */
        IMGSTAB_CMD_SET_ENABLE              = 2,    /* Enable image stabilization.                      */
        IMGSTAB_CMD_GET_ENABLE              = 3     /* Image stabilization enabled?                     */

    } IMGSTAB_CMD;

    // New functions and defines for 3.61 (uEye XS)
    IDSEXP is_ScenePreset(HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);

    typedef enum E_SCENE_CMD
     {
        SCENE_CMD_GET_SUPPORTED_PRESETS = 1,/* Get the supported scene presets      */
        SCENE_CMD_SET_PRESET            = 2,/* Set the scene preset                 */
        SCENE_CMD_GET_PRESET            = 3,/* Get the current sensor scene preset  */
        SCENE_CMD_GET_DEFAULT_PRESET    = 4 /* Get the default sensor scene preset  */
    } SCENE_CMD;



    typedef enum E_SCENE_PRESET
    {
      SCENE_INVALID             = 0,
      SCENE_SENSOR_AUTOMATIC    = 0x00000001,
      SCENE_SENSOR_PORTRAIT     = 0x00000002,
      SCENE_SENSOR_SUNNY        = 0x00000004,
      SCENE_SENSOR_ENTERTAINMENT= 0x00000008,
      SCENE_SENSOR_NIGHT        = 0x00000010,
      SCENE_SENSOR_SPORTS       = 0x00000040,
      SCENE_SENSOR_LANDSCAPE    = 0x00000080
     } SCENE_PRESET;


IDSEXP  is_Zoom (HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);

typedef enum E_ZOOM_CMD
{
    ZOOM_CMD_GET_CAPABILITIES               = 0,/* Get the zoom capabilities. */
    ZOOM_CMD_DIGITAL_GET_NUM_LIST_ENTRIES   = 1,/* Get the number of list entries. */
    ZOOM_CMD_DIGITAL_GET_LIST               = 2,/* Get a list of supported zoom factors. */
    ZOOM_CMD_DIGITAL_SET_VALUE              = 3,/* Set the digital zoom factor zoom factors. */
    ZOOM_CMD_DIGITAL_GET_VALUE              = 4 /* Get a current digital zoom factor. */

} ZOOM_CMD;


typedef enum E_ZOOM_CAPABILITY_FLAGS
{
    ZOOM_CAP_INVALID        = 0,
    ZOOM_CAP_DIGITAL_ZOOM   = 0x00001
} ZOOM_CAPABILITY_FLAGS;


IDSEXP is_Sharpness (HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);


typedef enum E_SHARPNESS_CMD
{
    SHARPNESS_CMD_GET_CAPABILITIES          = 0, /* Get the sharpness capabilities */
    SHARPNESS_CMD_GET_VALUE                 = 1, /* Get the current sharpness value */
    SHARPNESS_CMD_GET_MIN_VALUE             = 2, /* Get the minimum sharpness value */
    SHARPNESS_CMD_GET_MAX_VALUE             = 3, /* Get the maximum sharpness value */
    SHARPNESS_CMD_GET_INCREMENT             = 4, /* Get the sharpness increment */
    SHARPNESS_CMD_GET_DEFAULT_VALUE         = 5, /* Get the default sharpness value */
    SHARPNESS_CMD_SET_VALUE                 = 6  /* Set the sharpness value */

} SHARPNESS_CMD;


typedef enum E_SHARPNESS_CAPABILITY_FLAGS
{
    SHARPNESS_CAP_INVALID                   = 0x0000,
    SHARPNESS_CAP_SHARPNESS_SUPPORTED       = 0x0001

} SHARPNESS_CAPABILITY_FLAGS;


IDSEXP is_Saturation (HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);


typedef enum E_SATURATION_CMD
{
    SATURATION_CMD_GET_CAPABILITIES         = 0, /* Get the saturation capabilities */
    SATURATION_CMD_GET_VALUE                = 1, /* Get the current saturation value */
    SATURATION_CMD_GET_MIN_VALUE            = 2, /* Get the minimum saturation value */
    SATURATION_CMD_GET_MAX_VALUE            = 3, /* Get the maximum saturation value */
    SATURATION_CMD_GET_INCREMENT            = 4, /* Get the saturation increment */
    SATURATION_CMD_GET_DEFAULT_VALUE        = 5, /* Get the default saturation value */
    SATURATION_CMD_SET_VALUE                = 6  /* Set the saturation value */

} SATURATION_CMD;


typedef enum E_SATURATION_CAPABILITY_FLAGS
{
    SATURATION_CAP_INVALID                  = 0x0000,
    SATURATION_CAP_SATURATION_SUPPORTED     = 0x0001

} SATURATION_CAPABILITY_FLAGS;


// Trigger debounce modes
typedef enum E_TRIGGER_DEBOUNCE_MODE
{
    TRIGGER_DEBOUNCE_MODE_NONE              = 0x0000,
    TRIGGER_DEBOUNCE_MODE_FALLING_EDGE      = 0x0001,   
    TRIGGER_DEBOUNCE_MODE_RISING_EDGE       = 0x0002,
    TRIGGER_DEBOUNCE_MODE_BOTH_EDGES        = 0x0004,
    TRIGGER_DEBOUNCE_MODE_AUTOMATIC         = 0x0008

} TRIGGER_DEBOUNCE_MODE;


// Trigger debounce commands
typedef enum E_TRIGGER_DEBOUNCE_CMD
{
    TRIGGER_DEBOUNCE_CMD_SET_MODE                   = 0, /* Set a new trigger debounce mode */
    TRIGGER_DEBOUNCE_CMD_SET_DELAY_TIME             = 1, /* Set a new trigger debounce delay time */
    TRIGGER_DEBOUNCE_CMD_GET_SUPPORTED_MODES        = 2, /* Get the supported modes */
    TRIGGER_DEBOUNCE_CMD_GET_MODE                   = 3, /* Get the current trigger debounce mode */
    TRIGGER_DEBOUNCE_CMD_GET_DELAY_TIME             = 4, /* Get the current trigger debounce delay time */
    TRIGGER_DEBOUNCE_CMD_GET_DELAY_TIME_MIN         = 5, /* Get the minimum value for the trigger debounce delay time */
    TRIGGER_DEBOUNCE_CMD_GET_DELAY_TIME_MAX         = 6, /* Get the maximum value for the trigger debounce delay time */
    TRIGGER_DEBOUNCE_CMD_GET_DELAY_TIME_INC         = 7, /* Get the increment of the trigger debounce delay time */
    TRIGGER_DEBOUNCE_CMD_GET_MODE_DEFAULT           = 8, /* Get the default trigger debounce mode */
    TRIGGER_DEBOUNCE_CMD_GET_DELAY_TIME_DEFAULT     = 9  /* Get the default trigger debounce delay time */

} TRIGGER_DEBOUNCE_CMD;


IDSEXP is_TriggerDebounce(HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);


typedef enum E_RGB_COLOR_MODELS
{
    RGB_COLOR_MODEL_SRGB_D50        = 0x0001,
    RGB_COLOR_MODEL_SRGB_D65        = 0x0002,
    RGB_COLOR_MODEL_CIE_RGB_E       = 0x0004,
    RGB_COLOR_MODEL_ECI_RGB_D50     = 0x0008,
    RGB_COLOR_MODEL_ADOBE_RGB_D65   = 0x0010,

} RGB_COLOR_MODELS;


typedef enum E_COLOR_TEMPERATURE_CMD
{
    COLOR_TEMPERATURE_CMD_SET_TEMPERATURE                   = 0, /* Set a new color temperature */
    COLOR_TEMPERATURE_CMD_SET_RGB_COLOR_MODEL               = 1, /* Set a new RGB color model */
    COLOR_TEMPERATURE_CMD_GET_SUPPORTED_RGB_COLOR_MODELS    = 2, /* Get the supported RGB color models */
    COLOR_TEMPERATURE_CMD_GET_TEMPERATURE                   = 3, /* Get the current color temperature */
    COLOR_TEMPERATURE_CMD_GET_RGB_COLOR_MODEL               = 4, /* Get the current RGB color model */
    COLOR_TEMPERATURE_CMD_GET_TEMPERATURE_MIN               = 5, /* Get the minimum value for the color temperature */
    COLOR_TEMPERATURE_CMD_GET_TEMPERATURE_MAX               = 6, /* Get the maximum value for the color temperature */
    COLOR_TEMPERATURE_CMD_GET_TEMPERATURE_INC               = 7, /* Get the increment of the color temperature */
    COLOR_TEMPERATURE_CMD_GET_TEMPERATURE_DEFAULT           = 8, /* Get the default color temperature */
    COLOR_TEMPERATURE_CMD_GET_RGB_COLOR_MODEL_DEFAULT       = 9  /* Get the default RGB color model */

} COLOR_TEMPERATURE_CMD;

IDSEXP is_ColorTemperature(HIDS hf, UINT nCommand, void *pParam, UINT nSizeOfParam);

IDSEXP is_DirectRenderer(HIDS hf, UINT nMode, void *pParam, UINT SizeOfParam);

IDSEXP is_HotPixel(HIDS hf, UINT nMode, void *pParam, UINT SizeOfParam);


typedef struct 
{
    INT s32X;
    INT s32Y;
} IS_POINT_2D;

typedef struct 
{
    INT s32Width;
    INT s32Height;
} IS_SIZE_2D;

typedef struct
{
    INT s32X;
    INT s32Y;
    INT s32Width;
    INT s32Height;
} IS_RECT;


IDSEXP is_AOI(HIDS hf, UINT nCommand, void *pParam, UINT SizeOfParam); 

/*!
 * \brief Data type for 32-bit unsigned int value ranges.
 *
 * \note Introduced with uEye SDK 3.80.
 */
typedef struct S_RANGE_OF_VALUES_U32
{
    UINT    u32Minimum;     /*!< \brief Minimum value. */
    UINT    u32Maximum;     /*!< \brief Maximum value, not considered Infinite. */
    UINT    u32Increment;   /*!< \brief Increment value. */
    UINT    u32Default;     /*!< \brief Default value. */
    UINT    u32Infinite;    /*!< \brief Infinite code, where applicable. */

} RANGE_OF_VALUES_U32;


/*!
 * \brief Enumeration of transfer engine's capability flags, \see is_Transfer, \see TRANSFER_CMD_QUERY_CAPABILITIES.
 *
 * \note to come
 */
typedef enum E_TRANSFER_CAPABILITY_FLAGS
{
    /*!
     * \brief Capability flag: 'Image delay' setting supported.
     */
    TRANSFER_CAP_IMAGEDELAY         = 0x01,

    /*!
     * \brief Capability flag: 'Packet clock' setting supported.
     */
    TRANSFER_CAP_PACKETINTERVAL     = 0x20,

} TRANSFER_CAPABILITY_FLAGS;

/*!
 * \brief Enumeration of commands supported by the transfer engine access function, \see is_Transfer.
 *
 * \note to come
 */
typedef enum E_TRANSFER_CMD
{
    /*!
     * \brief   Query the transfer engine capabilities.
     *          Type of value: unsigned int bitmask, 32-bit.
     * \see TRANSFER_CAPABILITY_FLAGS.
     */
    TRANSFER_CMD_QUERY_CAPABILITIES             = 0,

    /*!
     * \brief   Set 'image delay' in us units.
     *          Type of value: unsigned int, 32-bit.
     */
    TRANSFER_CMD_SET_IMAGEDELAY_US              = 1000,
    /*!
     * \brief   Set 'packet clock' in us units.
     *          Type of value: unsigned int, 32-bit.
     */
    TRANSFER_CMD_SET_PACKETINTERVAL_US          = 1005,

    /*!
     * \brief   Get 'image delay' in us units.
     *          Type of value: unsigned int, 32-bit.
     */
    TRANSFER_CMD_GET_IMAGEDELAY_US              = 2000,
    /*!
     * \brief   Get 'packet clock' in us units.
     *          Type of value: unsigned int, 32-bit.
     */
    TRANSFER_CMD_GET_PACKETINTERVAL_US          = 2005,

    /*!
     * \brief   Get range of values for 'image delay'.
     *          Type of value: RANGE_OF_VALUES_U32, size of RANGE_OF_VALUES_U32.
     */
    TRANSFER_CMD_GETRANGE_IMAGEDELAY_US         = 3000,
    /*!
     * \brief   Get range of values for 'packet clock'.
     *          Type of value: RANGE_OF_VALUES_U32, size of RANGE_OF_VALUES_U32.
     */
    TRANSFER_CMD_GETRANGE_PACKETINTERVAL_US     = 3005

} TRANSFER_CMD;

/*!
 * \brief Generic interface to the transfer engine setup.
 * \param   hf              valid device handle.
 * \param   nCommand        code, indicates requested access and accessed value, \see TRANSFER_CMD enumeration.
 * \param   pParam          input or output storage for the accessed param.
 * \param   cbSizeOfParam   size of *pParam.
 * \return  error code
 *
 * \note to come
 *
 * \note For 'set' commands: If the resulting transfer engine setup differs from the current state the transfer param
 *          is immediately written to the device.
 * \note For 'set' commands: The function forces the value to the next lower catch according to the related increment.
 */
IDSEXP is_Transfer(HIDS hf, UINT nCommand, void* pParam, UINT cbSizeOfParam);


/*!
 * \brief Enumeration of commands supported by the device feature function, \see is_DeviceFeature.
 */
typedef enum E_DEVICE_FEATURE_CMD
{
    IS_DEVICE_FEATURE_CMD_GET_SUPPORTED_FEATURES        = 1,
    IS_DEVICE_FEATURE_CMD_SET_LINESCAN_MODE             = 2,
    IS_DEVICE_FEATURE_CMD_GET_LINESCAN_MODE             = 3,
    IS_DEVICE_FEATURE_CMD_SET_LINESCAN_NUMBER           = 4,
    IS_DEVICE_FEATURE_CMD_GET_LINESCAN_NUMBER           = 5,
    IS_DEVICE_FEATURE_CMD_SET_SHUTTER_MODE              = 6,
    IS_DEVICE_FEATURE_CMD_GET_SHUTTER_MODE              = 7,
    IS_DEVICE_FEATURE_CMD_SET_PREFER_XS_HS_MODE         = 8,
    IS_DEVICE_FEATURE_CMD_GET_PREFER_XS_HS_MODE         = 9,
    IS_DEVICE_FEATURE_CMD_GET_DEFAULT_PREFER_XS_HS_MODE = 10
} DEVICE_FEATURE_CMD;


/*!
 * \brief Enumeration of device feature capability flags, \see is_DeviceFeature
 */
typedef enum E_DEVICE_FEATURE_MODE_CAPS
{
    IS_DEVICE_FEATURE_CAP_SHUTTER_MODE_ROLLING      = 0x00000001,
    IS_DEVICE_FEATURE_CAP_SHUTTER_MODE_GLOBAL       = 0x00000002,
    IS_DEVICE_FEATURE_CAP_LINESCAN_MODE_FAST        = 0x00000004,
    IS_DEVICE_FEATURE_CAP_LINESCAN_NUMBER           = 0x00000008,
    IS_DEVICE_FEATURE_CAP_PREFER_XS_HS_MODE         = 0x00000010
} DEVICE_FEATURE_MODE_CAPS;


/*!
 * \brief Interface to control various device features.
 * \param   hf              valid device handle.
 * \param   nCommand        Specifies the command and device.
 * \param   pParam          input or output storage for the accessed param.
 * \param   cbSizeOfParam   size of *pParam.
 * \return  error code
 */
IDSEXP is_DeviceFeature(HIDS hf, UINT nCommand, void* pParam, UINT cbSizeOfParam);


/*!
 * \brief Enumeration of commands supported by the exposure function, \see is_Exposure.
 */
typedef enum E_EXPOSURE_CMD
{
    IS_EXPOSURE_CMD_GET_CAPS                        = 1,
    IS_EXPOSURE_CMD_GET_EXPOSURE_DEFAULT            = 2,
    IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MIN          = 3,
    IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_MAX          = 4,
    IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE_INC          = 5,
    IS_EXPOSURE_CMD_GET_EXPOSURE_RANGE              = 6,
    IS_EXPOSURE_CMD_GET_EXPOSURE                    = 7,
    IS_EXPOSURE_CMD_GET_FINE_INCREMENT_RANGE_MIN    = 8,
    IS_EXPOSURE_CMD_GET_FINE_INCREMENT_RANGE_MAX    = 9,
    IS_EXPOSURE_CMD_GET_FINE_INCREMENT_RANGE_INC    = 10,
    IS_EXPOSURE_CMD_GET_FINE_INCREMENT_RANGE        = 11,
    IS_EXPOSURE_CMD_SET_EXPOSURE                    = 12
} EXPOSURE_CMD;


typedef enum E_EXPOSURE_CAPS
{
    IS_EXPOSURE_CAP_EXPOSURE                        = 0x00000001,
    IS_EXPOSURE_CAP_FINE_INCREMENT                  = 0x00000002

} EXPOSURE_CAPS;


/*!
 * \brief Interface to control the camera exposure
 * \param   hf              valid device handle.
 * \param   nCommand        Specifies the command
 * \param   pParam          input or output storage for the accessed param.
 * \param   cbSizeOfParam   size of *pParam.
 * \return  error code
 */
IDSEXP is_Exposure(HIDS hf, UINT nCommand, void* pParam, UINT cbSizeOfParam);



typedef enum E_TRIGGER_CMD
{
    IS_TRIGGER_CMD_GET_BURST_SIZE_SUPPORTED     = 1,
    IS_TRIGGER_CMD_GET_BURST_SIZE_RANGE         = 2,
    IS_TRIGGER_CMD_GET_BURST_SIZE               = 3,
    IS_TRIGGER_CMD_SET_BURST_SIZE               = 4
    
} TRIGGER_CMD;


/*!
 * \brief Interface to control the trigger functions
 * \param   hf              valid device handle.
 * \param   nCommand        Specifies the command
 * \param   pParam          input or output storage for the accessed param.
 * \param   cbSizeOfParam   size of *pParam.
 * \return  error code
 */
IDSEXP is_Trigger(HIDS hf, UINT nCommand, void* pParam, UINT cbSizeOfParam);


// ----------------------------------------------------------------------------
// new functions and datatypes only valid for uEye ETH
// ----------------------------------------------------------------------------

#pragma pack( push, 1)

  // IP V4 address
  typedef union _UEYE_ETH_ADDR_IPV4
  {
      struct
      {
          BYTE  by1;
          BYTE  by2;
          BYTE  by3;
          BYTE  by4;
      } by;

      DWORD dwAddr;

  } UEYE_ETH_ADDR_IPV4, *PUEYE_ETH_ADDR_IPV4;

  // Ethernet address
  typedef struct _UEYE_ETH_ADDR_MAC
  {
      BYTE abyOctet[6];

  } UEYE_ETH_ADDR_MAC, *PUEYE_ETH_ADDR_MAC;

  // IP configuration
  typedef struct _UEYE_ETH_IP_CONFIGURATION
  {
      UEYE_ETH_ADDR_IPV4    ipAddress;      /*!< IP address */
      UEYE_ETH_ADDR_IPV4    ipSubnetmask;   /*!< IP subnetmask */

      BYTE                  reserved[4];    /*!< reserved */

  } UEYE_ETH_IP_CONFIGURATION, *PUEYE_ETH_IP_CONFIGURATION;

  // values for UEYE_ETH_DEVICE_INFO_HEARTBEAT::dwDeviceStatusFlags
  typedef enum _UEYE_ETH_DEVICESTATUS
  {
      IS_ETH_DEVSTATUS_READY_TO_OPERATE=            0x00000001, /*!< device is ready to operate */
      IS_ETH_DEVSTATUS_TESTING_IP_CURRENT=          0x00000002, /*!< device is (arp-)probing its current ip */
      IS_ETH_DEVSTATUS_TESTING_IP_PERSISTENT=       0x00000004, /*!< device is (arp-)probing its persistent ip */
      IS_ETH_DEVSTATUS_TESTING_IP_RANGE=            0x00000008, /*!< device is (arp-)probing the autocfg ip range */

      IS_ETH_DEVSTATUS_INAPPLICABLE_IP_CURRENT=     0x00000010, /*!< current ip is inapplicable */
      IS_ETH_DEVSTATUS_INAPPLICABLE_IP_PERSISTENT=  0x00000020, /*!< persistent ip is inapplicable */
      IS_ETH_DEVSTATUS_INAPPLICABLE_IP_RANGE=       0x00000040, /*!< autocfg ip range is inapplicable */

      IS_ETH_DEVSTATUS_UNPAIRED=                    0x00000100, /*!< device is unpaired */
      IS_ETH_DEVSTATUS_PAIRING_IN_PROGRESS=         0x00000200, /*!< device is being paired */
      IS_ETH_DEVSTATUS_PAIRED=                      0x00000400, /*!< device is paired */

      IS_ETH_DEVSTATUS_FORCE_100MBPS=               0x00001000, /*!< device phy is configured to 100 Mbps */
      IS_ETH_DEVSTATUS_NO_COMPORT=                  0x00002000, /*!< device does not support ueye eth comport */

      IS_ETH_DEVSTATUS_RECEIVING_FW_STARTER=        0x00010000, /*!< device is receiving the starter firmware */
      IS_ETH_DEVSTATUS_RECEIVING_FW_RUNTIME=        0x00020000, /*!< device is receiving the runtime firmware */
      IS_ETH_DEVSTATUS_INAPPLICABLE_FW_RUNTIME=     0x00040000, /*!< runtime firmware is inapplicable */
      IS_ETH_DEVSTATUS_INAPPLICABLE_FW_STARTER=     0x00080000, /*!< starter firmware is inapplicable */

      IS_ETH_DEVSTATUS_REBOOTING_FW_RUNTIME=        0x00100000, /*!< device is rebooting to runtime firmware */
      IS_ETH_DEVSTATUS_REBOOTING_FW_STARTER=        0x00200000, /*!< device is rebooting to starter firmware */
      IS_ETH_DEVSTATUS_REBOOTING_FW_FAILSAFE=       0x00400000, /*!< device is rebooting to failsafe firmware */

      IS_ETH_DEVSTATUS_RUNTIME_FW_ERR0=             0x80000000  /*!< checksum error runtime firmware */

  } UEYE_ETH_DEVICESTATUS;


  // heartbeat info transmitted periodically by a device
  // contained in UEYE_ETH_DEVICE_INFO
  typedef struct _UEYE_ETH_DEVICE_INFO_HEARTBEAT
  {
      BYTE                  abySerialNumber[12];        /*!< \brief camera's serial number (string) */

      BYTE                  byDeviceType;               /*!< \brief device type / board type, 0x80 for ETH */
      
      BYTE                  byCameraID;                 /*!< \brief camera id */

      WORD                  wSensorID;                  /*!< \brief camera's sensor's id */

      WORD                  wSizeImgMem_MB;             /*!< \brief size of camera's image memory in MB */

      BYTE                  reserved_1[2];              /*!< \brief reserved */

      DWORD                 dwVerStarterFirmware;       /*!< \brief starter firmware version */

      DWORD                 dwVerRuntimeFirmware;       /*!< \brief runtime firmware version */

      DWORD                 dwStatus;                   /*!< \brief camera status flags */

      BYTE                  reserved_2[4];              /*!< \brief reserved */
      
      WORD                  wTemperature;               /*!< \brief camera temperature */
      
      WORD                  wLinkSpeed_Mb;              /*!< \brief link speed in Mb */

      UEYE_ETH_ADDR_MAC     macDevice;                  /*!< \brief camera's MAC address */
      
      WORD                  wComportOffset;             /*!< \brief comport offset from 100, valid range -99 to +156 */

      UEYE_ETH_IP_CONFIGURATION ipcfgPersistentIpCfg;   /*!< \brief persistent IP configuration */

      UEYE_ETH_IP_CONFIGURATION ipcfgCurrentIpCfg;      /*!< \brief current IP configuration */

      UEYE_ETH_ADDR_MAC     macPairedHost;              /*!< \brief paired host's MAC address */

      BYTE                  reserved_4[2];              /*!< \brief reserved */

      UEYE_ETH_ADDR_IPV4    ipPairedHostIp;             /*!< \brief paired host's IP address */

      UEYE_ETH_ADDR_IPV4    ipAutoCfgIpRangeBegin;      /*!< \brief begin of IP address range */

      UEYE_ETH_ADDR_IPV4    ipAutoCfgIpRangeEnd;        /*!< \brief end of IP address range */

      BYTE                  abyUserSpace[8];            /*!< \brief user space data (first 8 bytes) */

      BYTE                  reserved_5[84];             /*!< \brief reserved */

      BYTE                  reserved_6[64];             /*!< \brief reserved */

  } UEYE_ETH_DEVICE_INFO_HEARTBEAT, *PUEYE_ETH_DEVICE_INFO_HEARTBEAT;

  // values for UEYE_ETH_DEVICE_INFO_CONTROL::dwControlStatus
  typedef enum _UEYE_ETH_CONTROLSTATUS
  {
      IS_ETH_CTRLSTATUS_AVAILABLE =             0x00000001, /*!< device is available TO US */
      IS_ETH_CTRLSTATUS_ACCESSIBLE1 =           0x00000002, /*!< device is accessible BY US, i.e. directly 'unicastable' */
      IS_ETH_CTRLSTATUS_ACCESSIBLE2 =           0x00000004, /*!< device is accessible BY US, i.e. not on persistent ip and adapters ip autocfg range is valid */

      IS_ETH_CTRLSTATUS_PERSISTENT_IP_USED =    0x00000010, /*!< device is running on persistent ip configuration */
      IS_ETH_CTRLSTATUS_COMPATIBLE =            0x00000020, /*!< device is compatible TO US */
      IS_ETH_CTRLSTATUS_ADAPTER_ON_DHCP =       0x00000040, /*!< adapter is configured to use dhcp */
      IS_ETH_CTRLSTATUS_ADAPTER_SETUP_OK =      0x00000080, /*!< adapter's setup is ok with respect to uEye needs */

      IS_ETH_CTRLSTATUS_UNPAIRING_IN_PROGRESS = 0x00000100, /*!< device is being unpaired FROM US */
      IS_ETH_CTRLSTATUS_PAIRING_IN_PROGRESS =   0x00000200, /*!< device is being paired TO US */

      IS_ETH_CTRLSTATUS_PAIRED =                0x00001000, /*!< device is paired TO US */

      IS_ETH_CTRLSTATUS_FW_UPLOAD_STARTER =     0x00010000, /*!< device is receiving the starter firmware */
      IS_ETH_CTRLSTATUS_FW_UPLOAD_RUNTIME =     0x00020000, /*!< device is receiving the runtime firmware */

      IS_ETH_CTRLSTATUS_REBOOTING =             0x00100000, /*!< device is rebooting */

      IS_ETH_CTRLSTATUS_INITIALIZED =           0x08000000, /*!< device object is initialized */

      IS_ETH_CTRLSTATUS_TO_BE_DELETED =         0x40000000, /*!< device object is being deleted */
      IS_ETH_CTRLSTATUS_TO_BE_REMOVED =         0x80000000, /*!< device object is being removed */

  } UEYE_ETH_CONTROLSTATUS;

  // control info for a listed device
  // contained in UEYE_ETH_DEVICE_INFO
  typedef struct _UEYE_ETH_DEVICE_INFO_CONTROL
  {
      DWORD     dwDeviceID;         /*!< device's unique id */

      DWORD     dwControlStatus;    /*!< device control status */

      BYTE      reserved_1[80];     /*!< reserved */

      BYTE      reserved_2[64];     /*!< reserved */

  } UEYE_ETH_DEVICE_INFO_CONTROL, *PUEYE_ETH_DEVICE_INFO_CONTROL;

  // Ethernet configuration
  typedef struct _UEYE_ETH_ETHERNET_CONFIGURATION
  {
      UEYE_ETH_IP_CONFIGURATION ipcfg;
      UEYE_ETH_ADDR_MAC         mac;

  } UEYE_ETH_ETHERNET_CONFIGURATION, *PUEYE_ETH_ETHERNET_CONFIGURATION;

  // autocfg ip setup
  typedef struct _UEYE_ETH_AUTOCFG_IP_SETUP
  {
      UEYE_ETH_ADDR_IPV4    ipAutoCfgIpRangeBegin;      /*!< begin of ip address range for devices */
      UEYE_ETH_ADDR_IPV4    ipAutoCfgIpRangeEnd;        /*!< end of ip address range for devices */

      BYTE                  reserved[4];    /*!< reserved */

  } UEYE_ETH_AUTOCFG_IP_SETUP, *PUEYE_ETH_AUTOCFG_IP_SETUP;

  // values for incoming packets filter setup
  typedef enum _UEYE_ETH_PACKETFILTER_SETUP
  {
      // notice: arp and icmp (ping) packets are always passed!

      IS_ETH_PCKTFLT_PASSALL=       0,  /*!< pass all packets to OS */
      IS_ETH_PCKTFLT_BLOCKUEGET=    1,  /*!< block UEGET packets to the OS */
      IS_ETH_PCKTFLT_BLOCKALL=      2   /*!< block all packets to the OS */

  } UEYE_ETH_PACKETFILTER_SETUP;

  // values for link speed setup
  typedef enum _UEYE_ETH_LINKSPEED_SETUP
  {
      IS_ETH_LINKSPEED_100MB=		100,    /*!< 100 MBits */
      IS_ETH_LINKSPEED_1000MB=	    1000    /*!< 1000 MBits */

  } UEYE_ETH_LINKSPEED_SETUP;


  // control info for a device's network adapter
  // contained in UEYE_ETH_DEVICE_INFO
  typedef struct _UEYE_ETH_ADAPTER_INFO
  {
      DWORD                             dwAdapterID;        /*!< adapter's unique id */

      DWORD                             dwDeviceLinkspeed;  /*!< device's linked to this adapter are forced to use this link speed */

      UEYE_ETH_ETHERNET_CONFIGURATION   ethcfg;         /*!< adapter's eth configuration */
      BYTE                              reserved_2[2];  /*!< reserved */
      BOOL                              bIsEnabledDHCP; /*!< adapter's dhcp enabled flag */

      UEYE_ETH_AUTOCFG_IP_SETUP         autoCfgIp;                  /*!< the setup for the ip auto configuration */
      BOOL                              bIsValidAutoCfgIpRange;     /*!<    the given range is valid when: 
                                                                            - begin and end are valid ip addresses
                                                                            - begin and end are in the subnet of the adapter
                                                                            - */

      DWORD                             dwCntDevicesKnown;      /*!< count of listed Known devices */
      DWORD                             dwCntDevicesPaired;     /*!< count of listed Paired devices */

      WORD                              wPacketFilter;          /*!< Setting for the Incoming Packets Filter. see UEYE_ETH_PACKETFILTER_SETUP enum above. */

      BYTE                              reserved_3[38];         /*!< reserved */
      BYTE                              reserved_4[64];         /*!< reserved */

  } UEYE_ETH_ADAPTER_INFO, *PUEYE_ETH_ADAPTER_INFO;

  // driver info
  // contained in UEYE_ETH_DEVICE_INFO
  typedef struct _UEYE_ETH_DRIVER_INFO
  {
      DWORD     dwMinVerStarterFirmware;    /*!< minimum version compatible starter firmware */
      DWORD     dwMaxVerStarterFirmware;    /*!< maximum version compatible starter firmware */

      BYTE      reserved_1[8];              /*!< reserved */
      BYTE      reserved_2[64];             /*!< reserved */

  } UEYE_ETH_DRIVER_INFO, *PUEYE_ETH_DRIVER_INFO;



  // use is_GetEthDeviceInfo() to obtain this data.
  typedef struct _UEYE_ETH_DEVICE_INFO
  {
      UEYE_ETH_DEVICE_INFO_HEARTBEAT    infoDevHeartbeat;

      UEYE_ETH_DEVICE_INFO_CONTROL      infoDevControl;

      UEYE_ETH_ADAPTER_INFO             infoAdapter;

      UEYE_ETH_DRIVER_INFO              infoDriver;

  } UEYE_ETH_DEVICE_INFO, *PUEYE_ETH_DEVICE_INFO;


  typedef struct _UEYE_COMPORT_CONFIGURATION
  {
      WORD wComportNumber;

  } UEYE_COMPORT_CONFIGURATION, *PUEYE_COMPORT_CONFIGURATION;


#pragma pack(pop)

  IDSEXP is_GetEthDeviceInfo    (HIDS hf, UEYE_ETH_DEVICE_INFO* pDeviceInfo, UINT uStructSize);
  IDSEXP is_SetPersistentIpCfg  (HIDS hf, UEYE_ETH_IP_CONFIGURATION* pIpCfg, UINT uStructSize);
  IDSEXP is_SetStarterFirmware  (HIDS hf, const CHAR* pcFilepath, UINT uFilepathLen);

  IDSEXP is_SetAutoCfgIpSetup   (INT iAdapterID, const UEYE_ETH_AUTOCFG_IP_SETUP* pSetup, UINT uStructSize);
  IDSEXP is_SetPacketFilter     (INT iAdapterID, UINT uFilterSetting);
  
  IDSEXP is_GetComportNumber    (HIDS hf, UINT *pComportNumber);


/*!
 * \brief Enumeration of IpConfig capability flags, \see is_IpConfig, \see IPCONFIG_CMD_QUERY_CAPABILITIES.
 *
 * \note Introduced with uEye SDK 3.80.
 */
typedef enum E_IPCONFIG_CAPABILITY_FLAGS
{
    /*! \brief Capability flag indicates support of Persistent IP for the device in question. */
    IPCONFIG_CAP_PERSISTENT_IP_SUPPORTED    = 0x01,

    /*! \brief Capability flag indicates support of IP auto configuration for the device in question. */
    IPCONFIG_CAP_AUTOCONFIG_IP_SUPPORTED    = 0x04

} IPCONFIG_CAPABILITY_FLAGS;

/*!
 * \brief Enumeration of commands supported by the IP configuration access function, \see is_IpConfig.
 *
 * \note Introduced with uEye SDK 3.80.
 */
typedef enum E_IPCONFIG_CMD
{
    /*!
     * \brief   Query the IP configuration capabilities.
     *          Type of value: unsigned int bitmask, 32-bit.
     * \see DHCP_CAPABILITY_FLAGS.
     */
    IPCONFIG_CMD_QUERY_CAPABILITIES = 0,

    /*!
     * \brief   Set persistent IP configuration.
     *          Type of value: \see UEYE_ETH_IP_CONFIGURATION.
     *
     * \note Use camera's device id or camera's MAC address as identifier for \see is_IpConfig.
     * \note Changing persistent IP configuration enabled status is allowed only if device is not paired.
     */
    IPCONFIG_CMD_SET_PERSISTENT_IP  = 0x01010000,
    /*!
     * \brief   Set IP auto configuration setup.
     *          Type of value: \see UEYE_ETH_AUTOCFG_IP_SETUP.
     *
     * \note Use NIC's adapter id or NIC's MAC address as identifier for \see is_IpConfig.
     * \note Changed autoconfig IP setup is applied for each device connected to the addressed NIC
     *          at the next pairing of the device.
     */
    IPCONFIG_CMD_SET_AUTOCONFIG_IP  = 0x01040000,

    /*!
     * \brief   Get persistent IP configuration.
     *          Type of value: \see UEYE_ETH_IP_CONFIGURATION.
     *
     * \note Use camera's device id or camera's MAC address as identifier for \see is_IpConfig.
     */
    IPCONFIG_CMD_GET_PERSISTENT_IP  = 0x02010000,
    /*!
     * \brief   Get IP auto configuration setup.
     *          Type of value: \see UEYE_ETH_AUTOCFG_IP_SETUP.
     *
     * \note Use NIC's adapter id or NIC's MAC address as identifier for \see is_IpConfig.
     */
    IPCONFIG_CMD_GET_AUTOCONFIG_IP  = 0x02040000

} IPCONFIG_CMD;

/*!
 * \brief Generic interface to the device's IP configuration.
 * \param   iID             if != -1: id of the addressed camera device / network adapter.
 * \param   mac             if iID == -1: mac of the addressed camera device / network adapter.
 * \param   nCommand        code, indicates requested access and accessed value, \see IPCONFIG_CMD enumeration.
 * \param   pParam          input or output storage for the accessed param.
 * \param   cbSizeOfParam   size of *pParam.
 * \return  error code
 *
 * \note Introduced with uEye SDK 3.81.
 */
IDSEXP is_IpConfig(INT iID, UEYE_ETH_ADDR_MAC mac, UINT nCommand, void* pParam, UINT cbSizeOfParam);





/*!
 * \brief Enumeration of defines used by is_Configuration(), \see is_Configuration.
 */
typedef enum E_CONFIGURATION_SEL
{
    IS_CONFIG_CPU_IDLE_STATES_BIT_AC_VALUE         = 0x01, /*!< Mains power */
    IS_CONFIG_CPU_IDLE_STATES_BIT_DC_VALUE         = 0x02, /*!< Battery power */

    IS_CONFIG_OPEN_MP_DISABLE                      = 0,
    IS_CONFIG_OPEN_MP_ENABLE                       = 1,

    IS_CONFIG_INITIAL_PARAMETERSET_NONE            = 0,
    IS_CONFIG_INITIAL_PARAMETERSET_1               = 1,
    IS_CONFIG_INITIAL_PARAMETERSET_2               = 2

} CONFIGURATION_SEL;



/*!
 * \brief Enumeration of commands of function is_Configuration , \see is_Configuration.
 */
typedef enum E_CONFIGURATION_CMD
{
    IS_CONFIG_CMD_GET_CAPABILITIES                         = 1, /*!< Get supported configuration capabilities (bitmask of CONFIGURATION_CAPS)*/
    
    IS_CONFIG_CPU_IDLE_STATES_CMD_GET_ENABLE               = 2, /*!< Get the current CPU idle states enable state (bitmask of CONFIGURATION_SEL)*/
    IS_CONFIG_CPU_IDLE_STATES_CMD_SET_DISABLE_ON_OPEN      = 4, /*!< Disable migration to other CPU idle states (other than C0) if the first USB camera is being opened*/
    IS_CONFIG_CPU_IDLE_STATES_CMD_GET_DISABLE_ON_OPEN      = 5, /*!< Get the current setting of the command IS_CPU_IDLE_STATES_CMD_SET_DISABLE_ON_OPEN*/

    IS_CONFIG_OPEN_MP_CMD_GET_ENABLE                       = 6,
    IS_CONFIG_OPEN_MP_CMD_SET_ENABLE                       = 7,
    IS_CONFIG_OPEN_MP_CMD_GET_ENABLE_DEFAULT               = 8,

    IS_CONFIG_INITIAL_PARAMETERSET_CMD_SET                 = 9,
    IS_CONFIG_INITIAL_PARAMETERSET_CMD_GET                 = 10

} CONFIGURATION_CMD;


/*!
 * \brief Enumeration of configuration command capability flags, \see is_Configuration.
 */
typedef enum E_CONFIGURATION_CAPS
{
    IS_CONFIG_CPU_IDLE_STATES_CAP_SUPPORTED                = 0x00000001, /*!< CPU idle state commands are supported by the SDK */
    IS_CONFIG_OPEN_MP_CAP_SUPPORTED                        = 0x00000002, /*!< Open MP commands are supported by the SDK */
    IS_CONFIG_INITIAL_PARAMETERSET_CAP_SUPPORTED           = 0x00000004  /*!< Initial parameter set commands are supported by the SDK */
} CONFIGURATION_CAPS;


/*!
 * \brief Command to set general configuration parameters (e.g. the CPU idle state settings)
 * \param   nCommand        specifies the command, \see CONFIGURATION_CMD.
 * \param   pParam          input or output storage for the accessed param.
 * \param   cbSizeOfParam   size of *pParam.
 * \return  error code.
 */
IDSEXP is_Configuration(UINT nCommand, void* pParam, UINT cbSizeOfParam);


#ifdef __cplusplus
};
#endif  /* __cplusplus */

#pragma pack(pop)

#endif  // #ifndef __IDS_HEADER__
