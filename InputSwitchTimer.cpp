#include "InputSwitchTimer.h"

#define INPUT_SWITCH_TIME_MAX (2) // 20ms

CInputSwitchTimer::CInputSwitchTimer()
{
	m_nInputSwitchTime = 0;
}

void CInputSwitchTimer::vIncInputSwitchTime()
{
	if (m_nInputSwitchTime < INPUT_SWITCH_TIME_MAX) {
		m_nInputSwitchTime++;
	}
}

boolean CInputSwitchTimer::isCheckInputSwitchTime()
{
	boolean isRet = false;

	if (m_nInputSwitchTime >= INPUT_SWITCH_TIME_MAX) {
		isRet = true;
		m_nInputSwitchTime = 0;
	}

	return isRet;
}
