#include "stdafx.h"
#include "EllipseM.h"


	IMPLEMENT_SERIAL(EllipseM,CObject,1)

	EllipseM::EllipseM()
	{
	}

	EllipseM::EllipseM(CPoint p1, CPoint p2) : Figure(p1, p2)
	{
	}

	void EllipseM::Draw(CDC *dc)
	{
		dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
	}
