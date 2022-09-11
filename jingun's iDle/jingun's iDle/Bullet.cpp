#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
	
}


CBullet::~CBullet()
{
}

void CBullet::Initialize()
{
	m_tInfo.m_fCX = 10.f;
	m_tInfo.m_fCY = 10.f;

	m_fSpeed = 10.f;
}

void CBullet::Update()
{
	m_tInfo.m_fX += m_fSpeed * cosf(m_fAngle * (3.141592f / 180.f));
	m_tInfo.m_fY -= m_fSpeed * sinf(m_fAngle * (3.141592f / 180.f));

	Update_Rect();
}

void CBullet::Late_Update()
{
	if (0 > m_tRect.left)
		Set_Dead();
	if (WINCY < m_tRect.top)
		Set_Dead();
	if (WINCX < m_tRect.right)
		Set_Dead();
	if (0 > m_tRect.bottom)
		Set_Dead();
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CBullet::Release()
{
}
