#ifndef _MOTER_DRIVE_H_
#define _MOTER_DRIVE_H_

#include "Board.h"

typedef enum {
	E_MOTER_STATE_STOP,
	E_MOTER_STATE_NORMAL,
	E_MOTER_STATE_REVERSE,

	E_MOTER_STATE_MAX
} E_MOTER_STATE;

class CMoterDrive {
  public:
	CMoterDrive();
	void vChangeMoterStateRequest();
	
  private:
	E_MOTER_STATE m_eMoterNowState;
};

#endif // _MOTER_DRIVE_H_

