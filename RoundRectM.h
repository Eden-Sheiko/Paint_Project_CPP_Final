#pragma once
#include "RectangleM.h"
class RoundRectM :public RectangleM 
{
	DECLARE_SERIAL(RoundRectM)
public:
	RoundRectM();
	RoundRectM(CPoint, CPoint, int ,int);
	~RoundRectM();
	void Draw(CDC *dc);
};
