#pragma once
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	virtual void Initialize()=0;
	virtual void Update()=0;
	virtual void Late_Update()=0;
	virtual void Render(HDC hDC)=0;
	virtual void Release() = 0;

public:
void	Update_Rect();

const INFO Get_Info() { return m_tInfo; }
const RECT Get_Rect() { return m_tRect; }
const bool Get_Dead() { return m_bDead; }
const POINT Get_Target() { return m_Target; }

const float Get_Angle() { return m_fAngle; }


void Set_Dead() { m_bDead = true; }

void		Set_Info(INFO _tInfo)
{
	m_tInfo.m_fX = _tInfo.m_fX;
	m_tInfo.m_fY = _tInfo.m_fY;
}

void		Set_Pos(float _fX, float _fY)
{
	m_tInfo.m_fX = _fX;
	m_tInfo.m_fY = _fY;
}

void		Set_Target(float _fX, float _fY)
{
	m_Target.x = _fX;
	m_Target.y = _fY;
}

void		Set_Angle(float _fAngle)
{
	m_fAngle = _fAngle;
}

protected:
	INFO	m_tInfo;
	RECT	m_tRect;

	float	m_fSpeed;

	bool	m_bDead;

	// 포신관련
	POINT	m_tBarrel;

	float	m_fAngle;
	float	m_fDistance;

	POINT	m_Target;

};

