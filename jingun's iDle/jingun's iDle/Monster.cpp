#include "stdafx.h"
#include "Monster.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	m_tInfo.m_fX = 600;
	m_tInfo.m_fY = 200;
	m_tInfo.m_fCX = 50;
	m_tInfo.m_fCY = 50;

	m_fSpeed = 10.f;

	m_fDistance = 50.f;

	m_fAngle = 50.f;

}

void CMonster::Update()
{
	Update_Rect();

	//if (CObjMgr::Get_Instance()->m_ObjList[OBJ_PLAYER].front()->Get_Info().m_fY == m_tInfo.m_fY)
		Create_Bullet();
	
	
	
}

void CMonster::Late_Update()
{
	m_tBarrel.x = LONG(m_tInfo.m_fX + m_fDistance * cos(m_fAngle * (3.141592f / 180.f)));
	m_tBarrel.y = LONG(m_tInfo.m_fY - m_fDistance * sin(m_fAngle* (3.141592f / 180.f)));
	
	m_fAngle += 20.f;
}

void CMonster::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	Ellipse(hDC, m_tRect.left + 10.f, m_tRect.top + 10.f, m_tRect.right - 10.f, m_tRect.bottom - 10.f);
	MoveToEx(hDC, m_tInfo.m_fX, m_tInfo.m_fY, nullptr);
	LineTo(hDC, m_tBarrel.x, m_tBarrel.y);
}

void CMonster::Release()
{
}

void CMonster::Create_Bullet()
{
	CObjMgr::Get_Instance()->Add_Obj(OBJ_BULLET, CAbstractFactory<CBullet>::Create(m_tBarrel.x,m_tBarrel.y,m_fAngle));
}