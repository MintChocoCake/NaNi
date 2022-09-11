#include "stdafx.h"
#include "Obj.h"


CObj::CObj() :m_bDead(false) ,m_fAngle(0.f) ,m_fDistance(0.f)
{
}


CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	m_tRect.left = LONG(m_tInfo.m_fX - m_tInfo.m_fCX / 2);
	m_tRect.right = LONG(m_tInfo.m_fX + m_tInfo.m_fCX / 2);
	m_tRect.top = LONG(m_tInfo.m_fY - m_tInfo.m_fCY / 2);
	m_tRect.bottom = LONG(m_tInfo.m_fY + m_tInfo.m_fCY / 2);
}
