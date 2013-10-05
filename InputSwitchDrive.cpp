#include "InputSwitchDrive.h"

CInputSwitchDrive::CInputSwitchDrive()
{
}

int CInputSwitchDrive::nGetInputSwitchState(E_SW_NAME eSwitchName)
{
	return (digitalRead(nGetSwitchPort(eSwitchName)));
}

int CInputSwitchDrive::nGetSwitchPort(E_SW_NAME eSwitchName)
{
	int nPort = MOTER_START_STOP_SWITCH_PORT;
	switch (eSwitchName) {
	case E_SW_NAME_MOTER_START_STOP:
		nPort = MOTER_START_STOP_SWITCH_PORT;
		break;
	default:
		;
	}

	return nPort;
}
