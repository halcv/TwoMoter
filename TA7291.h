#ifndef _TA7291_H_
#define _TA7291_H_

#include "Board.h"

class CTA7291 {
  public:
	CTA7291();
	void vStopRequest();
	void vNormalRequest();
	void vReverseRequest();

  private:
	void vSetStop();
	void vSetNormal();
	void vSetReverse();
};

#endif // _TA7291_H_
