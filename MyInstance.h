#ifndef _MY_INSTANCE_H_
#define _MY_INSTANCE_H_

#include "board.h"
#include <Metro.h>
#include "InputSwitchTimer.h"
#include "InputSwitchProc.h"
#include "InputSwitchDrive.h"
#include "MoterDrive.h"
#include "TA7291.h"

class CMyInstance {
  public:
	static void vCreateInstance();
	static Metro* GetMetro10msInstance();
	static CInputSwitchTimer* GetInputSwitchTimerInstance();
	static CInputSwitchProc* GetInputSwitchProcInstance();
	static CInputSwitchDrive* GetInputSwitchDriveInstance();
	static CMoterDrive* GetMoterDriveInstance();
	static CTA7291* GetTA7291Instance();
	
  private:
	static Metro* m_pMetro10ms;
	static CInputSwitchTimer* m_pInputSwitchTimer;
	static CInputSwitchProc* m_pInputSwitchProc;
	static CInputSwitchDrive* m_pInputSwitchDrive;
	static CMoterDrive* m_pMoterDrive;
	static CTA7291* m_pTA7291;
};

#endif // _MY_INSTANCE_H_
