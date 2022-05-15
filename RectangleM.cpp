#include "stdafx.h"
#include "RectangleM.h"

IMPLEMENT_SERIAL(RectangleM,CObject,1)

RectangleM::RectangleM()
{
}
RectangleM::RectangleM(CPoint p1, CPoint p2) :Figure(p1, p2)
{
}
void RectangleM::Draw(CDC *dc)
{
	dc->Rectangle(p1.x, p1.y, p2.x, p2.y);
}

RectangleM::~RectangleM()
{
}

