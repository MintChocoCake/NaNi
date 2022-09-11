#pragma once
class CLine
{
public:
	CLine();
	CLine(MYPOINT& tLeft, MYPOINT& tRight);
	~CLine();

public:
	const LINE&  Get_Info()const { return m_tInfo; }

public:
	void Render(HDC hDC);
private:
	LINE m_tInfo;
};

