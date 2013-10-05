#include "MyInstance.h"

#define METRO_10MS_INTERVAL   (10)

Metro* CMyInstance::m_pMetro10ms = NULL;
CInputSwitchTimer* CMyInstance::m_pInputSwitchTimer = NULL;
CInputSwitchProc* CMyInstance::m_pInputSwitchProc = NULL;
CInputSwitchDrive* CMyInstance::m_pInputSwitchDrive = NULL;
CMoterDrive* CMyInstance::m_pMoterDrive = NULL;
CTA7291* CMyInstance::m_pTA7291 = NULL;

void CMyInstance::vCreateInstance()
{
	m_pMetro10ms = new Metro(METRO_10MS_INTERVAL);
	m_pInputSwitchTimer = new CInputSwitchTimer();
	m_pInputSwitchProc = new CInputSwitchProc();
	m_pInputSwitchDrive = new CInputSwitchDrive();
	m_pMoterDrive = new CMoterDrive();
	m_pTA7291 = new CTA7291();
}

Metro* CMyInstance::GetMetro10msInstance()
{
	return m_pMetro10ms;
}

CInputSwitchTimer* CMyInstance::GetInputSwitchTimerInstance()
{
	return m_pInputSwitchTimer;
}

CInputSwitchProc* CMyInstance::GetInputSwitchProcInstance()
{
	return m_pInputSwitchProc;
}

CInputSwitchDrive* CMyInstance::GetInputSwitchDriveInstance()
{
	return m_pInputSwitchDrive;
}

CMoterDrive* CMyInstance::GetMoterDriveInstance()
{
	return m_pMoterDrive;
}

CTA7291* CMyInstance::GetTA7291Instance()
{
	return m_pTA7291;
}
