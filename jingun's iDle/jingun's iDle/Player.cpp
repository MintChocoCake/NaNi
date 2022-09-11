#include "stdafx.h"
#include "Player.h"
#include "LineMgr.h"

CPlayer::CPlayer()
	: m_bJump(false), m_fPower(0.f), m_fTime(0.f)
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	m_tInfo.m_fCX = 30;
	m_tInfo.m_fCY = 60;
	m_tInfo.m_fX = 400;
	m_tInfo.m_fY = 500;
	m_fSpeed = 5.f;

	m_fPower = 20.f;

	m_fDistance = 50.f;
	
	
}

void CPlayer::Update()
{
	
	Key_Input();
	Jump();
	Update_Rect();

	Create_Bullet();
	m_fAngle += 20.f;
	
}

void CPlayer::Late_Update()
{
	// 포신 각도 조정
	m_tBarrel.x = LONG(m_tInfo.m_fX + m_fDistance * cos(m_fAngle * (3.141592f / 180.f)));
	m_tBarrel.y = LONG(m_tInfo.m_fY - m_fDistance * sin(m_fAngle* (3.141592f / 180.f)));

	
}





void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	// 대가리
	Ellipse(hDC, m_tRect.left-10.f, m_tRect.top -40.f, m_tRect.right + 10.f, m_tRect.bottom - 50.f);
	
	
	// 포신 그리기
	MoveToEx(hDC, m_tInfo.m_fX, m_tInfo.m_fY, nullptr);

	LineTo(hDC, m_tBarrel.x, m_tBarrel.y);


	// 플레이어 좌표 확인용
	Player_Location(hDC);
	
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
	float fY = 0;
	if (GetAsyncKeyState(VK_UP))
		m_tInfo.m_fY -= m_fSpeed;
	if (GetAsyncKeyState(VK_DOWN))
		m_tInfo.m_fY += m_fSpeed;
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.m_fX -= m_fSpeed;
		/*if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.m_fX, &fY))
			m_tInfo.m_fY = fY;*/
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.m_fX += m_fSpeed;
		/*if (CLineMgr::Get_Instance()->Collision_Line(m_tInfo.m_fX, &fY))
			m_tInfo.m_fY = fY;*/
	}
	if (GetAsyncKeyState(VK_SPACE))
	{
		if (!m_bJump)
			m_bJump = true;
	}

	// 포신 움직이기 
	if (GetAsyncKeyState('D'))
	{
		m_fAngle -= 5.f;
	}
	if (GetAsyncKeyState('A'))
	{
		m_fAngle += 5.f;
	}

	if (GetAsyncKeyState('S')) //& 0x0001
	{
		Create_Bullet();
		m_fAngle += 20.f;
	}
}

void CPlayer::Jump()
{
	float	fY = 0;

	bool	bLineCol = CLineMgr::Get_Instance()->Collision_Line(m_tInfo.m_fX, &fY);

	if (m_bJump)
	{
		m_tInfo.m_fY -= m_fPower * m_fTime - (9.8f * m_fTime * m_fTime) * 0.5f;
		m_fTime += 0.2f;

		if (bLineCol && fY < m_tInfo.m_fY)
		{
			m_bJump = false;
			m_fTime = 0.f;
			m_tInfo.m_fY = fY;
		}
	}
	else if (bLineCol)
		m_tInfo.m_fY = fY;
}

void CPlayer::Player_Location(HDC hDC)
{
	TCHAR		szBuff[32] = L"";

	// 플레이어x/y - 점1x/y  
	wsprintf(szBuff, L"PlayerX : %d", (int)m_tInfo.m_fX);
	TextOut(hDC, 50, 100, szBuff, lstrlen(szBuff));
	wsprintf(szBuff, L"PlayerY : %d", (int)m_tInfo.m_fY);
	TextOut(hDC, 50, 150, szBuff, lstrlen(szBuff));
	wsprintf(szBuff, L"PlayerRect.left : %d", m_tRect.left);
	TextOut(hDC, 50, 200, szBuff, lstrlen(szBuff));
	wsprintf(szBuff, L"PlayerRect.top : %d", m_tRect.top);
	TextOut(hDC, 50, 250, szBuff, lstrlen(szBuff));
	wsprintf(szBuff, L"PlayerRect.right : %d", m_tRect.right);
	TextOut(hDC, 50, 300, szBuff, lstrlen(szBuff));
	wsprintf(szBuff, L"PlayerRect.bottom : %d", m_tRect.bottom);
	TextOut(hDC, 50, 350, szBuff, lstrlen(szBuff));
	wsprintf(szBuff, L"BarrelX : %d", m_tBarrel.x);
	TextOut(hDC, 50, 400, szBuff, lstrlen(szBuff));
	wsprintf(szBuff, L"BarrelY : %d", m_tBarrel.y);
	TextOut(hDC, 50, 450, szBuff, lstrlen(szBuff));


	wsprintf(szBuff, L"Bullet : %d", CObjMgr::Get_Instance()->m_ObjList[OBJ_BULLET].size());
	TextOut(hDC, 50, 50, szBuff, lstrlen(szBuff));
}

void CPlayer::Create_Bullet()
{
	CObjMgr::Get_Instance()->Add_Obj(OBJ_BULLET, CAbstractFactory<CBullet>::Create((float)m_tBarrel.x, (float)m_tBarrel.y, m_fAngle));
}