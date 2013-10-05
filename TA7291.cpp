#include "TA7291.h"

CTA7291::CTA7291()
{
}

void CTA7291::vStopRequest()
{
	vSetStop();
}

void CTA7291::vNormalRequest()
{
	vSetNormal();
}

void CTA7291::vReverseRequest()
{
	vSetReverse();
}

void CTA7291::vSetStop()
{
	digitalWrite(MOTER1_IN1_PORT,LOW);
	digitalWrite(MOTER1_IN2_PORT,LOW);

	digitalWrite(MOTER2_IN1_PORT,LOW);
	digitalWrite(MOTER2_IN2_PORT,LOW);

	delay(1);
}

void CTA7291::vSetNormal()
{
	vSetStop();

	digitalWrite(MOTER1_IN1_PORT,HIGH);
	digitalWrite(MOTER1_IN2_PORT,LOW);

	digitalWrite(MOTER2_IN1_PORT,HIGH);
	digitalWrite(MOTER2_IN2_PORT,LOW);

}

void CTA7291::vSetReverse()
{
	vSetStop();

	digitalWrite(MOTER1_IN1_PORT,LOW);
	digitalWrite(MOTER1_IN2_PORT,HIGH);

	digitalWrite(MOTER2_IN1_PORT,LOW);
	digitalWrite(MOTER2_IN2_PORT,HIGH);
}
