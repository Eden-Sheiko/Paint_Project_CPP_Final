
#pragma once
class Figure : public CObject
{
	DECLARE_SERIAL(Figure)
protected:
public:
	CPoint p1;
	CPoint p2;
	CPoint p3;
	CPoint p4;
	Figure();
	void Serialize(CArchive& ar);
	Figure(CPoint p1, CPoint p2) : p1(p1), p2(p2)
	{
	}
	virtual void Draw(CDC *dc);
	virtual ~Figure(void);
};
