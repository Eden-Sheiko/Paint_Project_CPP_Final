#include "stdafx.h"
#include "PieM.h"

IMPLEMENT_SERIAL(PieM,CObject,1)
PieM::PieM()
{
}

PieM::PieM(CPoint p1, CPoint p2, int x, int y) : EllipseM(p1,p2)
{
}

PieM::~PieM()
{
}


void PieM::Draw(CDC *dc)
{
	dc->Pie(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y, p4.x, p4.y);
}
