// Figure.cpp
#include "stdafx.h"
#include "Figure.h"
	IMPLEMENT_SERIAL(Figure,CObject,1)
Figure::Figure(void)
{
}
Figure::~Figure(void)
{
}
void Figure::Draw(CDC *dc)
{
	dc->Rectangle(p1.x, p1.y,p2.x, p2.y);
}

void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << p1;
		ar << p2;
		
	}
	else
	{
		ar >> p1;
		ar >> p2;
	}
}