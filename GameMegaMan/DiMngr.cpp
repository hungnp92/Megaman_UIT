#include "DiMngr.h"

DiMngr::DiMngr()
{
	pDI = NULL;
	pDIDevice = NULL;
}

DiMngr::~DiMngr(void)
{
	Shutdown();
}

bool DiMngr::Initialize(HWND wndHandle)
{
		HRESULT hResult;
	
		// Create the DirectInput object. 
		hResult = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&pDI, NULL);
	
		if FAILED(hResult)
		{
			return FALSE;
		}
	
		// Retrieve a pointer to an IDirectInputDevice8 interface 
		hResult = pDI->CreateDevice(GUID_SysKeyboard, &pDIDevice, NULL);
		if FAILED(hResult)
		{
			return FALSE;
		}
	
		hResult = pDIDevice->SetDataFormat(&c_dfDIKeyboard);
		if FAILED(hResult)
		{
			return FALSE;
		}
	
		// Set the cooperative level 
		hResult = pDIDevice->SetCooperativeLevel(wndHandle, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
		if FAILED(hResult)
		{
			return FALSE;
		}
	
		// Set keyboard properties
		DIPROPDWORD diProp;
	
		diProp.diph.dwSize = sizeof(DIPROPDWORD);
		diProp.diph.dwHeaderSize = sizeof(DIPROPHEADER);
		diProp.diph.dwObj = 0;
		diProp.diph.dwHow = DIPH_DEVICE;
		diProp.dwData = KEYBOARD_BUFFER_SIZE;
	
		hResult = pDIDevice->SetProperty(DIPROP_BUFFERSIZE, &diProp.diph);
		if FAILED(hResult)
		{
			return FALSE;
		}
	
		// Get access to the input device. 
		hResult = pDIDevice->Acquire();
		if FAILED(hResult)
		{
			return FALSE;
		}
	
		return true;
}

void DiMngr::Shutdown()
{
	if (pDI)
	{
		if (pDIDevice)
		{
			pDIDevice->Unacquire();
			pDIDevice->Release();
			pDIDevice = NULL;
		}
		pDI->Release();
		pDI = NULL;
	}
}

void DiMngr::GetInputState()
{
	HRESULT hResult;
	hResult = pDIDevice->GetDeviceState(sizeof(keyState), &keyState);
	if (FAILED(hResult)){
		// try and reacquire the input device
		hResult = pDIDevice->Acquire();

		// do a continuous loop until the device is reacquired
		while (hResult == DIERR_INPUTLOST)
		{
			hResult = pDIDevice->Acquire();
		}
	}
}

void DiMngr::GetInputData(){
	dwElements = KEYBOARD_BUFFER_SIZE;
	HRESULT hResult;
	hResult = pDIDevice->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), KeyEvents, &dwElements, 0);
	if (FAILED(hResult)
		){
		// try and reacquire the input device
		hResult = pDIDevice->Acquire();

		// do a continuous loop until the device is reacquired
		while (hResult == DIERR_INPUTLOST)
		{
			hResult = pDIDevice->Acquire();
		}
	}
}

bool DiMngr::IsKeyDown(int keycode)
{
	return (bool)KEYDOWN(keyState, keycode);
}

LPDIRECTINPUTDEVICE8 DiMngr::GetDevice(){
	return pDIDevice;
}