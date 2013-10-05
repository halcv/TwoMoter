#ifndef _INPUT_SWITCH_DRIVE_H_
#define _INPUT_SWITCH_DRIVE_H_

#include "board.h"
#include "InputSwitchProc.h"

class CInputSwitchDrive {
  public:
	CInputSwitchDrive();
	int nGetInputSwitchState(E_SW_NAME eSwitchName);
  private:
	int nGetSwitchPort(E_SW_NAME eSwitchName);
};

#endif // _INPUT_SWITCH_DRIVE_H_
