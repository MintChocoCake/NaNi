#include "stdafx.h"
#include "LineMgr.h"

CLineMgr*		CLineMgr::m_pInstance = nullptr;
CLineMgr::CLineMgr()
{
}


CLineMgr::~CLineMgr()
{
}

void CLineMgr::Initialize(void)
{
	MYPOINT	tPoint[6] = { 
		{ 0.f , 550.f },
		{ 100.f, 450.f },
		{ 250.f, 450.f },
		{ 450.f, 250.f },
		{ 600.f, 250.f }, 
		{ 800.f, 100.f }
	};

	


	m_LineList.push_back(new CLine(tPoint[0], tPoint[1]));
	m_LineList.push_back(new CLine(tPoint[1], tPoint[2]));
	m_LineList.push_back(new CLine(tPoint[2], tPoint[3]));
	m_LineList.push_back(new CLine(tPoint[3], tPoint[4]));
	m_LineList.push_back(new CLine(tPoint[4], tPoint[5]));

}

void CLineMgr::Render(HDC _hDC)
{
	for (auto& iter : m_LineList)
		iter->Render(_hDC);
}

void CLineMgr::Release(void)
{
}

bool CLineMgr::Collision_Line(float & _fX, float * _pfY)
{
	if (m_LineList.empty())
		return false;

	CLine*		pTargetLine = nullptr;

	for (auto& iter : m_LineList)
	{
		if (_fX >= iter->Get_Info().tLPoint.fX &&
			_fX <= iter->Get_Info().tRPoint.fX)
			pTargetLine = iter;
	}

	if (nullptr == pTargetLine)
		return false;

	// Y  = ((y2 - y1) / (x2 - x1)) * (X - x1) + y1

	float	x1 = pTargetLine->Get_Info().tLPoint.fX;
	float	y1 = pTargetLine->Get_Info().tLPoint.fY;

	float	x2 = pTargetLine->Get_Info().tRPoint.fX;
	float	y2 = pTargetLine->Get_Info().tRPoint.fY;

	*_pfY = ((y2 - y1) / (x2 - x1)) * (_fX - x1) + y1;

	return true;
}
