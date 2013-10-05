#ifndef _INPUT_SWITCH_PROC_H_
#define _INPUT_SWITCH_PROC_H_

#include "Board.h"

typedef enum {
    E_SW_NAME_MOTER_START_STOP,
 	
    E_SW_NAME_MAX
} E_SW_NAME;

typedef enum {
    E_SW_STATE_OFF,
    E_SW_STATE_ON,
    E_SW_STATE_LONG_ON,

	E_SW_STATE_MAX
} E_SW_STATE;

typedef struct {
    E_SW_STATE eNowState;
    int iLongOnCounter;
} S_SW_STATUS;

class CInputSwitchProc {
  public:
	CInputSwitchProc();
	void vInputSwitchStateMachine();
	
  private:
	void vOffToOff(E_SW_NAME eSwName);
    void vOffToOn(E_SW_NAME eSwName);
    void vOnToOn(E_SW_NAME eSwName);
    void vOnToOff(E_SW_NAME eSwName);
    void vOnToLongOn(E_SW_NAME eSwName);
    void vLongOnToLongOn(E_SW_NAME eSwName);
    void vLongOnToOff(E_SW_NAME eSwName);
    void vOn(E_SW_NAME eSwName);
    void vLongOn(E_SW_NAME eSwName);
    void vOff(E_SW_NAME eSwName);
    int iGetPort(E_SW_NAME eSwName);
    S_SW_STATUS m_sSwitchStatus[E_SW_NAME_MAX];
};

#endif // _INPUT_SWITCH_PROC_H_
