#include "MoterDrive.h"
#include "MyInstance.h"

CMoterDrive::CMoterDrive()
{
	m_eMoterNowState = E_MOTER_STATE_STOP;
}

void CMoterDrive::vChangeMoterStateRequest()
{
	switch(m_eMoterNowState) {
	case E_MOTER_STATE_STOP:
		m_eMoterNowState = E_MOTER_STATE_NORMAL;
		CMyInstance::GetTA7291Instance()->vNormalRequest();
		break;
	case E_MOTER_STATE_NORMAL:
		m_eMoterNowState = E_MOTER_STATE_REVERSE;
		CMyInstance::GetTA7291Instance()->vReverseRequest();
		break;
	case E_MOTER_STATE_REVERSE:
		m_eMoterNowState = E_MOTER_STATE_STOP;
		CMyInstance::GetTA7291Instance()->vStopRequest();
		break;
	}
}

