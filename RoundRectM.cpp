#include "stdafx.h"
#include "RoundRectM.h"

	IMPLEMENT_SERIAL(RoundRectM,CObject,1)

RoundRectM::RoundRectM()
{
}

RoundRectM::RoundRectM(CPoint p1, CPoint p2, int x, int y) : RectangleM(p1,p2)
{
}
RoundRectM::~RoundRectM()
{
}

void RoundRectM::Draw(CDC *dc)
{
	dc->RoundRect(p1.x, p1.y, p2.x, p2.y, 20, 20);
}
