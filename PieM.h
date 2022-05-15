#pragma once
#include "EllipseM.h"
	
class PieM :public EllipseM {
	DECLARE_SERIAL(PieM)
public:
	PieM();
	PieM(CPoint , CPoint ,int, int);
	~PieM();
	void Draw(CDC *dc);
};