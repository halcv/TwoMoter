#ifndef _INPUT_SWITCH_TIMER_H_
#define _INPUT_SWITCH_TIMER_H_

#include "Board.h"

class CInputSwitchTimer {
  public:
	CInputSwitchTimer();
	void vIncInputSwitchTime();
	boolean isCheckInputSwitchTime();
	
  private:
	int m_nInputSwitchTime;
};

#endif // _INPUT_SWITCH_TIMER_H_
