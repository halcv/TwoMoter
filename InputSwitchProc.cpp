#include "InputSwitchProc.h"
#include "MyInstance.h"

#define PULL_UP                 (HIGH)
#define PULL_DOWN                (LOW)
#define PORT_PULL_UP_DOWN    (PULL_UP)
#define LONG_ON_COUNTER_MAX      (200)

CInputSwitchProc::CInputSwitchProc()
{
    for (int i = 0;i < E_SW_NAME_MAX;i++) {
        m_sSwitchStatus[i].eNowState = E_SW_STATE_OFF;
        m_sSwitchStatus[i].iLongOnCounter = 0;
    }
}


void CInputSwitchProc::vInputSwitchStateMachine()
{
    if (CMyInstance::GetInputSwitchTimerInstance()->isCheckInputSwitchTime() == false) {
        return;
    }
    
    for (int i = 0;i < E_SW_NAME_MAX;i++) {
        int iNewState = CMyInstance::GetInputSwitchDriveInstance()->nGetInputSwitchState((E_SW_NAME)i);

        switch(m_sSwitchStatus[i].eNowState) {
        case E_SW_STATE_OFF:
            if (iNewState == PORT_PULL_UP_DOWN) {
                vOffToOff((E_SW_NAME)i);
            } else {
                vOffToOn((E_SW_NAME)i);
            }
            break;
        case E_SW_STATE_ON:
            if (iNewState == PORT_PULL_UP_DOWN) {
                vOnToOff((E_SW_NAME)i);
            } else {
                vOnToOn((E_SW_NAME)i);
            }
            break;
        case E_SW_STATE_LONG_ON:
            if (iNewState == PORT_PULL_UP_DOWN) {
                vLongOnToOff((E_SW_NAME)i);
            } else {
                vLongOnToLongOn((E_SW_NAME)i);
            }
            break;
        }
    }
}

void CInputSwitchProc::vOffToOff(E_SW_NAME eSwName)
{
    m_sSwitchStatus[eSwName].eNowState = E_SW_STATE_OFF;
    m_sSwitchStatus[eSwName].iLongOnCounter = 0;
}

void CInputSwitchProc::vOffToOn(E_SW_NAME eSwName)
{
    m_sSwitchStatus[eSwName].eNowState = E_SW_STATE_ON;
    m_sSwitchStatus[eSwName].iLongOnCounter = 0;
    vOn(eSwName);
}

void CInputSwitchProc::vOnToOff(E_SW_NAME eSwName)
{
    m_sSwitchStatus[eSwName].eNowState = E_SW_STATE_OFF;
    m_sSwitchStatus[eSwName].iLongOnCounter = 0;
    vOff(eSwName);
}

void CInputSwitchProc::vOnToOn(E_SW_NAME eSwName)
{
    m_sSwitchStatus[eSwName].eNowState = E_SW_STATE_ON;
    m_sSwitchStatus[eSwName].iLongOnCounter++;
    if (m_sSwitchStatus[eSwName].iLongOnCounter >= LONG_ON_COUNTER_MAX) {
        vOnToLongOn(eSwName);
    }
}

void CInputSwitchProc::vOnToLongOn(E_SW_NAME eSwName)
{
    m_sSwitchStatus[eSwName].eNowState = E_SW_STATE_LONG_ON;
    m_sSwitchStatus[eSwName].iLongOnCounter = 0;
}

void CInputSwitchProc::vLongOnToLongOn(E_SW_NAME eSwName)
{
    m_sSwitchStatus[eSwName].eNowState = E_SW_STATE_LONG_ON;
    m_sSwitchStatus[eSwName].iLongOnCounter = 0;
    vLongOn(eSwName);
}

void CInputSwitchProc::vLongOnToOff(E_SW_NAME eSwName)
{
    m_sSwitchStatus[eSwName].eNowState = E_SW_STATE_OFF;
    m_sSwitchStatus[eSwName].iLongOnCounter = 0;
    vOff(eSwName);
}

void CInputSwitchProc::vOn(E_SW_NAME eSwName)
{
    switch(eSwName) {
    case E_SW_NAME_MOTER_START_STOP:
		CMyInstance::GetMoterDriveInstance()->vChangeMoterStateRequest();
        break;
    }
}

void CInputSwitchProc::vLongOn(E_SW_NAME eSwName)
{
    switch(eSwName) {
    case E_SW_NAME_MOTER_START_STOP:
        break;
    }
}

void CInputSwitchProc::vOff(E_SW_NAME eSwName)
{
    switch(eSwName) {
    case E_SW_NAME_MOTER_START_STOP:
        break;
    }
}
