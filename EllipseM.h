#pragma once
#include "Figure.h"

class EllipseM :public Figure {
	DECLARE_SERIAL(EllipseM)
public:
	EllipseM(); 
	EllipseM(CPoint p1, CPoint p2);
	virtual void Draw(CDC *dc);
};