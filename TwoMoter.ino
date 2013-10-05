#include <Metro.h>
#include "MyInstance.h"
#include "Board.h"

static void vMain_InitPort();
static void vMain_CheckMetroInterval();

void setup()
{
	vMain_InitPort();
	CMyInstance::vCreateInstance();
}

void loop()
{
	vMain_CheckMetroInterval();
}

static void vMain_CheckMetroInterval()
{
	if (CMyInstance::GetMetro10msInstance()->check()) {
		CMyInstance::GetInputSwitchTimerInstance()->vIncInputSwitchTime();
	}

	CMyInstance::GetInputSwitchProcInstance()->vInputSwitchStateMachine();
}

static void vMain_InitPort()
{
	pinMode(MOTER1_IN1_PORT,OUTPUT);
	digitalWrite(MOTER1_IN1_PORT,LOW);
	pinMode(MOTER1_IN2_PORT,OUTPUT);
	digitalWrite(MOTER1_IN2_PORT,LOW);
	pinMode(MOTER1_PWM_PORT,OUTPUT);
	analogWrite(MOTER1_PWM_PORT,127);

	pinMode(MOTER2_IN1_PORT,OUTPUT);
	digitalWrite(MOTER2_IN1_PORT,LOW);
	pinMode(MOTER2_IN2_PORT,OUTPUT);
	digitalWrite(MOTER2_IN2_PORT,LOW);
	pinMode(MOTER2_PWM_PORT,OUTPUT);
	analogWrite(MOTER2_PWM_PORT,127);

	pinMode(MOTER_START_STOP_SWITCH_PORT,INPUT);
}
